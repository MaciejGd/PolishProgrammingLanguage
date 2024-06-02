#pragma once 
#include "parser.h"

class Identifier {
	std::string name;
	bool function_id;
public:
	Identifier(std::string name, bool _is_func);
	bool operator==(const Identifier& id) const;
	bool is_ID_Function();
	const std::string getName() const;
};

bool id_found(const vector<Identifier>& vec, const Identifier& id);


void translate();
