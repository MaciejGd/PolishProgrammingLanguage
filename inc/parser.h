#pragma once
#include <stack>
#include <sstream>
#include "lex.h"

#include "grammar.h"


int analyze_identifier(Symbol previous, Symbol id);
int rec_parse(Symbol* head, const std::vector<Token>& tokens, int &counter);
Symbol* parse(const vector<Token>& tokens);
//debug purposes -> to show ast in a file
void printAST( const char* file_arg, Symbol* head);
//removal of dynamically allocated AST nodes
void chopTree(Symbol *head);
//int parse(const vector<Token>& tokens);
