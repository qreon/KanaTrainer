#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>

#include "drawer.hpp"

class Prompt
{
	private:
		Drawer* d;

		bool parse(std::string in);
		void processNum(int n);
		bool processAlpha(std::string s);
		void displayHelp();

	public:
		Prompt(Drawer* d);
		~Prompt();

		void run();
};

#endif //PROMPT_HPP