#ifndef LEXER
#define LEXER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "production.h"


//token types
enum TYPE {Op, Sep, Id, Str, Int, Float, Bool, Key, Lit};
//for debug purposes
std::string typeToString(TYPE type);

struct Token {
	TYPE type;
	std::string value;
	//informing in case of error
	int line;
	Token (TYPE _type, std::string _val, int _line):type(_type),value(_val),line(_line){};
	Token (TYPE _type, std::string _val):Token(_type, _val, 0){};
	inline void printToken() const
	{	
		std::cout << "[ " << typeToString(type) << " ," << value << " ]\n"; 
	};
};

class Lexer {
	std::vector<Token> tokens;
	std::string file_name;

	void m_tokensScan();
	void m_divideToWords(int line_counter, const std::string& line, std::vector<std::string>& words);
	void m_divideToWords(int line_counter, const std::string& line);
	Token m_createToken(int line_counter, const std::string& lexeme);
	void m_createTokens(const std::vector<std::string>& lexemes);
	int m_isConstant(const std::string& lexem);
public:
	Lexer(std::string _file);
	inline const std::vector<Token> getTokens() const { return tokens; };
};

#endif