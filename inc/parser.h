#pragma once
#include "lex.h"
#include "parsing_table.h"
#include "production.h"
#include <stack>
#include <memory>

using std::unique_ptr;

//two functions for loading tokens from file
TYPE stringToType(string key);
void loadTokenList(vector<Token>& tokens);

int getElement(vector<vector<int>>& prod);

void parse(vector<Token>& tokens);
void error(string message, int line_num);

