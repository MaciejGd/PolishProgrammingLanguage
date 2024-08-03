#include "../inc/grammar.h"

const std::string Symbol::getName() const
{
  return name;
}

const size_t Symbol::getRhsSize() const
{
  return rhs.size();
}

Symbol *Symbol::getRhsNode(size_t index) const
{
  return rhs[index];
}

void Symbol::setValue(const std::string& val)
{
  value = val;
}
// Non terminal constructors:
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
Modulo::Modulo()
{
  name = "Modulo";
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

int Include::evaluate(const Token& token)
{
  if (token.value == "funkcja" || token.value == "globalne")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "dodaj")
  {
    rhs.push_back(new Include{});
    rhs.push_back(new Identifier{});
    rhs.push_back(new Dodaj{});
  }
  else {
    return 1;
  }
  return 0;
}

int Global::evaluate(const Token& token)
{
  if (token.value == "funkcja")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "globalne")
  {
    rhs.push_back(new ClosingCurly{});
    rhs.push_back(new GlobalVar{});
    rhs.push_back(new OpeningCurly{});
    rhs.push_back(new Globalne{});
  }
  else {
    return 1;
  }
  return 0;
}

int GlobalVar::evaluate(const Token& token)
{
  if (token.value == "dycha" | token.value == "przecinek" || token.value == "nic" || token.value == "tekst")
  {
    rhs.push_back(new GlobalVar{});
    rhs.push_back(new Semicolon{});
    rhs.push_back(new VarInit{});
    rhs.push_back(new VarDecl{});
  }
  else if (token.value == "}")
  {
    rhs.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int Start::evaluate(const Token& token)
{
  if (token.value=="funkcja" || token.value=="dodaj" || token.value == "globalne")
  {
    rhs.push_back(new End{});
    rhs.push_back(new Function{});
    rhs.push_back(new Global{});
    rhs.push_back(new Include{});
    return 0;
  }
  return 1;
}

int Function::evaluate(const Token& token)
{
  if (token.value == "funkcja")
  {
    rhs.push_back(new Function{});
    rhs.push_back(new Body{});
    rhs.push_back(new FunctionDeclaration{});
  }
  else if (token.value == "$")
  {
    rhs.push_back(new Epsilon{});
  }
  return 0;
}

int VarDecl::evaluate(const Token& token)
{
  if (token.value=="dycha" || token.value=="przecinek" || token.value=="tekst" || token.value=="nic")
  {
    rhs.push_back(new Identifier{});
    rhs.push_back(new DataType{});
    return 0;
  }
  //std::cout << "[ERROR]Failed to parse symbol: " << rhs.back()->getName() << " in token: " << token << "\n";
  return 1;
}

int DataType::evaluate(const Token& token)
{
  if (token.value == "dycha")
  {
    rhs.push_back(new Dycha{});
  }
  else if (token.value == "przecinek")
  {
    rhs.push_back(new Przecinek{});
  }
  else if (token.value == "tekst")
  {
    rhs.push_back(new Tekst{});
  }
  else if (token.value == "nic")
  {
    rhs.push_back(new Nic{});
  }
  else {
    return 1;
  }
  return 0;
}

int FunctionDeclaration::evaluate(const Token& token)
{
  if (token.value == "funkcja")
  {
    rhs.push_back(new FuncType{});
    rhs.push_back(new ParamList{});
    rhs.push_back(new Identifier{});
    rhs.push_back(new Funkcja{});
    return 0;
  }
  return 1;
}

int ParamList::evaluate(const Token& token)
{
  if (token.value == "(")
  {
    rhs.push_back(new ClosingRound{});
    rhs.push_back(new ParamDecls{});
    rhs.push_back(new OpeningRound{});
    return 0;
  }
  return 1;
}

int ParamDecls::evaluate(const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic")
  {
    rhs.push_back(new ParamDeclsNew{});
    rhs.push_back(new VarDecl{});
  }
  else if (token.value == ")")
  {
    rhs.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int ParamDeclsNew::evaluate(const Token& token)
{
  if (token.value == ")")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == ",")
  {
    rhs.push_back(new ParamDeclsNew{});
    rhs.push_back(new VarDecl{});
    rhs.push_back(new Coma{});
  }
  else {
    return 1;
  }
  return 0;
}

int FuncType::evaluate(const Token& token)
{
  if (token.value == ":")
  {
    rhs.push_back(new Colon{});
    rhs.push_back(new DataType{});
    rhs.push_back(new Colon{});
    return 0;
  }
  return 1;
}

int Body::evaluate(const Token& token)
{
  if (token.value == "{")
  {
    rhs.push_back(new ClosingCurly{});
    rhs.push_back(new Statements{});
    rhs.push_back(new OpeningCurly{});
    return 0;
  }
  return 1;
}

int Statements::evaluate(const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic" ||
        token.type == TYPE::Id || token.value == "przestan" || token.value == "dalej"|| token.value == "zwroc" ||
        token.value == "wywolaj" || token.value == "dopoki" || token.value == "dla" || token.value == "jesli")
  {
    rhs.push_back(new Statements{});
    rhs.push_back(new Statement{});
  }
  else if (token.value == "}")
  {
    rhs.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int Statement::evaluate(const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic")
  {
    rhs.push_back(new Semicolon{});
    rhs.push_back(new VarInit{});
    rhs.push_back(new VarDecl{});
  }
  else if (token.type == TYPE::Id)
  {
    rhs.push_back(new Semicolon{});
    rhs.push_back(new VarInit{});
    rhs.push_back(new Identifier{});
  }
  else if (token.value == "}")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "przestan")
  {
    rhs.push_back(new Semicolon{});
    rhs.push_back(new Przestan{});
  }
  else if (token.value == "dalej")
  {
    rhs.push_back(new Semicolon{});
    rhs.push_back(new Dalej{});
  }
  else if (token.value == "zwroc")
  {
    rhs.push_back(new Semicolon{});
    rhs.push_back(new Expression{});
    rhs.push_back(new Zwroc{});
  }
  else if (token.value == "wywolaj")
  {
    rhs.push_back(new Semicolon{});
    rhs.push_back(new ArgList{});
    rhs.push_back(new Identifier{});
    rhs.push_back(new Wywolaj{});
  }
  else if (token.value == "dopoki")
  {
    rhs.push_back(new Body{});
    rhs.push_back(new Colon{});
    rhs.push_back(new Condition{});
    rhs.push_back(new Dopoki{});
  }
  else if (token.value == "dla")
  {
    rhs.push_back(new Body{});
    rhs.push_back(new Colon{});
    rhs.push_back(new ClosingRound{});
    rhs.push_back(new ForRange{});
    rhs.push_back(new OpeningRound{});
    rhs.push_back(new Zakres{});
    rhs.push_back(new Identifier{});
    rhs.push_back(new Dla{});
  }
  else if (token.value == "jesli")
  {
    rhs.push_back(new ElseClause{});
    rhs.push_back(new Body{});
    rhs.push_back(new Colon{});
    rhs.push_back(new Condition{});
    rhs.push_back(new Jesli{});
  }
  else {
    return 1;
  }
  return 0;
}

int VarInit::evaluate(const Token& token)
{
  if (token.value == ";")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "=")
  {
    rhs.push_back(new Expression{});
    rhs.push_back(new Assign{});
  }
  else {
    return 1;
  }
  return 0;
}

int ForRange::evaluate(const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj" || token.value == "-")
  {
    rhs.push_back(new ForRangeNew{});
    rhs.push_back(new Expression{});
    return 0;
  }
  return 1;
}

int ForRangeNew::evaluate(const Token& token)
{
  if (token.value == ")")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == ",")
  {
    rhs.push_back(new Expression{});
    rhs.push_back(new Coma{});
  }
  else {
    return 1;
  }
  return 0;
}

int ArgList::evaluate(const Token& token)
{
  if (token.value == "(")
  {
    rhs.push_back(new ClosingRound{});
    rhs.push_back(new FuncArgs{});
    rhs.push_back(new OpeningRound{});
  }
  return 0;
}

int FuncArgs::evaluate(const Token& token)
{
  if (token.type == TYPE::Str || token.type == TYPE::Float || token.type == TYPE::Int ||
      token.type == TYPE::Id || token.value == "(" || token.value == "wywolaj")
  {
    rhs.push_back(new FuncArgsNew{});
    rhs.push_back(new Expression{});
  }
  else if (token.value == ")")
  {
    rhs.push_back(new Epsilon{});
  }
  else {
    return 1;
  }
  return 0;
}

int FuncArgsNew::evaluate(const Token& token)
{
  if (token.value == ")")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == ",")
  {
    rhs.push_back(new FuncArgsNew{});
    rhs.push_back(new Expression{});
    rhs.push_back(new Coma{});
  }
  else {
    return 1;
  }
  return 0;
}

