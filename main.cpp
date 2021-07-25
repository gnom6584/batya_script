#include <iostream>
#include <cstring>
#include <stack>
#include <map>

#include "bytecode/bytecode_builder.hpp"
#include "bytecode/interpreter.hpp"
#include "bytecode/codes.hpp"

#include "string_utility.hpp"

#include <list>
#include <utility>
#include <sstream>

class Tree {
public:
	virtual ~Tree() {

	}
};

class Op : public Tree {
public:

	Op(std::string sign, Tree* left, Tree* right) : right(right), left(left), sign(std::move(sign))  {


	}
	std::string sign;

	Tree* left;
	Tree* right;
};

class Val : public Tree {
public:
	explicit Val(std::string  value) : value(std::move(value)) {}

	std::string value;
};

class Node {
public:
	virtual ~Node() = default;
	virtual Tree* evaluate() = 0;
};

struct String : public Node {
	explicit String(std::string value) : value(std::move(value)) {}

	Tree* evaluate() override {
		return new Val(value);
	}

	std::string value;
};

struct Operator : public Node {
	explicit Operator(std::string sign) : sign(std::move(sign)) {}

	Tree* evaluate() override {
		return nullptr;
	}

	std::string sign;
};

struct TreeNode : public Node {
	explicit TreeNode(Tree* tree) : tree(tree) {}

	Tree* evaluate() override {
		return tree;
	}

	Tree* tree;
};

std::vector<std::vector<std::string>> operators = {
	{"*", "/", "%"},
	{"+", "-"},
	{"<", ">", "<=", "=>"},
	{"=="},
};



struct Block : public Node {
	std::list<Node*> children;

	Tree* evaluate() override {
		for (auto & i : operators) {
			auto header = std::begin(children);
			while(header != std::end(children)) {
				auto as_operator = dynamic_cast<Operator*>(*header);
				if(as_operator && std::count(std::begin(i), std::end(i), as_operator->sign)) {
					auto left = std::prev(header);
					auto right = std::next(header);
					auto new_value = new Op(as_operator->sign, (*left)->evaluate(),  (*right)->evaluate());

					delete *header;
					delete *left;
					delete *right;
					header = children.erase(left);
					header = children.erase(header);
					header = children.erase(header);

					header = children.insert(header, new TreeNode((new_value)));
				}
				else
					++header;
			}
		}
		return children.front()->evaluate();
	}

	[[nodiscard]] std::string print() const {
		std::stringstream ss;
		for(auto& it : children) {
			if(dynamic_cast<String*>(it))
				ss << dynamic_cast<String*>(it)->value << ' ';
			if(dynamic_cast<Operator*>(it))
				ss << dynamic_cast<Operator*>(it)->sign << ' ';
			if(dynamic_cast<Block*>(it)) {
				ss << "(" << dynamic_cast<Block*>(it)->print() << ")";
			}
		}
		return ss.str();
	}

	~Block() override {
		for(auto child : children)
			delete child;
	}
};

Block* parse_block(const std::vector<std::string>& tokens, size_t begin, size_t end) {
	auto block = new Block();
	for (int i = begin; i < end; ++i) {
		if(tokens[i] == "(") {
			++i;
			auto start = i;
			int depth = 0;
			bool thr = true;
			while(i != end) {
				if(tokens[i] == "(")
					++depth;
				else if(tokens[i] == ")") {
					if(depth == 0) {
						block->children.emplace_back(parse_block(tokens, start, i));
						thr = false;
						break;
					}
					--depth;
				}
				++i;
			}
			if(thr)
				throw std::runtime_error("Unclosed brackets!");
		}
		else if(std::count(std::begin(operators[0]), std::end(operators[0]), tokens[i])) {
			block->children.emplace_back(new Operator {tokens[i]});
		}
		else if(std::count(std::begin(operators[1]), std::end(operators[1]), tokens[i])) {
			block->children.emplace_back(new Operator {tokens[i]});
		}
		else if(std::count(std::begin(operators[2]), std::end(operators[2]), tokens[i])) {
			block->children.emplace_back(new Operator {tokens[i]});
		}
		else if(std::count(std::begin(operators[3]), std::end(operators[3]), tokens[i])) {
			block->children.emplace_back(new Operator {tokens[i]});
		}
		else {
			block->children.emplace_back(new String(tokens[i]));
		}
	}
	return block;
}

Block* parse_expr(const std::string& str) {
	std::set<std::string> seprs;
	for(auto& _ : operators)
		for(auto& it : _)
			seprs.emplace(it);

	seprs.emplace("(");
	seprs.emplace(")");

	auto tokens = StringUtility::split_keep_by_strings(str, seprs);
	for(auto& token : tokens)
		token = StringUtility::strip(token);

	tokens.erase(std::remove_if(std::begin(tokens), std::end(tokens), [](auto& it){
		return it.length() == 0;
	}), std::end(tokens));

	return parse_block(tokens, 0, std::size(tokens));
}

