#include "../inc/transpiler.h"

std::vector<Identifier> global_ids;
std::vector<Identifier> local_ids;

Identifier::Identifier(std::string _name, bool _is_func):name(_name),function_id(_is_func)
{}

bool Identifier::operator==(const Identifier& id) const 
{
	return this->name == id.name;
}

bool Identifier::is_ID_Function()
{
	return function_id;
}

const std::string Identifier::getName() const 
{
	return name;
}

//no need for this function, can use function called vector_search from lex.h
bool id_Status(const vector<Identifier>& vec, const Identifier& id)
{
	return (std::find(vec.begin(), vec.end(), id)!=vec.end());
}

