#include "../inc/production.h"

//used for debugging purposes
std::unordered_map<Symbol, string> symbols_map = {
	{INCLUDE, "INCLUDE"},
	{GLOBAL, "GLOBAL"},
	{GLOBALVAR, "GLOBALVAR"},
	{START,"START"},
	{FUNCTION,"FUNCTION"},
	{VARDECL,"VARDECL"},
	{DATATYPE,"DATATYPE"},
	{FUNCTIONDECLARATION,"FUNCTIONDECLARATION"},
	{PARAMLIST,"PARAMLIST"},
	{PARAMDECLS,"PARAMDECLS"},
	{PARAMDECLSNEW,"PARAMDECLSNEW"},
	{FUNCTYPE,"FUNCTYPE"},
	{BODY,"BODY"},
	{STATEMENTS,"STATEMENTS"},
	{STATEMENT,"STATEMENT"},
	{VARINIT,"VARINIT"},
	{FORRANGE,"FORRANGE"},
	{FORRANGENEW,"FORRANGENEW"},
	{ARGLIST,"ARGLIST"},
	{FUNCARGS,"FUNCARGS"},
	{FUNCARGSNEW,"FUNCARGSNEW"},
	{ELSECLAUSE,"ELSECLAUSE"},
	{ELSE,"ELSE"},
	{CONDITION,"CONDITION"},
	{CONDITIONNEW,"CONDITIONNEW"},
	{LOGOP,"LOGOP"},
	{ADDOP,"ADDOP"},
	{MULOP,"MULOP"},
	{EXPRESSION,"EXPRESSION"},
	{EXPRESSIONNEW,"EXPRESSIONNEW"},
	{TERM,"TERM"},
	{TERMNEW,"TERMNEW"},
	{FACTOR,"FACTOR"},
	{ZAKRES,"ZAKRES"},
	{DYCHA,"DYCHA"},
	{PRZECINEK,"PRZECINEK"},
	{TEKST,"TEKST"},
	{NIC,"NIC"},
	{FUNKCJA,"FUNKCJA"},
	{IDENTIFIER,"IDENTIFIER"},
	{CONSTANT,"CONSTANT"},
	{OPENING_ROUND,"OPENING_ROUND"},
	{CLOSING_ROUND,"CLOSING_ROUND"},
	{COMA,"COMA"},
	{COLON,"COLON"},
	{SEMICOLON,"SEMICOLON"},
	{OPENING_CURLY,"OPENING_CURLY"},
	{CLOSING_CURLY,"CLOSING_CURLY"},
	{OPENING_SQUARE,"OPENING_SQUARE"},
	{CLOSING_SQUARE,"CLOSING_SQUARE"},
	{PRZESTAN,"PRZESTAN"},
	{DALEJ,"DALEJ"},
	{ZWROC,"ZWROC"},
	{WYWOLAJ,"WYWOLAJ"},
	{DOPOKI,"DOPOKI"},
	{DLA,"DLA"},
	{JESLI,"JESLI"},
	{ASSIGN,"ASSIGN"},
	{INACZEJ,"INACZEJ"},
	{DOUBLE_EQUAL,"DOUBLE_EQUAL"},
	{NOT_EQUAL,"NOT_EQUAL"},
	{MORE,"MORE"},
	{LESS,"LESS"},
	{MORE_EQUAL,"MORE_EQUAL"},
	{LESS_EQUAL,"LESS_EQUAL"},
	{AND_OP,"AND_OP"},
	{OR_OP,"OR_OP"},
	{PLUS,"PLUS"},
	{MINUS,"MINUS"},
	{MULTIPLY,"MULTIPLY"},
	{DIVIDE,"DIVIDE"},
	{END,"END"},
	{ERROR,"ERROR"},
	{EPSILON,"EPSILON"},
	{GLOBALNE, "GLOBALNE"},
	{DODAJ, "DODAJ"}
};