int ElseClause::evaluate(const Token& token)
{
  if (token.value == "dycha" || token.value == "przecinek" || token.value == "tekst" || token.value == "nic" ||
        token.type == TYPE::Id || token.value == "}" || token.value == "przestan" || token.value == "dalej" ||
        token.value == "zwroc" || token.value == "wywolaj" || token.value == "dopoki" || token.value == "dla" ||
        token.value == "jesli")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "inaczej")
  {
    rhs.push_back(new Else{});
    rhs.push_back(new Inaczej{});
  }
  else {
    return 1;
  }
  return 0;
}

int Else::evaluate(const Token& token)
{
  if (token.value == ":")
  {
    rhs.push_back(new Body{});
    rhs.push_back(new Colon{});
  }
  else if (token.value == "jesli")
  {
    rhs.push_back(new ElseClause{});
    rhs.push_back(new Body{});
    rhs.push_back(new Colon{});
    rhs.push_back(new Condition{});
    rhs.push_back(new Jesli{});
  }
  else {
    return 1;
  }
  return 0;
}

int Condition::evaluate(const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    rhs.push_back(new ConditionNew{});
    rhs.push_back(new Expression{});
    return 0;
  }
  return 1;
}

int ConditionNew::evaluate(const Token& token)
{
  if (token.value == ":")
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "==" || token.value == "!=" || token.value == ">" || token.value == "<" ||
            token.value == ">=" || token.value == "<=" || token.value == "&" || token.value == "|" )
  {
    rhs.push_back(new ConditionNew{});
    rhs.push_back(new Expression{});
    rhs.push_back(new LogOp{});
  }
  else {
    return 1;
  }
  return 0;
}

