#pragma once
#include <fstream>
#include <sstream>
#include "lex.h"

#include "grammar.h"

class Parser {
  Symbol* head;
  std::string file_name;
  int m_rec_parse(Symbol* head, const std::vector<Token>& tokens, int &counter);
  int m_parse(const std::vector<Token>& tokens);
  void m_chopTree(Symbol *head);
public:
  Parser(const std::string& file_name, const std::vector<Token>& tokens);
  ~Parser();
  const Symbol* getHead() const { return head; };
};

//debug purposes -> to show ast in a file
void printRec(std::ostringstream& ss, const Symbol* head, int incantation);
void printAST( const char* file_arg, const Symbol* head);

