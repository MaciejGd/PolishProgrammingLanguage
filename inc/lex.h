#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

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

int isConstant(const string& lexem);

template<typename T>
bool vector_search(const vector<T>& compare_set, T lexeme)
{
	return (find(compare_set.begin(), compare_set.end(), lexeme)!=compare_set.end());
}

void createToken(const vector<string>& lexemes, vector<Token>& tokens);
void divideToWords(int line_counter, const string& line, vector<string> &words);
vector<Token> tokensScan(const string& file_name);