void dump(Tree* tree, int d = 0) {
	std::cout << std::string(d, '\t') << typeid(*tree).name() << std::endl;
	if(dynamic_cast<Op*>(tree)) {
		dump(dynamic_cast<Op*>(tree)->left, d + 1);
		std::cout << std::string(d, '\t') << dynamic_cast<Op*>(tree)->sign << std::endl;
		dump(dynamic_cast<Op*>(tree)->right, d + 1);
	}
}

using namespace batya_script::bytecode;

enum class Literal: int {
	Bool,
	Int1,
	Uint1,
	Int2,
	Uint2,
	Int4,
	Uint4,
	Int8,
	Uint8,
	Float4,
	Float8
};

std::map<Literal, size_t> lit_s = {
	{Literal::Bool, 1},
	{Literal::Int1, 1},
	{Literal::Uint1, 1},
	{Literal::Int2, 2},
	{Literal::Uint2, 2},
	{Literal::Int4, 4},
	{Literal::Uint4, 4},
	{Literal::Int8, 8},
	{Literal::Uint8, 8},
	{Literal::Float4, 4},
	{Literal::Float8, 8},


};

Literal check_literal(const std::string& str) {
	std::cout << str << std::endl;
#define ex_rng(t, b, e) "Invalid " + std::string(t) + " value, valid value range is [" + std::to_string(b) + ", " + std::to_string(e) + "]"
	if(str.ends_with("i1")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stol(copy);
		;
		if(c < -128 || c > 127)
			throw std::runtime_error(ex_rng("Int1", -128, 127) + str);
		return Literal::Int1;
	}
	if(str.ends_with("u1")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stol(copy);
		if(c < 0 || c > 255)
			throw std::runtime_error(ex_rng("Uint1", 0, 255) + str);
		return Literal::Uint1;
	}
	if(str.ends_with("i2")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stol(copy);

		if(c < INT16_MIN || c > INT16_MAX)
			throw std::runtime_error(ex_rng("Int2", INT16_MIN, INT16_MAX) + str);

		return Literal::Int2;
	}
	if(str.ends_with("u2")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stol(copy);

		if(c < 0 || c > UINT16_MAX)
			throw std::runtime_error(ex_rng("Uint2", 0, UINT16_MAX) + str);
		return Literal::Uint2;
	}
	if(str.ends_with("i4")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stol(copy);

		if(c < INT32_MIN || c > INT32_MAX)
			throw std::runtime_error(ex_rng("Int4", INT32_MIN, INT32_MAX) + str);
		return Literal::Int4;
	}
	if(str.ends_with("u4")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stol(copy);

		if(c < 0 || c > UINT32_MAX)
			throw std::runtime_error(ex_rng("Uint4", 0, UINT32_MAX) + str);
		return Literal::Uint4;
	}
	if(str.ends_with("i8")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stoll(copy);
		return Literal::Int8;
	}
	if(str.ends_with("u8")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stoull(copy);
		return Literal::Uint8;
	}
	if(str.ends_with("f4")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stof(copy);
		return Literal::Float4;
	}
	if(str.ends_with("f8")) {
		std::string copy(std::begin(str), std::end(str) - 2);
		auto c = std::stod(copy);
		return Literal::Float8;
	}
	if(!std::isdigit(str.back())) {
		throw std::invalid_argument("Invalid literal");
	}
	if(str == "true" || str == "false")
		return Literal::Bool;
	try {
		stoi(str);
		return Literal::Int4;
	}
	catch (...) {
		try {
			stof(str);
			return Literal::Float4;
		}
		catch (...) {
		}
	}
	throw std::invalid_argument("Invalid literal");
}

#define WTF_MACRO(x)\
switch (left_literal) { \
case Literal::Bool:\
throw std::runtime_error("bool op");\
break;\
case Literal::Int1:\
b. x ## _integer_8(pos, pos + lits);\
break;\
case Literal::Uint1:\
b. x ## _unsigned_integer_8(pos, pos + lits);\
break;\
case Literal::Int2:\
b. x ## _integer_16(pos, pos + lits);\
break;\
case Literal::Uint2:\
b. x ## _unsigned_integer_16(pos, pos + lits);\
break;\
case Literal::Int4:\
b. x ## _integer_32(pos, pos + lits);\
break;\
case Literal::Uint4:\
b. x ## _unsigned_integer_32(pos, pos + lits);\
break;\
case Literal::Int8:\
b. x ## _integer_64(pos, pos + lits);\
break;\
case Literal::Uint8:\
b. x ## _unsigned_integer_64(pos, pos + lits);\
break;\
case Literal::Float4:\
b. x ## _float_32(pos, pos + lits);\
break;\
case Literal::Float8:\
b. x ## _float_64(pos, pos + lits);\
break;\
}\

