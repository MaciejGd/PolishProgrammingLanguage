#pragma once
#include <stack>

#include "lex.h"
#include "production.h"

//two functions for loading tokens from file
TYPE stringToType(string key);

int getElement(vector<vector<int>>& prod);

void parse(vector<Token>& tokens);
void error(string message, int line_num);

