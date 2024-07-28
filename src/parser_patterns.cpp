#include "../inc/parser_patterns.h"

const std::string Symbol::getName() const
{
  return name;
}

//*** NON-TERMINALS ***

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
    sym_stack.push_back(new ClosingCurly{});
    sym_stack.push_back(new GlobalVar{});
    sym_stack.push_back(new OpeningCurly{});
    sym_stack.push_back(new Globalne{});
  }
  else {
    return 1;
  }
  return 0;
}

int GlobalVar::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha" | token.value == "przecinek" || token.value == "nic" || token.value == "tekst")
  {
    sym_stack.push_back(new GlobalVar{});
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new VarInit{});
    sym_stack.push_back(new VarDecl{});
  }
  else if (token.value == "}")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int Start::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value=="funkcja" || token.value=="dodaj" || token.value == "globalne")
  {
    sym_stack.push_back(new Function{});
    sym_stack.push_back(new Global{});
    sym_stack.push_back(new Include{});
    return 0;
  }
  return 1;
}

int Function::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "funkcja")
  {
    sym_stack.push_back(new Function{});
    sym_stack.push_back(new Body{});
    sym_stack.push_back(new FunctionDeclaration{});
  }
  else if (token.value == "$")
  {
    sym_stack.push_back(new Epsilon{});
  }
  return 0;
}

int VarDecl::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value=="dycha" || token.value=="przecinek" || token.value=="tekst" || token.value=="nic")
  {
    sym_stack.push_back(new Identifier{});
    sym_stack.push_back(new DataType{});
    return 0;
  }
  //std::cout << "[ERROR]Failed to parse symbol: " << sym_stack.back()->getName() << " in token: " << token << "\n";
  return 1;
}

int DataType::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha")
  {
    sym_stack.push_back(new Dycha{});
  }
  else if (token.value == "przecinek")
  {
    sym_stack.push_back(new Przecinek{});
  }
  else if (token.value == "tekst")
  {
    sym_stack.push_back(new Tekst{});
  }
  else if (token.value == "nic")
  {
    sym_stack.push_back(new Nic{});
  }
  else {
    return 1;
  }
  return 0;
}

int FunctionDeclaration::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "funkcja")
  {
    sym_stack.push_back(new FuncType{});
    sym_stack.push_back(new ParamList{});
    sym_stack.push_back(new Identifier{});
    sym_stack.push_back(new Funkcja{});
    return 0;
  }
  return 1;
}

int ParamList::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.type == TYPE::Int || token.type == TYPE::Float || token.type == TYPE::Str)
  {
    sym_stack.push_back(new ClosingRound{});
    sym_stack.push_back(new ParamDecls{});
    sym_stack.push_back(new OpeningRound{});
    return 0;
  }
  return 1;
}

int ParamDecls::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic")
  {
    sym_stack.push_back(new ParamDeclsNew{});
    sym_stack.push_back(new VarDecl{});
  }
  else if (token.value == ")")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int ParamDeclsNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ")")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == ",")
  {
    sym_stack.push_back(new ParamDeclsNew{});
    sym_stack.push_back(new VarDecl{});
    sym_stack.push_back(new Coma{});
  }
  else {
    return 1;
  }
  return 0;
}

int FuncType::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ":")
  {
    sym_stack.push_back(new Colon{});
    sym_stack.push_back(new DataType{});
    sym_stack.push_back(new Colon{});
    return 0;
  }
  return 1;
}

int Body::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "{")
  {
    sym_stack.push_back(new ClosingCurly{});
    sym_stack.push_back(new Statements{});
    sym_stack.push_back(new OpeningCurly{});
    return 0;
  }
  return 1;
}

int Statements::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic" ||
        token.type == TYPE::Id || token.value == "przestan" || token.value == "dalej"|| token.value == "zwroc" ||
        token.value == "wywolaj" || token.value == "dopoki" || token.value == "dla" || token.value == "jesli")
  {
    sym_stack.push_back(new Statements{});
    sym_stack.push_back(new Statement{});
  }
  else if (token.value == "}")
  {
    sym_stack.push_back(new Epsilon{});
  }
  return 0;
}

