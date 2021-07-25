import os
import getpass
from datetime import date
import xml.etree.ElementTree as ET

script_dir = os.path.dirname(os.path.realpath(__file__))

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

keywords_dir = os.path.join(os.path.join(os.path.join(script_dir, 'resources')), 'keywords')

key_words = dict()

for f in os.listdir(keywords_dir):
    if not f.endswith('.xml'):
        continue
    tree = ET.parse(os.path.join(keywords_dir, f))
    key_words[f] = []
    for elem in tree.iter():
        if 'key' in elem.keys():
            key_words[f].append((elem.attrib['key'], elem.attrib['value']))

keys = [x[0] for x in key_words['keywords_eng.xml']]

keys_hpp = 'namespace batya_script::resources::keywords {\n\n'
keys_hpp += 'enum class Key {\n'
for key in keys:
    keys_hpp += '    ' + key.capitalize()
    if key != keys[-1]:
        keys_hpp += ',\n'
keys_hpp += '\n};\n'
keys_hpp += '\n}'
create_header_file(os.path.join(os.path.join('resources', 'keywords'), 'keys'), keys_hpp)
hpp = '#include <array>\n\n'
hpp += '#include "keys.hpp"\n'
hpp += 'namespace batya_script::resources::keywords {\n\n'
hpp += 'enum class Locale {\n'

locales = []

i = 0
for key, values in key_words.items():
    locales.append(key.replace('.xml', '').split('_')[-1].capitalize())
    hpp += '    ' + locales[-1]
    if i != len(key_words) - 1:
        hpp += ',\n'
    i += 1

hpp += '\n};\n\n'

hpp += f'constexpr std::array<std::array<const char*, {len(keys)}>, {len(locales)}> words = {{\n'

i = 0
for key, values in key_words.items():
    hpp += f'std::array<const char*, {len(keys)}> {{\n'
    for value in values:
        hpp += '    "' + value[1] + '"'
        if value != values[-1]:
            hpp += ',\n'
    hpp += '\n}'
    if i != len(key_words) - 1:
        hpp += ',\n'
    i += 1

hpp += '\n};\n\n'

hpp += '[[nodiscard]] bool equals(const std::string& str, Key key) noexcept(true);\n'

hpp += '\n}\n'    
cpp = 'using namespace batya_script::resources::keywords;\n\n'
cpp += 'bool batya_script::resources::keywords::equals(const std::string& str, Key key) noexcept(true) {\n'
cpp += f'   for(size_t i = 0; i < {len(locales)}; ++i)\n'
cpp += '        if(words[i][(int)key] == str)\n'
cpp += '            return true;\n'
cpp += '    return false;\n'
cpp += '}'

create_header_and_cpp_file(os.path.join(os.path.join('resources', 'keywords'), "keywords"), hpp, cpp)