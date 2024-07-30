#ifndef PARSER
#define PARSER

#include "lex.h"
#include <memory>

class Symbol;

//Node of AST(Abstract Syntax Tree)
//structure of node class and implementation needs further investigation
// class AST_Node {
//   Symbol* value;
//   std::vector<Symbol*> children;
// public:
//   AST_Node();
//   void addChild();
//   //acessors
//   const Symbol* getValue() const;
//   const std::vector<std::shared_ptr<Symbol*>> getChildren() const;
// };

//non-terminals
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
protected:
  std::vector<Symbol*> rhs;
  std::string name;
public:
  virtual int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) = 0;
  const std::string getName() const;
};

class VarDecl : public Symbol {
public:
  VarDecl();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

//start of non-terminal
class Include : public Symbol {
public:
  Include();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Global : public Symbol {
public:
  Global();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class GlobalVar : public Symbol {
public:
  GlobalVar();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Start : public Symbol {
public:
  Start();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Function : public Symbol {
public:
  Function();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class DataType : public Symbol {
public:
  DataType();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FunctionDeclaration : public Symbol {
public:
  FunctionDeclaration();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ParamList : public Symbol {
public:
  ParamList();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ParamDecls : public Symbol {
public:
  ParamDecls();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ParamDeclsNew : public Symbol {
public:
  ParamDeclsNew();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FuncType : public Symbol {
public:
  FuncType();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Body : public Symbol {
public:
  Body();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Statements : public Symbol {
public:
  Statements();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Statement : public Symbol {
public:
  Statement();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class VarInit : public Symbol {
public:
  VarInit();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ForRange : public Symbol {
public:
  ForRange();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ForRangeNew : public Symbol {
public:
  ForRangeNew();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ArgList : public Symbol {
public:
  ArgList();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FuncArgs : public Symbol {
public:
  FuncArgs();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class FuncArgsNew : public Symbol {
public:
  FuncArgsNew();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ElseClause : public Symbol {
public:
  ElseClause();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Else : public Symbol {
public:
  Else();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Condition : public Symbol {
public:
  Condition();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ConditionNew : public Symbol {
public:
  ConditionNew();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class LogOp : public Symbol {
public:
  LogOp();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class AddOp : public Symbol {
public:
  AddOp();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class MulOp : public Symbol {
public:
  MulOp();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Expression : public Symbol {
public:
  Expression();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ExpressionNew : public Symbol {
public:
  ExpressionNew();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Term : public Symbol {
public:
  Term();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class TermNew : public Symbol {
public:
  TermNew();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Factor : public Symbol {
public:
  Factor();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
//end of non terminals
//*** TERMINALS ***
class Zakres : public Symbol {
public:
  Zakres();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Dycha : public Symbol {
public:
  Dycha();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Przecinek : public Symbol {
public:
  Przecinek();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Tekst : public Symbol {
public:
  Tekst();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Nic : public Symbol {
public:
  Nic();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Funkcja : public Symbol {
public:
  Funkcja();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Identifier : public Symbol {
public:
  Identifier();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Constant : public Symbol {
public:
  Constant();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class OpeningRound : public Symbol {
public:
  OpeningRound();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ClosingRound : public Symbol {
public:
  ClosingRound();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Coma : public Symbol {
public:
  Coma();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Colon : public Symbol {
public:
  Colon();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Semicolon : public Symbol {
public:
  Semicolon();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class OpeningCurly : public Symbol {
public:
  OpeningCurly();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ClosingCurly : public Symbol {
public:
  ClosingCurly();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class OpeningSquare : public Symbol {
public:
  OpeningSquare();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class ClosingSquare : public Symbol {
public:
  ClosingSquare();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Przestan : public Symbol {
public:
  Przestan();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Dalej : public Symbol {
public:
  Dalej();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Zwroc : public Symbol {
public:
  Zwroc();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Wywolaj : public Symbol {
public:
  Wywolaj();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Dopoki : public Symbol {
public:
  Dopoki();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Dla : public Symbol {
public:
  Dla();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Jesli : public Symbol {
public:
  Jesli();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Assign : public Symbol {
public:
  Assign();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Inaczej : public Symbol {
public:
  Inaczej();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class DoubleEqual : public Symbol {
public:
  DoubleEqual();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class NotEqual : public Symbol {
public:
  NotEqual();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class More : public Symbol {
public:
  More();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Less : public Symbol {
public:
  Less();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class MoreEqual : public Symbol {
public:
  MoreEqual();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class LessEqual : public Symbol {
public:
  LessEqual();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class AndOp : public Symbol {
public:
  AndOp();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class OrOp : public Symbol {
public:
  OrOp();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Plus : public Symbol {
public:
  Plus();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Minus : public Symbol {
public:
  Minus();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Multiply : public Symbol {
public:
  Multiply();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Divide : public Symbol {
public:
  Divide();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class End : public Symbol {
public:
  End();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Error : public Symbol {
public:
  Error();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Epsilon : public Symbol {
public:
  Epsilon();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Globalne : public Symbol {
public:
  Globalne();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};

class Dodaj : public Symbol {
public:
  Dodaj();
  int evaluate(std::vector<Symbol*>& sym_stack, const Token& token) override;
};
//*** END OF TERMINALS ***

#endif