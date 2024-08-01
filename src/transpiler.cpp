#include "../inc/transpiler.h"
#include <sstream>

//this solution allows to properly resolve transpiling
// function declaration but is not the most elegent one
// it would be good to reconsider solution
bool function_decl = false;
int function_decl_colons = 0;
std::deque<std::string> function_decl_record;

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

//helper functtion for processing function declarations
void processFunctionRecord(std::ostringstream& ss, std::deque<std::string>& func_record)
{
  std::string return_type = func_record.back();
  func_record.pop_back();
  func_record.push_front(return_type);
  for (const auto& node_val : func_record)
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
  func_record.clear();
}


void transpiler_rec(std::ostringstream& ss, Symbol *head)
{
  //if node is down node with value
  std::string node_val = head->getValue();
  if (node_val != "")
  {
    //set flag to true to start recording 
    if (node_val=="funkcja")
    {
      function_decl = true;
      return;
    }
    if (function_decl)
    {
      std::cout << "[DEBUG] node_val: " << node_val << std::endl;
      if (node_val != ":")
      {
        function_decl_record.push_back(node_val);
        return;
      }
      function_decl_colons++;
      if (function_decl_colons == 2)
      {
        std::cout << "[DEBUG]I am about to reset function_decl flag..." << std::endl;
        function_decl_colons = 0;
        function_decl = false;
        processFunctionRecord(ss, function_decl_record);
      }
      return;
    }
    if (search(common_signs, node_val))
    {
      ss << node_val << " ";
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
    transpiler_rec(ss, head->getRhsNode(i));
  }
} 

void transpiler(const char* file_name, Symbol* head)
{
  std::ostringstream ss;
  transpiler_rec(ss, head);
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