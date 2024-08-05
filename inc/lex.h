#ifndef LEXER
#define LEXER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "production.h"


//token types
enum TYPE {Op, Sep, Id, Str, Int, Float, Bool, Key, Lit};
//for debug purposes
std::string typeToString(TYPE type);

struct Token {
	TYPE type;
	std::string value;
	Token (TYPE _type, std::string val);
	void printToken() const;
};

class Lexer {
	std::vector<Token> tokens;
	std::string file_name;

	void m_tokensScan();
	void m_divideToWords(int line_counter, const std::string& line, std::vector<std::string>& words);
	void m_createTokens(const std::vector<std::string>& lexemes);
	int m_isConstant(const std::string& lexem);
public:
	Lexer(std::string _file);
	const std::vector<Token> getTokens() const { return tokens; };
};

#endif