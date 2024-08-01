#include "../inc/transpiller.h"


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
                                  /*   1  ,     2     ,   3   ,  4  ,    5    ,  6 ,   7   , 8 , 9 , 10, 11, 12, 13, 14,    15    ,   16  ,  17   ,    18   ,   19   , 20  ,   21  , 22,   23    , 24 , 25 , 26, 27, 28 , 29 , 30, 31, 32, 33, 34, 35,  36,   37    ,  38   ,   39     */
//vector<std::string> terminals = {"dycha","przecinek","tekst","nic","funkcja","id","const","(",")",",",":",";","{","}","przestan","dalej","zwroc","wywolaj","dopoki","dla","jesli","=","inaczej","==","!=",">","<",">=","<=","&","|","+","-","*","/", "$", "zakres","dodaj","globalne"};


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