int LogOp::evaluate(const Token& token)
{
  if (token.value == "==")
    rhs.push_back(new DoubleEqual{});
  else if (token.value == "!=")
    rhs.push_back(new NotEqual{});
  else if (token.value == ">")
    rhs.push_back(new More{});
  else if (token.value == "<")
    rhs.push_back(new Less{});
  else if (token.value == ">=")
    rhs.push_back(new MoreEqual{});
  else if (token.value == "<=")
    rhs.push_back(new LessEqual{});
  else if (token.value == "&")
    rhs.push_back(new AndOp{});
  else if (token.value == "|")
    rhs.push_back(new OrOp{});
  else 
    return 1;
  return 0;
}

int AddOp::evaluate(const Token& token)
{
  if (token.value == "+")
    rhs.push_back(new Plus{});
  else if (token.value == "-")
    rhs.push_back(new Minus{});
  else 
    return 1;
  return 0;
}

int MulOp::evaluate(const Token& token)
{
  if (token.value == "*")
    rhs.push_back(new Multiply{});
  else if (token.value == "/")
    rhs.push_back(new Divide{});
  else if (token.value == "%")
    rhs.push_back(new Modulo{});
  else 
    return 1;
  return 0;
}

int Expression::evaluate(const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    rhs.push_back(new ExpressionNew{});
    rhs.push_back(new Term{});
  }
  //needed to enable minus constant values
  else if (token.value == "-")
  {
    rhs.push_back(new ExpressionNew{});
    rhs.push_back(new Term{});
    rhs.push_back(new AddOp{});
  }
  else {
    return 1;
  }
  return 0;
}

