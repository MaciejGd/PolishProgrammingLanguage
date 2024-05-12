#pragma once
#include "lex.h"
#include <memory>

using std::unique_ptr;

TYPE stringToType(string key);
void loadTokenList(vector<Token>& tokens);

class Node {
	Token token;
public:
	Node(Token _token);
	void printNode() const;
};

