#include <iostream>
#include <string>
#include <sstream>
#include <set>

#include "prompt.hpp"

using namespace std;

Prompt::Prompt(Drawer* d)
{
	this->d = d;
}

Prompt::~Prompt()
{

}

void Prompt::run()
{
	string in;
	do
	{
		cout << endl;
		cout << "> ";
		getline(cin, in);
	} while (parse(in));
}

bool Prompt::parse(string in)
{
	int n;
	stringstream toInt(in);

	if (!(toInt >> n))	//Dirty str -> int cast
	{	//If fail
		return processAlpha(in);
	}
	else
	{	//If success
		processNum(n);
		return true;
	}
}

void Prompt::processNum(int n)
{
	d->addSeries(n);
}

bool Prompt::processAlpha(string s)
{
	if (s == "s" || s == "start")
	{
		d->start();
		return true;
	}
	if (s == "h" || s == "help")
	{
		displayHelp();
		return true;
	}
	if (s == "e" || s == "exit")
	{
		cout << "See you next time !";
		return false;
	}
	if (s == "d" || s == "disp")
	{
		d->displayContent();
		return true;
	}
	else
	{
		cout << "Unknown option '" << s << "'. Please try again." << endl;
		return true;
	}
}

void Prompt::displayHelp()
{
	cout << "Select a series by typing its number in the prompt. When you are ready, type 's' or 'start'." << endl;
	cout << "You will be asked the number of ideograms you want to draw." << endl;
	cout << "Then, the number of ideograms you asked for will be displayed in romaji, randomly picked in the series you selected in the previous step." << endl;
	cout << "You can now practice by drawing hiragana or katakana on a piece of paper." << endl;
}