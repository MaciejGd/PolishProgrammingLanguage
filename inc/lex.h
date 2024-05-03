#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <unistd.h>

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

int isConstant(string lexem);
void createToken(const vector<string>& lexemes, vector<Token>& tokens);
void divideToWords(int line_counter, string line, vector<string> &words);
void loadTokensToFile(const vector<Token>& tokens);
vector<Token> tokensScan(string file_name);