int ExpressionNew::evaluate(const Token& token)
{
  if (token.value == "==" || token.value == "!=" || token.value == ">" || token.value == "<" || 
      token.value == ">=" || token.value == "<=" || token.value == "&" || token.value == "|" ||
      token.value == ")" || token.value == "," || token.value == ":" || token.value == ";") 
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "+" || token.value == "-")
  {
    rhs.push_back(new ExpressionNew{});
    rhs.push_back(new Term{});
    rhs.push_back(new AddOp{});
  }
  else 
    return 1;
  return 0;
}

int Term::evaluate(const Token& token)
{
  if (token.value == "(" || token.type==TYPE::Int || token.type==TYPE::Float ||
       token.type==TYPE::Str || token.type==TYPE::Id || token.value == "wywolaj")
  {
    rhs.push_back(new TermNew{});
    rhs.push_back(new Factor{});
    return 0;
  }
  return 1;
}

int TermNew::evaluate(const Token& token)
{
  if (token.value == "==" || token.value == "!=" || token.value == ">" || token.value == "<" || 
      token.value == ">=" || token.value == "<=" || token.value == "&" || token.value == "|" ||
      token.value == ")" || token.value == "," || token.value == ":" || token.value == ";" || 
      token.value == "+" || token.value == "-") 
  {
    rhs.push_back(new Epsilon{});
  }
  else if (token.value == "*" || token.value == "/" || token.value == "%")
  {
    rhs.push_back(new TermNew{});
    rhs.push_back(new Factor{});
    rhs.push_back(new MulOp{});
  }
  else {
    return 1;
  }
  return 0;
}

int Factor::evaluate(const Token& token)
{
  if (token.type == TYPE::Id)
  {
    rhs.push_back(new Identifier{});
  }
  else if (token.type == TYPE::Int || token.type == TYPE::Float || token.type == TYPE::Str)
  {
    rhs.push_back(new Constant{});
  }
  else if (token.value == "(")
  {
    rhs.push_back(new ClosingRound{});
    rhs.push_back(new Expression{});
    rhs.push_back(new OpeningRound{});
  }
  else if (token.value == "wywolaj")
  {
    rhs.push_back(new ArgList{});
    rhs.push_back(new Identifier{});
    rhs.push_back(new Wywolaj{});
  }
  return 0;
}

//*** TERMINALS ***
int Zakres::evaluate(const Token& token)
{
  if (token.value == "zakres")
    return 2;
  return 1;
}

int Dycha::evaluate(const Token& token)
{
  if (token.value == "dycha")
    return 2;
  return 1;
}

int Przecinek::evaluate(const Token& token)
{
  if (token.value == "przecinek")
    return 2;
  return 1;
}

int Tekst::evaluate(const Token& token)
{
  if (token.value == "tekst")
    return 2;
  return 1;
}

int Nic::evaluate(const Token& token)
{
  if (token.value == "nic")
    return 2;
  return 1;
}

int Funkcja::evaluate(const Token& token)
{
  if (token.value == "funkcja")
    return 2;
  return 1;
}

int Identifier::evaluate(const Token& token)
{
  if (token.type == TYPE::Id)
  {
    //
    return 2;
  }
  return 1;
}

int Constant::evaluate(const Token& token)
{
  if (token.type == TYPE::Int || token.type == TYPE::Float || token.type == TYPE::Str)
    return 2;
  return 1;
}

int OpeningRound::evaluate(const Token& token)
{
  if (token.value == "(")
    return 2;
  return 1;
}

int ClosingRound::evaluate(const Token& token)
{
  if (token.value == ")")
    return 2;
  return 1;
}

