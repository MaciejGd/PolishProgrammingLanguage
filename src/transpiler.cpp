#include "../inc/transpiler.h"

void addNewLine(std::ostringstream &ss, const std::string &sign)
{
  if (sign == ";" || sign == "{" || sign == "}")
  {
    ss << "\n";
  }
}



void Transpiler::m_transpiler_rec(Symbol *head)
{
  //if node is down node with value
  std::string node_val = head->getValue();
  if (node_val != "")
  {
    //set flag to true to start recording 
    if (m_handler && m_handler->isActive())
    {
      m_handler->analyze(ss, node_val);
      return;
    }
    if (node_val=="funkcja")
    {
      m_handler.reset(new FunctionHandler{});
      return;
    }
    
    if (search(common_signs, node_val))
    {
      ss << node_val << " ";
      addNewLine(ss, node_val);
      return;
    }
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      return;
    }
    if (node_val == "$")
    {
      return;
    }
    ss << node_val << " ";
  }
  //else go down from right to left in rhs
  for (int i = head->getRhsSize() - 1; i >= 0; i--)
  {
    m_transpiler_rec(head->getRhsNode(i));
  }
} 

void Transpiler::transpiler(const char* file_name, Symbol* head)
{
  m_transpiler_rec(head);
  //todo open a file and place a string stream
  std::fstream file(file_name, std::ios::out);
  if (file.fail())
  {
    std::cout << "[ERROR]Could not open a file: " << file_name << " in function transpiler in transpiler.cpp\n";
    return;
  }
  file << ss.str();
  ss.clear();
  file.close();
}

void Transpiler::chooseHandler(const std::string& node_val)
{
  // if (node_val == "funkcja")
  // {
  //   m_handler.reset(new FunctionHandler{});
  // }
  // else if (node_val == "dla")
  // {
  //   m_handler.reset(new ForHandler{});
  //   ss << "for";
  // }
  // else if (node_val == "dopoki")
  // {
  //   m_handler.reset(new WhileHandler{});
  //   ss << "while";
  // }
  // else if (node_val == "jesli")
  // {
  //   m_handler.reset(new IfHandler{});
  //   ss << "if";
  //   ss << "(";
  // }
  // else if (node_val == "inaczej") 
  // {
  //   m_handler.reset(new IfHandler);
  // }
}




// std::unordered_map<string, Symbol> terminals_map = {
// 	{"zakres", ZAKRES},
// 	{"dycha", DYCHA},
// 	{"przecinek", PRZECINEK},
// 	{"tekst", TEKST},
// 	{"nic", NIC},
// 	{"funkcja", FUNKCJA},
// 	{"id", IDENTIFIER},
// 	{"const", CONSTANT},
// 	{"(", OPENING_ROUND},
// 	{")", CLOSING_ROUND},
// 	{",", COMA},
// 	{":", COLON},
// 	{";", SEMICOLON},
// 	{"{", OPENING_CURLY},
// 	{"}", CLOSING_CURLY},
// 	{"przestan", PRZESTAN},
// 	{"dalej", DALEJ},
// 	{"zwroc", ZWROC},
// 	{"wywolaj", WYWOLAJ},
// 	{"dopoki", DOPOKI},
// 	{"dla", DLA},
// 	{"jesli", JESLI},
// 	{"=", ASSIGN},
// 	{"inaczej", INACZEJ},
// 	{"==", DOUBLE_EQUAL},
// 	{"!=", NOT_EQUAL},
// 	{">", MORE},
// 	{"<", LESS},
// 	{">=", MORE_EQUAL},
// 	{"<=", LESS_EQUAL},
// 	{"&", AND_OP},
// 	{"|", OR_OP},
// 	{"+", PLUS},
// 	{"-", MINUS},
// 	{"*", MULTIPLY},
// 	{"/", DIVIDE},
// 	{"$", END},
// 	{"dodaj", DODAJ},
// 	{"globalne", GLOBALNE}
// };