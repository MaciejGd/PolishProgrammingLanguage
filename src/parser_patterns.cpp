#include "../inc/parser_patterns.h"
#include "parser_patterns.h"

const std::string Symbol::getName() const
{
  return name;
}

//*** NON-TERMINALS ***
int VarDecl::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value=="dycha" || token.value=="przecinek" || token.value=="tekst" || token.value=="nic")
  {
    sym_stack.push_back(new DataType{});
    sym_stack.push_back(new Identifier{});
    return 0;
  }
  //std::cout << "[ERROR]Failed to parse symbol: " << sym_stack.back()->getName() << " in token: " << token << "\n";
  return 1;
}

int Include::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "funkcja" || token.value == "globalne")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "dodaj")
  {
    sym_stack.push_back(new Include{});
    sym_stack.push_back(new Identifier{});
    sym_stack.push_back(new Dodaj{});
  }
  else {
    return 1;
  }
  return 0;
}

int Global::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "funkcja")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "globalne")
  {
    sym_stack.push_back(new Globalne{});
    sym_stack.push_back(new OpeningCurly{});
    sym_stack.push_back(new GlobalVar{});
    sym_stack.push_back(new ClosingCurly{});
  }
  else {
    return 1;
  }
  return 0;
}

int GlobalVar::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha" | token.value == "przecinek" || token.value == "")
  return 0;
}

int Start::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Function::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int VarDecl::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int DataType::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int FunctionDeclaration::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ParamList::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ParamDecls::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ParamDeclsNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int FuncType::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Body::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Statements::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Statement::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int VarInit::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ForRange::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ForRangeNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ArgList::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int FuncArgs::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int FuncArgsNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ElseClause::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Else::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Condition::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ConditionNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int LogOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int AddOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int MulOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Expression::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ExpressionNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Term::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int TermNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Factor::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

//*** TERMINALS ***
int Zakres::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Dycha::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Przecinek::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Tekst::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Nic::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Funkcja::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Identifier::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Constant::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int OpeningRound::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ClosingRound::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Coma::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Colon::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Semicolon::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int OpeningCurly::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ClosingCurly::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int OpeningSquare::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int ClosingSquare::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Przestan::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Dalej::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Zwroc::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Wywolaj::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Dopoki::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Dla::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Jesli::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Assign::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Inaczej::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int DoubleEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int NotEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int More::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Less::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int MoreEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int LessEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int AndOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int OrOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Plus::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Minus::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Multiply::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Divide::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int End::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Error::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Epsilon::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Globalne::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}

int Dodaj::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}



int VarDecl::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  return 0;
}


