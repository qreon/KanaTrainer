#include <iostream>
#include <vector>
#include <string>

#include "parser.hpp"
#include "category.hpp"
#include "prompt.hpp"

using namespace std;

int main(int argc, char** argv)
{
	Parser* p = new Parser("hiragana.txt");
	Prompt* prompt;
	Drawer* d = new Drawer();
	Category* c;

	while (c = p->getCategory())
	{
		d->addCategory(c);
	}

	prompt = new Prompt(d);

	cout << "Welcome to KanaTrainer !" << endl << endl;

	d->menu();

	prompt->run();

	cin.get();

	return 0;
}