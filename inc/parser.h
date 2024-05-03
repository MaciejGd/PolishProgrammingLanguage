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
	virtual Node* eval() = 0;	
	void printNode() const;
};

class Add : public Node {
	unique_ptr<Node> left;
	unique_ptr<Node> right;
public:
	Add(Token _token, Node* _left, Node* _right);
	Node* eval() override;
};

class Sub : public Node {
	unique_ptr<Node> left;
	unique_ptr<Node> right;
public:
	Sub(Token _token, Node* _left, Node* _right);
	Node* eval() override;
};
