#pragma once
#include <stack>

#include "lex.h"
#include "production.h"
#include "transpiler.h"

int analyze_identifier(Symbol previous, Symbol id);
int parse(const vector<Token>& tokens);
