#include "category.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

Category::Category(string name, vector<string> cont)
{
	this->name = name;
	index = 0;
	contents.clear();
	fill(cont);
}

Category::~Category()
{

}



void Category::addContent(string content)
{
	contents.push_back(content);
}

void Category::fill(vector<string>& cont)
{
	contents.clear();
	for(unsigned int i = 0 ; i < cont.size() ; i++)
	{
		contents.push_back(cont[i]);
	}
}



string Category::getName()
{
	return name;
}

string Category::bracketName()
{
	return "[ " + name + " ]";
}

string Category::getFirst()
{
	index = 0;
	return getNext();
}

string Category::getNext()
{
	if (index < (int)contents.size())
	{
		return contents[index++];
	}
	else
	{
		return "";
	}
}

int Category::count()
{
	return contents.size();
}

string Category::toString()
{
	stringstream res;
	res << setw(12) << bracketName();
	for(int i = 0; i < count(); i++)
	{
		res << setw(5) << contents[i];
	}
	res << std::endl;
	return res.str();
}



ostream& operator<<(std::ostream& os, Category c)
{
	os << c.toString();
	return os;
}

ostream& operator<<(std::ostream& os, Category* c)
{
	os << c->toString();
	return os;
}

ostream& Category::endl(ostream & os)
{
	return os << '\n';
}