int Coma::evaluate(const Token& token)
{
  if (token.value == ",")
    return 2;
  return 1;
}

int Colon::evaluate(const Token& token)
{
  if (token.value == ":")
    return 2;
  return 1;
}

int Semicolon::evaluate(const Token& token)
{
  if (token.value == ";")
    return 2;
  return 1;
}

int OpeningCurly::evaluate(const Token& token)
{
  if (token.value == "{")
    return 2;
  return 1;
}

int ClosingCurly::evaluate(const Token& token)
{
  if (token.value == "}")
    return 2;
  return 1;
}

int OpeningSquare::evaluate(const Token& token)
{
  if (token.value == "[")
    return 2;
  return 1;
}

int ClosingSquare::evaluate(const Token& token)
{
  if (token.value == "]")
    return 2;
  return 1;
}

int Przestan::evaluate(const Token& token)
{
  if (token.value == "przestan")
    return 2;
  return 1;
}

int Dalej::evaluate(const Token& token)
{
  if (token.value == "dalej")
    return 2;
  return 1;
}

int Zwroc::evaluate(const Token& token)
{
  if (token.value == "zwroc")
    return 2;
  return 1;
}

int Wywolaj::evaluate(const Token& token)
{
  if (token.value == "wywolaj")
    return 2;
  return 1;
}

int Dopoki::evaluate(const Token& token)
{
  if (token.value == "dopoki")
    return 2;
  return 1;
}

int Dla::evaluate(const Token& token)
{
  if (token.value == "dla")
    return 2;
  return 1;
}

int Jesli::evaluate(const Token& token)
{
  if (token.value == "jesli")
    return 2;
  return 1;
}

int Assign::evaluate(const Token& token)
{
  if (token.value == "=")
    return 2;
  return 1;
}

int Inaczej::evaluate(const Token& token)
{
  if (token.value == "inaczej")
    return 2;
  return 1;
}

int DoubleEqual::evaluate(const Token& token)
{
  if (token.value == "==")
    return 2;
  return 1;
}

int NotEqual::evaluate(const Token& token)
{
  if (token.value == "!=")
    return 2;
  return 1;
}

int More::evaluate(const Token& token)
{
  if (token.value == ">")
    return 2;
  return 1;
}

int Less::evaluate(const Token& token)
{
  if (token.value == "<")
    return 2;
  return 1;
}

int MoreEqual::evaluate(const Token& token)
{
  if (token.value == ">=")
    return 2;
  return 1;
}

int LessEqual::evaluate(const Token& token)
{
  if (token.value == "<=")
    return 2;
  return 1;
}

int AndOp::evaluate(const Token& token)
{
  if (token.value == "&")
    return 2;
  return 1;
}

int OrOp::evaluate(const Token& token)
{
  if (token.value == "|")
    return 2;
  return 1;
}

int Plus::evaluate(const Token& token)
{
  if (token.value == "+")
    return 2;
  return 1;
}

int Minus::evaluate(const Token& token)
{
  if (token.value == "-")
    return 2;
  return 1;
}

int Multiply::evaluate(const Token& token)
{
  if (token.value == "*")
    return 2;
  return 1;
}

int Divide::evaluate(const Token& token)
{
  if (token.value == "/")
    return 2;
  return 1;
}

int Modulo::evaluate(const Token &token)
{
  if (token.value == "%")
    return 2;
  return 0;
}

int End::evaluate(const Token& token)
{
  if (token.value == "$")
    return 2;
  return 1;
}

//todo -> do I even need this symbol???
int Error::evaluate(const Token& token)
{
  if (token.value == "zakres")
    return 2;
  return 1;
}

int Epsilon::evaluate(const Token& token)
{
  return 0;
}

int Globalne::evaluate(const Token& token)
{
  if (token.value == "globalne")
    return 2;
  return 1;
}

int Dodaj::evaluate(const Token& token)
{
  if (token.value == "dodaj")
    return 2;
  return 1;
}

