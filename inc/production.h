#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>
#include <algorithm>

//macros for colour logging on linux systems
#ifdef __linux__
#define ERROR_LOG "\033[1;31m[ERROR]\033[0m"
#define INFO_LOG "\033[1;32m[INFO]\033[0m"
#elif
#define ERROR_LOG "[ERROR]"
#define INFO_LOG "[INFO]"
#endif


template<typename T>
bool search(const std::vector<T>& compare_set, T lexeme)
{
	return (std::find(compare_set.begin(), compare_set.end(), lexeme)!=compare_set.end());
}
//#include "lex.h"

//values of enum in order in which it is placed in parsing table, changing places strictly forbidden
// namespace Prod{
// enum Symbol {
// 	INCLUDE,
// 	GLOBAL,
// 	GLOBALVAR,
// 	START,
// 	FUNCTION,
// 	VARDECL,
// 	DATATYPE,
// 	FUNCTIONDECLARATION,
// 	PARAMLIST,
// 	PARAMDECLS,
// 	PARAMDECLSNEW,
// 	FUNCTYPE,
// 	BODY,
// 	STATEMENTS,
// 	STATEMENT,
// 	VARINIT,
// 	FORRANGE,
// 	FORRANGENEW,
// 	ARGLIST,
// 	FUNCARGS,
// 	FUNCARGSNEW,
// 	ELSECLAUSE,
// 	ELSE,
// 	CONDITION,
// 	CONDITIONNEW,
// 	LOGOP,
// 	ADDOP,
// 	MULOP,
// 	EXPRESSION,
// 	EXPRESSIONNEW,
// 	TERM,
// 	TERMNEW,
// 	FACTOR,
// 	EPSILON,
// 	ZAKRES,
// 	DYCHA,
// 	PRZECINEK,
// 	TEKST,
// 	NIC,
// 	FUNKCJA,
// 	IDENTIFIER,
// 	CONSTANT ,
// 	OPENING_ROUND,
// 	CLOSING_ROUND,
// 	COMA,
// 	COLON,
// 	SEMICOLON,
// 	OPENING_CURLY,
// 	CLOSING_CURLY,
// 	OPENING_SQUARE,
// 	CLOSING_SQUARE,
// 	PRZESTAN,
// 	DALEJ ,
// 	ZWROC,
// 	WYWOLAJ,
// 	DOPOKI,
// 	DLA,
// 	JESLI,
// 	ASSIGN,
// 	INACZEJ,
// 	DOUBLE_EQUAL,
// 	NOT_EQUAL,
// 	MORE,
// 	LESS,
// 	MORE_EQUAL,
// 	LESS_EQUAL,
// 	AND_OP,
// 	OR_OP,
// 	PLUS,
// 	MINUS,
// 	MULTIPLY,
// 	DIVIDE,
// 	END,
// 	ERROR,
// 	// EPSILON,
// 	GLOBALNE,
// 	DODAJ
// };

// struct Production 
// {
// 	Symbol lhs;
// 	std::vector<Symbol> rhs;
// };

// //symbols map for debugging
// extern std::unordered_map<Symbol, std::string> symbols_map;
// extern std::unordered_map<std::string, Symbol> terminals_map;
// extern std::vector<std::string> terminals;
// //grammar as vector
// extern std::vector<Production> grammar;
// extern std::vector<std::vector<int>> parsing_table;
// }

//needed by lexer
extern std::vector<char> operators;
extern std::vector<char> separators;
extern std::vector<std::string> keywords;

//needed by trabnspiler
extern std::unordered_map<std::string, std::string> keyword_map;



