#include "lex.h"
#include <memory>
#include <unordered_map>
#include "parsing_table.h"
#include "parser.h"

enum Symbol {
	ERROR,
	EPSILON,
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
	DIVIDE
};

extern std::unordered_map<std::string, Symbol> terminals;

Symbol translateTokenToSymbol(const Token& token);

struct Production 
{
	Symbol lhs;
	vector<Symbol> rhs;
};

//grammar as vector
extern vector<Production> grammar;

