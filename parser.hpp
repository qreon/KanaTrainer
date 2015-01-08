#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <string>

#include "category.hpp"

class Parser
{
	private:
		std::ifstream file;

		std::string extractName();
		std::vector<std::string> extractContents();
		Category* buildCategory();

	public:
		Parser(std::string name);
		~Parser();

		Category* getCategory();
};

#endif //PARSER_HPP
