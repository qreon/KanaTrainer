#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "drawer.hpp"
#include "category.hpp"
#include "pool.hpp"

using namespace std;

int askNumber();

Drawer::Drawer()
{
	p = new Pool();
}

Drawer::~Drawer()
{

}

void Drawer::addSeries(int n)
{
	if (n <= (int)cat.size() && n > 0)
	{
		if (series.count(n) == 0)
		{
			series.insert(n);
			cout << "Series " << n << " successfully added!" << endl;
		}
		else
		{
			series.erase(n);
			cout << "Series " << n << " successfully removed!" << endl;
		}
	}
	else
	{
		cout << "That series doesn't exist. Please pick another one." << endl;
	}
}

void Drawer::addCategory(Category* c)
{
	cat.push_back(c);
}

int Drawer::countCategories()
{
	return cat.size();
}

int Drawer::countSeries()
{
	return series.size();
}

Category* Drawer::get(int n)
{
	return cat[n];
}

void Drawer::start()
{
	if (series.size() == 0)
	{
		cout << "You shall select one or several series before beginning practicing." << endl;
	}
	else
	{
		int drawCount = askNumber();
		fillPool();
		
		cout << endl;
		for (int i = 0; i < drawCount; i++)
		{
			cout << setw(5) << p->getRandom();
		}
		cout << endl << endl;
		cout << "Done!";
		cin.get();
		series.clear();
		cout << endl << endl;
		menu();
	}
}

void Drawer::fillPool()
{
	for (int i = 0; i < (int)cat.size(); i++)
	{
		if (series.count(i + 1) != 0)
		{
			string s;
			do
			{
				s = cat[i]->getNext();
				if (!s.empty())
				{
					p->add(s);
				}
			} while (!s.empty());
		}
	}
}

void Drawer::displayContent()
{
	for (int i = 0; i < (int)cat.size(); i++)
	{
		cout << cat[i];
	}
}

void Drawer::menu()
{
	cout << "Series available :" << endl;

	for (int i = 0; i < (int)cat.size(); i++)
	{
		cout << " " << i + 1 << ".\t" << cat[i]->bracketName() << endl;
	}

	cout << endl;

	cout << "Type the number of a series to add it to the practicing list." << endl;
	cout << "Type 's' or 'start' to begin practicing." << endl;
	cout << "Type 'h' or 'help' to display some help." << endl;
	cout << "Type 'd' or 'disp' to display the content of the series." << endl;
	cout << "Type 'e' or 'exit' to close the program." << endl;
}

int askNumber()
{
	string s;
	bool cont = true;

	do
	{
		cout << "How many ideograms do you wish to draw ? ";
		getline(cin, s);

		int n;
		stringstream toInt(s);

		if (!(toInt >> n))	//Dirty str -> int cast
		{	//If fail
			cout << "Please enter a number." << endl;
		}
		else
		{	//If success
			if (!(n > 0 && n < 2000))
			{
				cout << "Please enter a number over 0 and below 2000." << endl;
			}
			else
			{
				cont = false;
				return n;
			}
		}
	} while (cont);
}