#define WTF_TER(x)\
switch (left_literal) { \
case Literal::Bool:\
throw std::runtime_error("bool op");\
break;\
case Literal::Int1:\
b. x ## _integer_8(pos, pos + lits, pos);\
break;\
case Literal::Uint1:\
b. x ## _unsigned_integer_8(pos, pos + lits, pos);\
break;\
case Literal::Int2:\
b. x ## _integer_16(pos, pos + lits, pos);\
break;\
case Literal::Uint2:\
b. x ## _unsigned_integer_16(pos, pos + lits, pos);\
break;\
case Literal::Int4:\
b. x ## _integer_32(pos, pos + lits, pos);\
break;\
case Literal::Uint4:\
b. x ## _unsigned_integer_32(pos, pos + lits, pos);\
break;\
case Literal::Int8:\
b. x ## _integer_64(pos, pos + lits, pos);\
break;\
case Literal::Uint8:\
b. x ## _unsigned_integer_64(pos, pos + lits, pos);\
break;\
case Literal::Float4:\
b. x ## _float_32(pos, pos + lits, pos);\
break;\
case Literal::Float8:\
b. x ## _float_64(pos, pos + lits, pos);\
break;\
}\


Literal to_bytecode(BytecodeBuilder& b, Tree* t, size_t pos) {
	if(auto op = dynamic_cast<Op*>(t)) {
		auto left_literal = to_bytecode(b, op->left, pos);
		auto lits = lit_s[left_literal];
		auto right_literal = to_bytecode(b, op->right, pos + lits);
		if(left_literal != right_literal)
			throw std::runtime_error("invalid types between operator");
		if(op->sign == "==") {
			switch (left_literal) {
            	case Literal::Bool:
					b.equal_8(pos, pos + lits, pos);
					break;
				case Literal::Int1:
					b.equal_8(pos, pos + lits, pos);
					break;
				case Literal::Uint1:
					b.equal_8(pos, pos + lits, pos);
					break;
				case Literal::Int2:
					b.equal_16(pos, pos + lits, pos);
					break;
				case Literal::Uint2:
					b.equal_16(pos, pos + lits, pos);
					break;
				case Literal::Int4:
					b.equal_32(pos, pos + lits, pos);
					break;
				case Literal::Uint4:
					b.equal_32(pos, pos + lits, pos);
					break;
				case Literal::Int8:
					b.equal_64(pos, pos + lits, pos);
					break;
				case Literal::Uint8:
					b.equal_64(pos, pos + lits, pos);
					break;
				case Literal::Float4:
					b.equal_32(pos, pos + lits, pos);
					break;
				case Literal::Float8:
					b.equal_64(pos, pos + lits, pos);
					break;
			}
			return Literal::Bool;
		}
		if(op->sign == "+")
			WTF_MACRO(add)
		if(op->sign == "-")
			WTF_MACRO(subtract)
		else if (op->sign == "/")
			WTF_MACRO(divide)
		else if (op->sign == "*")
			WTF_MACRO(multiply)
		else if (op->sign == "%")
			WTF_MACRO(modulus)
		else if(op->sign == "<") {
			WTF_TER(less)
			return Literal::Bool;
		}
		return left_literal;
	}
	else if (auto v = dynamic_cast<Val*>(t)) {
		auto lit = check_literal(v->value);
		switch (lit) {

			case Literal::Bool:
				b.set_boolean(pos, v->value == "true");
				break;
			case Literal::Int1:
				b.set_integer_8(pos, (char)std::stoi(v->value));
				break;
			case Literal::Uint1:
				b.set_unsigned_integer_8(pos, (unsigned char)std::stoi(v->value));
				break;
			case Literal::Int2:
				b.set_integer_16(pos, (short)std::stoi(v->value));
				break;
			case Literal::Uint2:
				b.set_unsigned_integer_16(pos, std::stoi(v->value));
				break;
			case Literal::Int4:
				b.set_integer_32(pos, std::stoi(v->value));
				break;
			case Literal::Uint4:
				b.set_unsigned_integer_32(pos, std::stoi(v->value));
				break;
			case Literal::Int8:
				b.set_integer_64(pos, std::stoll(v->value));
				break;
			case Literal::Uint8:
				b.set_unsigned_integer_64(pos, std::stoull(v->value));
				break;
			case Literal::Float4:
				b.set_float_32(pos, std::stof(v->value));
				break;
			case Literal::Float8:
				b.set_float_64(pos, std::stod(v->value));
				break;
		}
		//
		std::cout << (int)lit << std::endl;
		return lit;
	}
}

Bytecode compile(const std::string& str) {
	auto tokens = StringUtility::split_keep_by_strings(str, {"=", "var", "if", "while", "{", "}", "\n"});
	BytecodeBuilder builder;
	std::map<std::string, std::pair<Literal, size_t>> decls;
	for(auto& token : tokens) {
		token = StringUtility::strip(token);
	}
	int p = 0;
	for (int i = 0; i < std::size(tokens); ++i) {

	}
	return builder.build();
}
#include "resources/keywords/keywords.hpp"
#include "resources/keywords/keys.hpp"

#include "ast/parser/parser.hpp"
#include <fstream>
int main() {

	using namespace batya_script::ast;
	using namespace batya_script::utility;
	std::ifstream f("/mnt/c/Users/Name/CLionProjects/batya_script/test");

	std::stringstream ss;
	ss << f.rdbuf();

	SinglePointer<Expression> c = parser::parse(ss.str());

	return 0;
}
