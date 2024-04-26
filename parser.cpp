#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//have to use some kind of data socket to pass created tokens into a parser
using std::string, std::vector, std::cout, std::cin, std::endl, std::find;

enum TYPE {
	op,
	sep,
	id,
	con,
	key,
	lit
};

string typeToString(TYPE type)
{
	switch(type)
	{
		case TYPE::op: return "op";
		case TYPE::sep: return "sep";
		case TYPE::id: return "id";
		case TYPE::con: return "con";
		case TYPE::key: return "key";
		case TYPE::lit: return "lit";
		default: return "";
	}
}

class Token {
	TYPE type;
	string value;
public:
	Token (TYPE _type):type(_type){}
	Token (TYPE _type, string val):type(_type),value(val){}	
	virtual void printToken() const 
	{
		cout << "[ " << typeToString(type) << " : " << value << " ]" << endl;
	}
};

template<typename T>
class Con : public Token {
	T value;
public:
	Con (T val):Token(TYPE::con),value(val){}
	void printToken() const override
	{
		cout << "[ con" << " : " << value << " ]" << endl;
	}
};

int main()
{

	return 0;
}