std::unordered_map<string, Symbol> terminals_map = {
	{"zakres", ZAKRES},
	{"dycha", DYCHA},
	{"przecinek", PRZECINEK},
	{"tekst", TEKST},
	{"nic", NIC},
	{"funkcja", FUNKCJA},
	{"id", IDENTIFIER},
	{"const", CONSTANT},
	{"(", OPENING_ROUND},
	{")", CLOSING_ROUND},
	{",", COMA},
	{":", COLON},
	{";", SEMICOLON},
	{"{", OPENING_CURLY},
	{"}", CLOSING_CURLY},
	{"przestan", PRZESTAN},
	{"dalej", DALEJ},
	{"zwroc", ZWROC},
	{"wywolaj", WYWOLAJ},
	{"dopoki", DOPOKI},
	{"dla", DLA},
	{"jesli", JESLI},
	{"=", ASSIGN},
	{"inaczej", INACZEJ},
	{"==", DOUBLE_EQUAL},
	{"!=", NOT_EQUAL},
	{">", MORE},
	{"<", LESS},
	{">=", MORE_EQUAL},
	{"<=", LESS_EQUAL},
	{"&", AND_OP},
	{"|", OR_OP},
	{"+", PLUS},
	{"-", MINUS},
	{"*", MULTIPLY},
	{"/", DIVIDE},
	{"$", END},
	{"dodaj", DODAJ},
	{"globalne", GLOBALNE}
};
//debug purposes
                                /*   1  ,     2     ,   3   ,  4  ,    5    ,  6 ,   7   , 8 , 9 , 10, 11, 12, 13, 14,    15    ,   16  ,  17   ,    18   ,   19   , 20  ,   21  , 22,   23    , 24 , 25 , 26, 27, 28 , 30 , 31, 32, 33, 34, 35, 36,  37,   38    ,  40   ,   41     */
vector<std::string> terminals = {"dycha","przecinek","tekst","nic","funkcja","id","const","(",")",",",":",";","{","}","przestan","dalej","zwroc","wywolaj","dopoki","dla","jesli","=","inaczej","==","!=",">","<",">=","<=","&","|","+","-","*","/", "$", "zakres","dodaj","globalne"};

