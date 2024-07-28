#ifndef PARSER
#define PARSER

#include "lex.h"

//non-terminals
class VarDecl;
class Include;
class Global;
class GlobalVar;
class Start;
class Function;
class VarDecl;
class DataType;
class FunctionDeclarati;
class ParamList;
class ParamDecls;
class ParamDeclsNew;
class FuncType;
class Body;
class Statements;
class Statement;
class VarInit;
class ForRange;
class ForRangeNew;
class ArgList;
class FuncArgs;
class FuncArgsNew;
class ElseClause;
class Else;
class Condition;
class ConditionNew;
class LogOp;    
class AddOp;
class MulOp;
class Expression;
class ExpressionNew;
class Term;
class TermNew;
class Factor;
//end of non-terminals
//terminals
class Zakres;
class Dycha;
class Przecinek;
class Tekst;
class Nic;
class Funkcja;
class Identifier;
class Constant;
class OpeningRound;
class ClosingRound;
class Coma;
class Colon;
class Semicolon;
class OpeningCurly;
class ClosingCurly;
class OpeningSquare;
class ClosingSquare;
class Przestan;
class Dalej;
class Zwroc;
class Wywolaj;
class Dopoki;
class Dla;
class Jesli;
class Assign;
class Inaczej;
class DoubleEqual;
class NotEqual;
class More;
class Less;
class MoreEqual;
class LessEqual;
class AndOp;
class OrOp;
class Plus;
class Minus;
class Multiply;
class Divide;
class End;
class Error;
class Epsilon;
class Globalne;
class Dodaj;
//end of terminals

class Symbol {
  std::vector<Symbol*> rhs;
  std::string name;
public:
  virtual int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) = 0;
  const std::string getName() const;
};

class VarDecl : public Symbol {
  std::string name = "VarDecl";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

//start of non-terminal
class Include : public Symbol {
  std::string name = "Include";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Global : public Symbol {
  std::string name = "Global";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class GlobalVar : public Symbol {
  std::string name = "GlobalVar";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Start : public Symbol {
  std::string name = "Start";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Function : public Symbol {
  std::string name = "Function";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class DataType : public Symbol {
  std::string name = "DataType";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FunctionDeclaration : public Symbol {
  std::string name = "FunctionDeclaration";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ParamList : public Symbol {
  std::string name = "ParamList";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ParamDecls : public Symbol {
  std::string name = "ParamDecls";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ParamDeclsNew : public Symbol {
  std::string name = "ParamDeclsNew";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FuncType : public Symbol {
  std::string name = "FuncType";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Body : public Symbol {
  std::string name = "Body";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Statements : public Symbol {
  std::string name = "Satements";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Statement : public Symbol {
  std::string name = "Statement";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class VarInit : public Symbol {
  std::string name = "VarInit";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ForRange : public Symbol {
  std::string name = "ForRange";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ForRangeNew : public Symbol {
  std::string name = "ForRangeNew";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ArgList : public Symbol {
  std::string name = "ArgList";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FuncArgs : public Symbol {
  std::string name = "FuncArgs";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FuncArgsNew : public Symbol {
  std::string name = "FuncArgsNew";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ElseClause : public Symbol {
  std::string name = "ElseClause";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Else : public Symbol {
  std::string name = "Else";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Condition : public Symbol {
  std::string name = "Condition";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ConditionNew : public Symbol {
  std::string name = "ConditionNew";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class LogOp : public Symbol {
  std::string name = "LogOp";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class AddOp : public Symbol {
  std::string name = "AddOp";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class MulOp : public Symbol {
  std::string name = "MulOp";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Expression : public Symbol {
  std::string name = "Expression";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ExpressionNew : public Symbol {
  std::string name = "ExpressionNew";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Term : public Symbol {
  std::string name = "Term";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class TermNew : public Symbol {
  std::string name = "TermNew";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Factor : public Symbol {
  std::string name = "Factor";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
//end of non terminals
//*** TERMINALS ***
class Zakres : public Symbol {
  std::string name = "Zakres";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Dycha : public Symbol {
  std::string name = "Dycha";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Przecinek : public Symbol {
  std::string name = "Przecinek";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Tekst : public Symbol {
  std::string name = "Tekst";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Nic : public Symbol {
  std::string name = "Nic";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Funkcja : public Symbol {
  std::string name = "Funkcja";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Identifier : public Symbol {
  std::string name = "Identifier";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Constant : public Symbol {
  std::string name = "Constant";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class OpeningRound : public Symbol {
  std::string name = "OpeningRound";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class ClosingRound : public Symbol {
  std::string name = "ClosingRound";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Coma : public Symbol {
  std::string name = "Coma";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Colon : public Symbol {
  std::string name = "Colon";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Semicolon : public Symbol {
  std::string name = "Semicolon";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class OpeningCurly : public Symbol {
  std::string name = "OpeningCurly";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class ClosingCurly : public Symbol {
  std::string name = "ClosingCurly";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class OpeningSquare : public Symbol {
  std::string name = "OpeningSquare";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class ClosingSquare : public Symbol {
  std::string name = "ClosingSquare";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Przestan : public Symbol {
  std::string name = "Przestan";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Dalej : public Symbol {
  std::string name = "Dalej";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Zwroc : public Symbol {
  std::string name = "Zwroc";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Wywolaj : public Symbol {
  std::string name = "Wywolaj";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Dopoki : public Symbol {
  std::string name = "Dopoki";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Dla : public Symbol {
  std::string name = "Dla";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Jesli : public Symbol {
  std::string name = "Jesli";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Assign : public Symbol {
  std::string name = "Assign";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Inaczej : public Symbol {
  std::string name = "Inaczej";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class DoubleEqual : public Symbol {
  std::string name = "DoubleEqual";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class NotEqual : public Symbol {
  std::string name = "NotEqual";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class More : public Symbol {
  std::string name = "More";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Less : public Symbol {
  std::string name = "Less";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class MoreEqual : public Symbol {
  std::string name = "MoreEqual";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class LessEqual : public Symbol {
  std::string name = "LessEqual";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class AndOp : public Symbol {
  std::string name = "AndOp";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class OrOp : public Symbol {
  std::string name = "OrOp";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Plus : public Symbol {
  std::string name = "Plus";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Minus : public Symbol {
  std::string name = "Minus";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Multiply : public Symbol {
  std::string name = "Multiply";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Divide : public Symbol {
  std::string name = "Divide";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class End : public Symbol {
  std::string name = "End";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Error : public Symbol {
  std::string name = "Error";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Epsilon : public Symbol {
  std::string name = "Epsilon";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Globalne : public Symbol {
  std::string name = "Globalne";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
class Dodaj : public Symbol {
  std::string name = "Symbol";
public:
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
//*** END OF TERMINALS ***

class SymbolFactory {
public:
  Symbol* getSymbol(const Token& token){
    //here need to add implementation of turning token to a symbol class
  }
};

#endif