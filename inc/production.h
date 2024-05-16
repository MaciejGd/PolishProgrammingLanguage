#include "lex.h"
#include <memory>
#include "parsing_table.h"
#include "parser.h"

enum Symbol {
	VarDecl,
	DataType,
	FunctionDeclaration,
	ParamList,
	ParamDecls,
	ParamDeclsNew,
	FuncType,
	Body,
	Statements,
	Statement,
	VarInit,
	ForRange,
	ForRangeNew,
	ArgList,
	FuncArgs,
	FuncArgsNew,
	ElseClause,
	Else,
	Condition,
	ConditionNew,
	LogOp,
	AddOp,
	MulOp,
	Expression,
	ExpressionNew,
	Term,
	TermNew,
	Factor,
	dycha,
	przecinek,
	tekst,
	nic,
	funkcja,
	identifier,
	constant ,
	opening_round,
	closing_round,
	coma,
	colon,
	semicolon,
	opening_curly,
	closing_curly,
	przestan,
	dalej ,
	zwroc,
	wywolaj,
	dopoki,
	dla,
	jesli,
	assign,
	inaczej,
	double_equal,
	not_equal,
	more,
	less,
	more_equal,
	less_equal,
	and_op,
	or_op,
	plus,
	minus,
	multiply,
	divide
};

struct Production 
{
	Symbol lhs;
	vector<Symbol> rhs;
};

//grammar as vector
vector<Production> grammar = {
	{VarDecl, {DataType, identifier}},
	{}



};








