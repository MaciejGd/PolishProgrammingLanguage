#pragma once
#include <stack>
#include <sstream>
#include "lex.h"

#include "grammar.h"


int rec_parse(Symbol* head, const std::vector<Token>& tokens, int &counter);
Symbol* parse(const vector<Token>& tokens);
//debug purposes -> to show ast in a file
void printRec(std::ostringstream& ss, Symbol* head, int incantation);
void printAST( const char* file_arg, Symbol* head);
//removal of dynamically allocated AST nodes
void chopTree(Symbol *head);
