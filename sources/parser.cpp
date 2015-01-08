#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "parser.hpp"
#include "category.hpp"

using namespace std;

vector<string>& split(const string& s, char delim, vector<string>& elems);
vector<string> split(const string &s, char delim);

Parser::Parser(string name)
{
	file.open(name.c_str());
}

Parser::~Parser()
{

}

Category* Parser::getCategory()
{
	return buildCategory();
}



string Parser::extractName()
{
	string line;
	getline(file, line,']');
	if (line.empty())
	{
		return "";
	}

	return line.substr(1);
}

vector<string> Parser::extractContents()
{
	string line("");
	vector<string> res;
	getline(file, line, '\n');
	while (line.find("[end]") == string::npos)
	{
		if(!line.empty())
		{
			res.push_back(line);
		}
		getline(file, line, '\n');
	}

	return res;
}

Category* Parser::buildCategory()
{
	string n = extractName();
	if (n.empty())
	{
		return nullptr;
	}

	vector<string> v = extractContents();
	
	Category* c = new Category(n, v);

	return c;
}



vector<string>& split(const string& s, char delim, vector<string>& elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