std::vector<Production> grammar = {	
/* 1*/{VARDECL, {DATATYPE, IDENTIFIER}},
/* 2*/{DATATYPE, {DYCHA}},
/* 3*/{DATATYPE, {PRZECINEK}},
/* 4*/{DATATYPE, {TEKST}},
/* 5*/{DATATYPE, {NIC}},
/* 6*/{FUNCTIONDECLARATION, {FUNKCJA, IDENTIFIER, PARAMLIST, FUNCTYPE}},
/* 7*/{PARAMLIST, {OPENING_ROUND, PARAMDECLS, CLOSING_ROUND}},
/* 8*/{PARAMDECLS, {VARDECL, PARAMDECLSNEW}},
/* 9*/{PARAMDECLS, {EPSILON}},
/*10*/{PARAMDECLSNEW, {COMA, VARDECL, PARAMDECLSNEW}},
/*11*/{PARAMDECLSNEW, {EPSILON}},
/*12*/{FUNCTYPE, {COLON, DATATYPE, COLON}},
/*13*/{BODY, {OPENING_CURLY, STATEMENTS, CLOSING_CURLY}},
/*14*/{STATEMENTS, {STATEMENT, STATEMENTS}},
/*15*/{STATEMENTS, {EPSILON}},
/*16*/{STATEMENT, {PRZESTAN, SEMICOLON}},
/*17*/{STATEMENT, {DALEJ, SEMICOLON}},
/*18*/{STATEMENT, {ZWROC, EXPRESSION, SEMICOLON}},
/*19*/{STATEMENT, {VARDECL, VARINIT, SEMICOLON}},
/*20*/{STATEMENT, {IDENTIFIER, VARINIT, SEMICOLON}},
/*21*/{STATEMENT, {EPSILON}},
/*22*/{STATEMENT, {WYWOLAJ, IDENTIFIER, ARGLIST, SEMICOLON}},
/*23*/{STATEMENT, {DOPOKI, CONDITION, COLON, BODY}},
/*24*/{STATEMENT, {DLA, IDENTIFIER, ZAKRES, OPENING_ROUND, FORRANGE, CLOSING_ROUND, COLON, BODY}},
/*25*/{STATEMENT, {JESLI, CONDITION, COLON, BODY, ELSECLAUSE}},
/*26*/{VARINIT, {ASSIGN, EXPRESSION}},
/*27*/{VARINIT, {EPSILON}},
/*28*/{FORRANGE, {EXPRESSION, FORRANGENEW}},
/*29*/{FORRANGENEW, {COMA, EXPRESSION}},
/*30*/{FORRANGENEW, {EPSILON}},
/*31*/{ARGLIST, {OPENING_ROUND, FUNCARGS, CLOSING_ROUND}},
/*32*/{FUNCARGS, {EXPRESSION, FUNCARGSNEW}},
/*33*/{FUNCARGS, {EPSILON}},
/*34*/{FUNCARGSNEW, {COMA, EXPRESSION, FUNCARGSNEW}},
/*35*/{FUNCARGSNEW, {EPSILON}},
/*36*/{ELSECLAUSE, {INACZEJ, ELSE}},
/*37*/{ELSECLAUSE, {EPSILON}},
/*38*/{ELSE, {JESLI, CONDITION, COLON, BODY, ELSECLAUSE}},
/*39*/{ELSE, {BODY}},
/*40*/{CONDITION, {EXPRESSION, CONDITIONNEW}},
/*41*/{CONDITIONNEW, {LOGOP, EXPRESSION, CONDITIONNEW}},
/*42*/{CONDITIONNEW, {EPSILON}},
/*43*/{LOGOP, {DOUBLE_EQUAL}},
/*44*/{LOGOP, {NOT_EQUAL}},
/*45*/{LOGOP, {MORE}},
/*46*/{LOGOP, {LESS}},
/*47*/{LOGOP, {MORE_EQUAL}},
/*48*/{LOGOP, {LESS_EQUAL}},
/*49*/{LOGOP, {AND_OP}},
/*50*/{LOGOP, {OR_OP}},
/*51*/{ADDOP, {PLUS}},
/*52*/{ADDOP, {MINUS}},
/*53*/{MULOP, {MULTIPLY}},
/*54*/{MULOP, {DIVIDE}},
/*55*/{EXPRESSION, {TERM, EXPRESSIONNEW}},
/*56*/{EXPRESSIONNEW, {ADDOP, TERM, EXPRESSIONNEW}},
/*57*/{EXPRESSIONNEW, {EPSILON}},
/*58*/{TERM, {FACTOR, TERMNEW}},
/*59*/{TERMNEW, {MULOP, FACTOR, TERMNEW}},
/*60*/{TERMNEW, {EPSILON}},
/*61*/{FACTOR, {IDENTIFIER}},
/*62*/{FACTOR, {CONSTANT}},
/*63*/{FACTOR, {OPENING_ROUND, EXPRESSION, CLOSING_ROUND}},
/*64*/{FACTOR, {WYWOLAJ, IDENTIFIER, ARGLIST}},
/*65*/{START, {INCLUDE, GLOBAL, FUNCTION}},
/*66*/{FUNCTION, {FUNCTIONDECLARATION, BODY, FUNCTION}},
/*67*/{FUNCTION, {EPSILON}},
/*68*/{INCLUDE, {DODAJ, IDENTIFIER, INCLUDE}},
/*69*/{INCLUDE, {EPSILON}},
/*70*/{GLOBAL, {GLOBALNE, OPENING_CURLY, GLOBALVAR, CLOSING_CURLY}},
/*71*/{GLOBAL, {EPSILON}},
/*72*/{GLOBALVAR, {VARDECL, VARINIT, SEMICOLON, GLOBALVAR}},
/*73*/{GLOBALVAR, {EPSILON}},
//for testing purposes 
/*74*/{EXPRESSION, {ADDOP, TERM, EXPRESSIONNEW}}
};

//debug purposes
                                  /*   1  ,     2     ,   3   ,  4  ,    5    ,  6 ,   7   , 8 , 9 , 10, 11, 12, 13, 14,    15    ,   16  ,  17   ,    18   ,   19   , 20  ,   21  , 22,   23    , 24 , 25 , 26, 27, 28 , 29 , 30, 31, 32, 33, 34, 35,  36,   37    ,  38   ,   39     */
