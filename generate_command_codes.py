import os
import getpass
from datetime import date

script_dir = os.path.dirname(os.path.realpath(__file__))
commands_path = os.path.join(script_dir, 'commands')

lines = []
with open(commands_path) as file:
    lines = list(filter(lambda x: len(x) != 0, file.read().split('\n')))

class Command:
    def __init__(self, name, args):
        self.name = name
        self.args = args

def parse_command(line):
    tokens = [x.strip() for x in list(filter(lambda x: len(x) != 0, line.replace('(', '#').replace(')', '#').replace(',', '#').split('#')))]
    
    name = tokens[0]
    args = []
    for token in tokens[1:]:
        arg_tokens = token.split(' ')
        args.append((' '.join(arg_tokens[:-1]), arg_tokens[-1]))
    
    return Command(name, args)
    
    
def create_header_file(path, text):
    with open(os.path.join(script_dir, path) + '.hpp', 'w') as f:
        f.write('//\n')
        f.write(f'// Created by {getpass.getuser()} on {date.today().strftime("%d.%m.%Y.")}\n')
        f.write('//\n\n')
        dirs = path.split(os.sep)
        guard_tag = (script_dir.split(os.sep)[-1] + '_' + '_'.join([x.replace(' ', '_').replace('.', '_') for x in dirs]) + '_HPP_').upper()
        f.write(f'#ifndef {guard_tag}\n')
        f.write(f'#define {guard_tag}\n\n')
        f.write(text)
        f.write(f'\n\n#endif //{guard_tag}')

def create_header_and_cpp_file(path, hpp_text, cpp_text):
    create_header_file  (path, hpp_text)
    with open(os.path.join(script_dir, path) + '.cpp', 'w') as f:
        f.write(f'#include "{path.split(os.sep)[-1]}.hpp"\n\n')
        f.write(cpp_text)

commands = [parse_command(line) for line in lines]

# bytecode/codes.hpp generation

command_codes = '#include <array>\n\n'

command_codes += 'namespace batya_script::bytecode::codes {\n\n'

i = 0
for command in commands:
    command_codes += f'constexpr inline unsigned char {command.name} = {i};\n\n'
    i += 1

command_codes += f'constexpr std::array<unsigned char, {len(commands)}> size_of {{\n'

for command in commands:
    size = ' + '.join([f'sizeof({x[0]})' for x in command.args])
    if len(size) == 0:
        size = '0'
    command_codes += f'/*{command.name}*/ ' + size
    if command != commands[-1]:
        command_codes += ',\n'

command_codes += '\n};\n\n'

command_codes += f'constexpr std::array<const char*, {len(commands)}> spelling_of {{\n'

for command in commands:
    command_codes += f'/*{command.name}*/ "{command.name}"'
    if command != commands[-1]:
        command_codes += ',\n'

command_codes += '\n};\n\n'

command_codes += '}'

create_header_file('bytecode/codes', command_codes)

# bytecode/bytecode_builder generation

builder_cpp = '#include <cstring>\n'
builder_cpp += '#include "codes.hpp"\n\n'
builder_cpp += 'using namespace batya_script::bytecode;\n\n'
builder_hpp = '#include <vector>\n\n'
builder_hpp += 'namespace batya_script::bytecode {\n'
builder_hpp += '\nusing Bytecode = std::vector<unsigned char>;\n\n'
builder_hpp += 'class BytecodeBuilder {\n'
builder_hpp += 'public:\n\n'
builder_hpp += '    BytecodeBuilder() noexcept(true);\n\n'
builder_hpp += '    [[nodiscard]] size_t position() const noexcept(true);\n\n'
builder_hpp += '    [[nodiscard]] Bytecode build() noexcept(true);\n\n'

builder_cpp += 'BytecodeBuilder::BytecodeBuilder() noexcept(true)\n    : _bytecode({}), _position(0) {}\n\n\n'

builder_cpp += 'size_t BytecodeBuilder::position() const noexcept(true) {\n'
builder_cpp += '    return _position;'
builder_cpp += '\n}\n\n\n'

builder_cpp += 'Bytecode BytecodeBuilder::build() noexcept(true) {\n'
builder_cpp += '    auto result = Bytecode(std::move(_bytecode));\n'
builder_cpp += '    _bytecode = {};\n'
builder_cpp += '    _position = 0;\n'
builder_cpp += '    return result;\n'
builder_cpp += '\n}\n\n\n'

for command in commands:
    args_signature = '(' + ', '.join([x[0] + ' ' + x[1] for x in command.args]) + ')'
    builder_hpp += '    void ' + command.name + args_signature + 'noexcept(true); \n\n'
    builder_cpp += f'void BytecodeBuilder::{command.name}{args_signature} noexcept(true) {{\n'
    builder_cpp += '    ++_position;\n'
    builder_cpp += f'    _bytecode.emplace_back(codes::{command.name});\n'
    builder_cpp += f'    for(size_t i = 0; i < codes::size_of[codes::{command.name}]; ++i)\n'
    builder_cpp += '        _bytecode.emplace_back();\n'
    for arg in command.args:
        builder_cpp += f'    memcpy(_bytecode.data() + _position, &{arg[1]}, sizeof({arg[0]}));\n'
        builder_cpp += f'   _position += sizeof({arg[0]});\n'
    builder_cpp += '}\n\n\n'

builder_hpp += 'private:\n\n'
builder_hpp += '    Bytecode _bytecode;\n\n'
builder_hpp += '    size_t _position;\n\n'
builder_hpp += '};\n\n'
builder_hpp += '}'
builder_cpp = builder_cpp[:-3]
create_header_and_cpp_file('bytecode/bytecode_builder', builder_hpp, builder_cpp)
