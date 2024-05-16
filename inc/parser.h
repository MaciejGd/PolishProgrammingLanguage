#pragma once
#include "lex.h"
#include <memory>
#include "parsing_table.h"

using std::unique_ptr;

TYPE stringToType(string key);
void loadTokenList(vector<Token>& tokens);

int getElement(vector<vector<int>>& prod);



class Node {
	Token token;
public:
	Node(Token _token);
	void printNode() const;
};

