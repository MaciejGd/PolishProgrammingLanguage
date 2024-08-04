#pragma once
#include <unordered_map>
#include <vector>
#include <string>

//#include "lex.h"

//values of enum in order in which it is placed in parsing table, changing places strictly forbidden
namespace Prod{
enum Symbol {
	INCLUDE,
	GLOBAL,
	GLOBALVAR,
	START,
	FUNCTION,
	VARDECL,
	DATATYPE,
	FUNCTIONDECLARATION,
	PARAMLIST,
	PARAMDECLS,
	PARAMDECLSNEW,
	FUNCTYPE,
	BODY,
	STATEMENTS,
	STATEMENT,
	VARINIT,
	FORRANGE,
	FORRANGENEW,
	ARGLIST,
	FUNCARGS,
	FUNCARGSNEW,
	ELSECLAUSE,
	ELSE,
	CONDITION,
	CONDITIONNEW,
	LOGOP,
	ADDOP,
	MULOP,
	EXPRESSION,
	EXPRESSIONNEW,
	TERM,
	TERMNEW,
	FACTOR,
	EPSILON,
	ZAKRES,
	DYCHA,
	PRZECINEK,
	TEKST,
	NIC,
	FUNKCJA,
	IDENTIFIER,
	CONSTANT ,
	OPENING_ROUND,
	CLOSING_ROUND,
	COMA,
	COLON,
	SEMICOLON,
	OPENING_CURLY,
	CLOSING_CURLY,
	OPENING_SQUARE,
	CLOSING_SQUARE,
	PRZESTAN,
	DALEJ ,
	ZWROC,
	WYWOLAJ,
	DOPOKI,
	DLA,
	JESLI,
	ASSIGN,
	INACZEJ,
	DOUBLE_EQUAL,
	NOT_EQUAL,
	MORE,
	LESS,
	MORE_EQUAL,
	LESS_EQUAL,
	AND_OP,
	OR_OP,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	END,
	ERROR,
	// EPSILON,
	GLOBALNE,
	DODAJ
};

struct Production 
{
	Symbol lhs;
	std::vector<Symbol> rhs;
};

//symbols map for debugging
extern std::unordered_map<Symbol, std::string> symbols_map;
extern std::unordered_map<std::string, Symbol> terminals_map;
extern std::vector<std::string> terminals;
//grammar as vector
extern std::vector<Production> grammar;
extern std::vector<std::vector<int>> parsing_table;
}

//needed by lexer
extern std::vector<char> operators;
extern std::vector<char> separators;
extern std::vector<std::string> keywords;

//needed by trabnspiler
extern std::unordered_map<std::string, std::string> keyword_map;



