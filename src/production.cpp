#include "../inc/production.h"

//tables needed for lexer
std::vector<char> operators = {'=','+','-','*','/','&','|','>','<', '!'};
std::vector<char> separators = {';','[',']','{','}',':','(',')',','};
std::vector<std::string> keywords = {"funkcja" ,"nic","dycha", "przecinek", "tekst","wywolaj", 
		"przestań","dalej","jesli", "inaczej", "dopoki","dla", "liga", "zwroc", "do", 
		"zakres", "dodaj", "globalne"};

std::unordered_map<std::string, std::string> keyword_map = {
  std::pair{"dycha", "int"},
  std::pair{"przecinek", "float"},
  std::pair{"tekst", "std::string"},
  std::pair{"nic", "void"},
  std::pair{"przestan", "break"},
  std::pair{"dalej", "continue"},
  std::pair{"zwroc", "return"},
  std::pair{"dodaj", "include"},
	std::pair{"na_tekst", "std::to_string"}
	//reconsider adding some more function calls
};
