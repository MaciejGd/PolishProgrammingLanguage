#include "../inc/transpiler.h"
#include <sstream>


std::vector<std::string> common_signs = {"(",")",",",":",";","{","}","==","!=",">","<",">=","<=","&","|","+","-","*","/", "="};
//dollar sign should be skipped!!!!
std::unordered_map<std::string, std::string> keyword_map = {
  std::pair{"dycha", "int"},
  std::pair{"przecinek", "float"},
  std::pair{"tekst", "std::string"},
  std::pair{"nic", "void"},
  std::pair{"przestan", "break"},
  std::pair{"dalej", "continue"},
  std::pair{"zwroc", "return"},
  std::pair{"dodaj", "include"} 
};
//******* reference *******
                                  /*   1  ,     2     ,   3   ,  4  ,    5    ,  6 ,   7   , 8 , 9 , 10, 11, 12, 13, 14,    15    ,   16  ,  17   ,    18   ,   19   , 20  ,   21  , 22,   23    , 24 , 25 , 26, 27, 28 , 29 , 30, 31, 32, 33, 34, 35,  36,   37    ,  38   ,   39     */
//vector<std::string> terminals = {"dycha","przecinek","tekst","nic","funkcja","id","const","(",")",",",":",";","{","}","przestan","dalej","zwroc","wywolaj","dopoki","dla","jesli","=","inaczej","==","!=",">","<",">=","<=","&","|","+","-","*","/", "$", "zakres","dodaj","globalne"};
//*************************
void addNewLine(std::ostringstream &ss, const std::string &sign)
{
  if (sign == ";" || sign == "{" || sign == "}")
  {
    ss << "\n";
  }
}

void FunctionHandler::processRecord(std::ostringstream& ss) 
{
  std::string return_type = p_record.back();
  p_record.pop_back();
  p_record.push_front(return_type);
  for (const auto& node_val : p_record)
  {
    if (search(common_signs, node_val))
    {
      ss << node_val << " ";
      continue;
    }
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      continue;
    }
    ss << node_val << " ";
  }
  ss << "\n";
  p_record.clear();
}

void Transpiler::m_transpiler_rec(std::ostringstream& ss, Symbol *head)
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
    m_transpiler_rec(ss, head->getRhsNode(i));
  }
} 

void Transpiler::transpiler(const char* file_name, Symbol* head)
{
  std::ostringstream ss;
  m_transpiler_rec(ss, head);
  //todo open a file and place a string stream
  std::fstream file(file_name, std::ios::out);
  if (file.fail())
  {
    std::cout << "[ERROR]Could not open a file: " << file_name << " in function transpiler in transpiler.cpp\n";
    return;
  }
  file << ss.str();
  file.close();
}

void FunctionHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{
  std::cout << "[DEBUG] node_val: " << node_val << std::endl;
  if (node_val != ":")
  {
    p_record.push_back(node_val);
    return;
  }
  m_colons++;
  std::cout << "Colons: " << m_colons << std::endl;
  if (m_colons == 2)
  {
    processRecord(ss);
    m_colons = 0;
    p_active = 0;   
  }
  return;
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