//vector<std::string> terminals = {"dycha","przecinek","tekst","nic","funkcja","id","const","(",")",",",":",";","{","}","przestan","dalej","zwroc","wywolaj","dopoki","dla","jesli","=","inaczej","==","!=",">","<",">=","<=","&","|","+","-","*","/", "$", "zakres","dodaj","globalne"};

//here also added into an expression
vector<vector<int>> parsing_table = {
										/* { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39}*/ 				
	
/*INCLUDE*/            { 0, 0, 0, 0,69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,68,69},
/*GLOBAL*/             { 0, 0, 0, 0,71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,70},
/*GLOBALVAR*/          {72,72,72,72, 0, 0, 0, 0, 0, 0, 0, 0, 0,73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*START*/              { 0, 0, 0, 0,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,65,65},
/*Function*/           { 0, 0, 0, 0,66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,67, 0, 0, 0},
/*VarDecl*/            { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*DataType*/           { 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*FunctionDeclaration*/{ 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ParamList*/          { 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ParamDecls*/         { 8, 8, 8, 8, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ParamDeclsNew*/      { 0, 0, 0, 0, 0, 0, 0, 0,11,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*FuncType*/           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*Body*/               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*Statements*/         {14,14,14,14, 0,14, 0, 0, 0, 0, 0, 0, 0,15,14,14,14,14,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*Statement*/          {19,19,19,19, 0,20, 0, 0, 0, 0, 0, 0, 0,21,16,17,18,22,23,24,25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*VarInit*/            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,27, 0, 0, 0, 0, 0, 0, 0, 0, 0,26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ForRange*/           { 0, 0, 0, 0, 0,28,28,28, 0, 0, 0, 0, 0, 0, 0, 0, 0,28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ForRangeNew*/        { 0, 0, 0, 0, 0, 0, 0, 0,30,29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ArgList*/            { 0, 0, 0, 0, 0, 0, 0,31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*FuncArgs*/           { 0, 0, 0, 0, 0,32,32,32,33, 0, 0, 0, 0, 0, 0, 0, 0,32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*FuncArgsNew*/        { 0, 0, 0, 0, 0, 0, 0, 0,35,34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ElseClause*/         {37,37,37,37, 0,37, 0, 0, 0, 0, 0, 0, 0,37,37,37,37,37,37,37,37, 0,36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*Else*/               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,39, 0, 0, 0, 0, 0, 0, 0,38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*Condition*/          { 0, 0, 0, 0, 0,40,40,40, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*ConditionNew*/       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,41,41,41,41,41,41,41,41, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*LogOp*/              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,43,44,45,46,47,48,49,50, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*AddOp*/              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,51,52, 0, 0, 0, 0, 0, 0}, 
/*MulOp*/              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,53,54, 0, 0, 0, 0}, 
/*Expression*/         { 0, 0, 0, 0, 0,55,55,55, 0, 0, 0, 0, 0, 0, 0, 0, 0,55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,73, 0, 0, 0, 0, 0}, 
/*ExpressionNew*/      { 0, 0, 0, 0, 0, 0, 0, 0,57,57,57,57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,57,57,57,57,57,57,57,57,56,56, 0, 0, 0, 0, 0, 0}, 
/*Term*/               { 0, 0, 0, 0, 0,58,58,58, 0, 0, 0, 0, 0, 0, 0, 0, 0,58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
/*TermNew*/            { 0, 0, 0, 0, 0, 0, 0, 0,60,60,60,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60,60,60,60,60,60,60,60,60,60,59,59, 0, 0, 0, 0}, 
/*Factor*/             { 0, 0, 0, 0, 0,61,62,63, 0, 0, 0, 0, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
};

Symbol translateTokenToSymbol(const Token& token)
{
	switch(token.type)
	{
		case TYPE::Id:
			return IDENTIFIER;
			break;
		case TYPE::Str:
			return CONSTANT;
			break;
		case TYPE::Int:
			return CONSTANT;
			break;
		case TYPE::Float:
			return CONSTANT;
			break;
		default:
			return terminals_map[token.value];
			break;
	}
	return ERROR;
}

bool isTerminal(Symbol symbol)
{
	//symbols values in enum placed after zakres are terminal values
	return (symbol >= ZAKRES);
}
