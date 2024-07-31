#pragma once
#include <stack>

#include "lex.h"
//#include "production.h"
#include "grammar.h"

int analyze_identifier(Symbol previous, Symbol id);
int rec_parse(Symbol* head, const std::vector<Token>& tokens, int &counter);
Symbol* parse(const vector<Token>& tokens);
//int parse(const vector<Token>& tokens);