int Statement::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic")
  {
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new VarInit{});
    sym_stack.push_back(new VarDecl{});
  }
  else if (token.type == TYPE::Id)
  {
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new VarInit{});
    sym_stack.push_back(new Identifier{});
  }
  else if ("}")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "przestan")
  {
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new Przestan{});
  }
  else if (token.value == "dalej")
  {
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new Dalej{});
  }
  else if (token.value == "zwroc")
  {
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new Expression{});
    sym_stack.push_back(new Zwroc{});
  }
  else if (token.value == "wywolaj")
  {
    sym_stack.push_back(new Semicolon{});
    sym_stack.push_back(new ArgList{});
    sym_stack.push_back(new Identifier{});
    sym_stack.push_back(new Wywolaj{});
  }
  else if (token.value == "dopoki")
  {
    sym_stack.push_back(new Body{});
    sym_stack.push_back(new Colon{});
    sym_stack.push_back(new Condition{});
    sym_stack.push_back(new Dopoki{});
  }
  else if (token.value == "dla")
  {
    sym_stack.push_back(new Body{});
    sym_stack.push_back(new Colon{});
    sym_stack.push_back(new ClosingRound{});
    sym_stack.push_back(new ForRange{});
    sym_stack.push_back(new OpeningRound{});
    sym_stack.push_back(new Zakres{});
    sym_stack.push_back(new Identifier{});
    sym_stack.push_back(new Dla{});
  }
  else if (token.value == "jesli")
  {
    sym_stack.push_back(new ElseClause{});
    sym_stack.push_back(new Body{});
    sym_stack.push_back(new Colon{});
    sym_stack.push_back(new Condition{});
    sym_stack.push_back(new Jesli{});
  }
  else {
    return 1;
  }
  return 0;
}

int VarInit::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ";")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "=")
  {
    sym_stack.push_back(new Expression{});
    sym_stack.push_back(new Assign{});
  }
  else {
    return 1;
  }
  return 0;
}

int ForRange::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    sym_stack.push_back(new ForRangeNew{});
    sym_stack.push_back(new Expression{});
    return 0;
  }
  return 1;
}

int ForRangeNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ")")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == ",")
  {
    sym_stack.push_back(new Expression{});
    sym_stack.push_back(new Coma{});
  }
  else {
    return 1;
  }
  return 0;
}

int ArgList::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "(")
  {
    sym_stack.push_back(new ClosingRound{});
    sym_stack.push_back(new FuncArgs{});
    sym_stack.push_back(new OpeningRound{});
  }
  return 0;
}

int FuncArgs::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.type == TYPE::Str || token.type == TYPE::Float || token.type == TYPE::Int ||
      token.type == TYPE::Id || token.value == "(" || token.value == "wywolaj")
  {
    sym_stack.push_back(new FuncArgsNew{});
    sym_stack.push_back(new Expression{});
  }
  else if (token.value == ")")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int FuncArgsNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ")")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == ",")
  {
    sym_stack.push_back(new FuncArgsNew{});
    sym_stack.push_back(new Expression{});
    sym_stack.push_back(new Coma{});
  }
  else {
    return 1;
  }
  return 0;
}

int ElseClause::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic" ||
        token.type == TYPE::Id || token.value == "}" || token.value == "przestan" || token.value == "dalej" ||
        token.value == "zwroc" || token.value == "wywolaj" || token.value == "dopoki" || token.value == "dla" ||
        token.value == "jesli")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "inaczej")
  {
    sym_stack.push_back(new Else{});
    sym_stack.push_back(new Inaczej{});
  }
  else {
    return 1;
  }
  return 0;
}

int Else::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "{")
  {
    sym_stack.push_back(new Body{});
  }
  else if (token.value == "jesli")
  {
    sym_stack.push_back(new ElseClause{});
    sym_stack.push_back(new Body{});
    sym_stack.push_back(new Colon{});
    sym_stack.push_back(new Condition{});
    sym_stack.push_back(new Jesli{});
  }
  else {
    return 1;
  }
  return 0;
}

