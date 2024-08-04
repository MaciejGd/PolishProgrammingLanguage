#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "production.h"

using std::string, std::vector, std::cout, std::cin;

enum TYPE {
	Op,
	Sep,
	Id,
	Str,
	Int,
	Float,
	Bool,
	Key,
	Lit
};

string typeToString(TYPE type);

struct Token {
	TYPE type;
	string value;
	Token (TYPE _type, string val);
	void printToken() const;
};


class Lexer {
	vector<Token> tokens;
	string file_name;

	void m_tokensScan();
	void m_divideToWords(int line_counter, const string& line, vector<string>& words);
	void m_createTokens(const vector<string>& lexemes);
	int m_isConstant(const string& lexem);
public:
	Lexer(std::string _file);
	const vector<Token> getTokens() const { return tokens; };
};

//implemented in the code, need to move to production
template<typename T>
bool vector_search(const vector<T>& compare_set, T lexeme)
{
	return (find(compare_set.begin(), compare_set.end(), lexeme)!=compare_set.end());
}
