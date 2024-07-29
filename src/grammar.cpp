#include "../inc/grammar.h"

const std::string Symbol::getName() const
{
  return name;
}

//Non terminal constructors:
Include::Include()
{
  name = "Include";
}
Global::Global()
{
  name = "Global";
}
GlobalVar::GlobalVar()
{
  name = "GlobalVar";
}
Start::Start()
{
  name = "Start";
}
Function::Function()
{
  name = "Function";
}
VarDecl::VarDecl()
{
  name = "VarDecl";
}
DataType::DataType()
{
  name = "DataType";
}
FunctionDeclaration::FunctionDeclaration()
{
  name = "FunctionDeclarati";
}
ParamList::ParamList()
{
  name = "ParamList";
}
ParamDecls::ParamDecls()
{
  name = "ParamDecls";
}
ParamDeclsNew::ParamDeclsNew()
{
  name = "ParamDeclsNew";
}
FuncType::FuncType()
{
  name = "FuncType";
}
Body::Body()
{
  name = "Body";
}
Statements::Statements()
{
  name = "Statements";
}
Statement::Statement()
{
  name = "Statement";
}
VarInit::VarInit()
{
  name = "VarInit";
}
ForRange::ForRange()
{
  name = "ForRange";
}
ForRangeNew::ForRangeNew()
{
  name = "ForRangeNew";
}
ArgList::ArgList()
{
  name = "ArgList";
}
FuncArgs::FuncArgs()
{
  name = "FuncArgs";
}
FuncArgsNew::FuncArgsNew()
{
  name = "FuncArgsNew";
}
ElseClause::ElseClause()
{
  name = "ElseClause";
}
Else::Else()
{
  name = "Else";
}
Condition::Condition()
{
  name = "Condition";
}
ConditionNew::ConditionNew()
{
  name = "ConditionNew";
}
LogOp::LogOp()
{
  name = "LogOp";
}
AddOp::AddOp()
{
  name = "AddOp";
}
MulOp::MulOp()
{
  name = "MulOp";
}
Expression::Expression()
{
  name = "Expression";
}
ExpressionNew::ExpressionNew()
{
  name = "ExpressionNew";
}
Term::Term()
{
  name = "Term";
}
TermNew::TermNew()
{
  name = "TermNew";
}
Factor::Factor()
{
  name = "Factor";
}

//terminals constructors:
Zakres::Zakres()
{
  name = "Zakres";
};
Dycha::Dycha()
{
  name = "Dycha";
};
Przecinek::Przecinek()
{
  name = "Przecinek";
};
Tekst::Tekst()
{
  name = "Tekst";
};
Nic::Nic()
{
  name = "Nic";
};
Funkcja::Funkcja()
{
  name = "Funkcja";
};
Identifier::Identifier()
{
  name = "Identifier";
};
Constant::Constant()
{
  name = "Constant";
};
OpeningRound::OpeningRound()
{
  name = "OpeningRound";
};
ClosingRound::ClosingRound()
{
  name = "ClosingRound";
};
Coma::Coma()
{
  name = "Coma";
};
Colon::Colon()
{
  name = "Colon";
};
Semicolon::Semicolon()
{
  name = "Semicolon";
};
OpeningCurly::OpeningCurly()
{
  name = "OpeningCurly";
};
ClosingCurly::ClosingCurly()
{
  name = "ClosingCurly";
};
OpeningSquare::OpeningSquare()
{
  name = "OpeningSquare";
};
ClosingSquare::ClosingSquare()
{
  name = "ClosingSquare";
};
Przestan::Przestan()
{
  name = "Przestan";
};
Dalej::Dalej()
{
  name = "Dalej";
};
Zwroc::Zwroc()
{
  name = "Zwroc";
};
Wywolaj::Wywolaj()
{
  name = "Wywolaj";
};
Dopoki::Dopoki()
{
  name = "Dopoki";
};
Dla::Dla()
{
  name = "Dla";
};
Jesli::Jesli()
{
  name = "Jesli";
};
Assign::Assign()
{
  name = "Assign";
};
Inaczej::Inaczej()
{
  name = "Inaczej";
};
DoubleEqual::DoubleEqual()
{
  name = "DoubleEqual";
};
NotEqual::NotEqual()
{
  name = "NotEqual";
};
More::More()
{
  name = "More";
};
Less::Less()
{
  name = "Less";
};
MoreEqual::MoreEqual()
{
  name = "MoreEqual";
};
LessEqual::LessEqual()
{
  name = "LessEqual";
};
AndOp::AndOp()
{
  name = "AndOp";
};
OrOp::OrOp()
{
  name = "OrOp";
};
Plus::Plus()
{
  name = "Plus";
};
Minus::Minus()
{
  name = "Minus";
};
Multiply::Multiply()
{
  name = "Multiply";
};
Divide::Divide()
{
  name = "Divide";
};
End::End()
{
  name = "End";
};
Error::Error()
{
  name = "Error";
};
Epsilon::Epsilon()
{
  name = "Epsilon";
};
Globalne::Globalne()
{
  name = "Globalne";
};
Dodaj::Dodaj()
{
  name = "Dodaj";
};













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
  if (token.value == "(")
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
  else {
    return 1;
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
  else if (token.value == "}")
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
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj" || token.value == "-")
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
  //needed to enable minus constant values
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
  if (token.value == "zakres")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Dycha::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dycha")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Przecinek::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "przecinek")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Tekst::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "tekst")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Nic::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "nic")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Funkcja::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "funkcja")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Identifier::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.type == TYPE::Id)
  {
    ////delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Constant::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.type == TYPE::Int || token.type == TYPE::Float || token.type == TYPE::Str)
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int OpeningRound::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "(")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int ClosingRound::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ")")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Coma::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ",")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Colon::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ":")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Semicolon::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ";")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int OpeningCurly::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "{")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int ClosingCurly::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "}")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int OpeningSquare::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "[")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int ClosingSquare::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "]")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Przestan::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "przestan")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Dalej::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dalej")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Zwroc::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "zwroc")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Wywolaj::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "wywolaj")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Dopoki::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dopoki")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Dla::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dla")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Jesli::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "jesli")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Assign::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "=")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Inaczej::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "inaczej")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int DoubleEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "==")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int NotEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "!=")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int More::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ">")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Less::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "<")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int MoreEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == ">=")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int LessEqual::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "<=")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int AndOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "&")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int OrOp::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "|")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Plus::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "+")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Minus::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "-")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Multiply::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "*")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Divide::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "/")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int End::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "$")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

//todo -> do I even need this symbol???
int Error::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "zakres")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Epsilon::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  //delete sym_stack.back();
  //sym_stack.pop_back();
  return 0;
}

int Globalne::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "globalne")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}

int Dodaj::evaluate(std::vector<Symbol *> &sym_stack, const Token& token)
{
  if (token.value == "dodaj")
  {
    //delete sym_stack.back();
    //sym_stack.pop_back();
    return 2;
  }
  return 1;
}