int Condition::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    sym_stack.push_back(new ConditionNew{});
    sym_stack.push_back(new Expression{});
    return 0;
  }
  return 1;
}

int ConditionNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ":")
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "==" || token.value == "!=" || token.value == ">" || token.value == "<" ||
            token.value == ">=" || token.value == "<=" || token.value == "&" || token.value == "|" )
  {
    sym_stack.push_back(new ConditionNew{});
    sym_stack.push_back(new Expression{});
    sym_stack.push_back(new LogOp{});
  }
  else {
    return 1;
  }
  return 0;
}

int LogOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "==")
    sym_stack.push_back(new DoubleEqual{});
  else if (token.value == "!=")
    sym_stack.push_back(new NotEqual{});
  else if (token.value == ">")
    sym_stack.push_back(new More{});
  else if (token.value == "<")
    sym_stack.push_back(new Less{});
  else if (token.value == ">=")
    sym_stack.push_back(new MoreEqual{});
  else if (token.value == "<=")
    sym_stack.push_back(new LessEqual{});
  else if (token.value == "&")
    sym_stack.push_back(new AndOp{});
  else if (token.value == "|")
    sym_stack.push_back(new OrOp{});
  else 
    return 1;
  return 0;
}

int AddOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "+")
    sym_stack.push_back(new Plus{});
  else if (token.value == "-")
    sym_stack.push_back(new Minus{});
  else 
    return 1;
  return 0;
}

int MulOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "*")
    sym_stack.push_back(new Multiply{});
  else if (token.value == "/")
    sym_stack.push_back(new Divide{});
  else 
    return 1;
  return 0;
}

int Expression::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    sym_stack.push_back(new ExpressionNew{});
    sym_stack.push_back(new Term{});
  }
  //todo -> needs a fix
  else if (token.value == "-")
  {
    sym_stack.push_back(new ExpressionNew{});
    sym_stack.push_back(new Term{});
    sym_stack.push_back(new AddOp{});
  }
  else {
    return 1;
  }
  return 0;
}

int ExpressionNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "==" || token.value == "!=" || token.value == ">" || token.value == "<" || 
      token.value == ">=" || token.value == "<=" || token.value == "&" || token.value == "|" ||
      token.value == ")" || token.value == "," || token.value == ":" || token.value == ";") 
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "+" || token.value == "-")
  {
    sym_stack.push_back(new ExpressionNew{});
    sym_stack.push_back(new Term{});
    sym_stack.push_back(new AddOp{});
  }
  else 
    return 1;
  return 0;
}

int Term::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    sym_stack.push_back(new TermNew{});
    sym_stack.push_back(new Factor{});
    return 0;
  }
  return 1;
}

int TermNew::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "==" || token.value == "!=" || token.value == ">" || token.value == "<" || 
      token.value == ">=" || token.value == "<=" || token.value == "&" || token.value == "|" ||
      token.value == ")" || token.value == "," || token.value == ":" || token.value == ";" || 
      token.value == "+" || token.value == "-") 
  {
    sym_stack.push_back(new Epsilon{});
  }
  else if (token.value == "*" || token.value == "/")
  {
    sym_stack.push_back(new TermNew{});
    sym_stack.push_back(new Factor{});
    sym_stack.push_back(new MulOp{});
  }
  else {
    return 1;
  }
  return 0;
}

int Factor::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.type == TYPE::Id)
  {
    sym_stack.push_back(new Identifier{});
  }
  else if (token.type == TYPE::Int || token.type == TYPE::Float || token.type == TYPE::Str)
  {
    sym_stack.push_back(new Constant{});
  }
  else if (token.value == "(")
  {
    sym_stack.push_back(new ClosingRound{});
    sym_stack.push_back(new Expression{});
    sym_stack.push_back(new OpeningRound{});
  }
  else if (token.value == "wywolaj")
  {
    sym_stack.push_back(new ArgList{});
    sym_stack.push_back(new Identifier{});
    sym_stack.push_back(new Wywolaj{});
  }
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



