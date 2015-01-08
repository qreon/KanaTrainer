#include <cstdlib>
#include <ctime>

#include "pool.hpp"

Pool::Pool()
{
	srand(time(NULL));
}

Pool::~Pool()
{

}

void Pool::add(std::string s)
{
	ideograms.push_back(s);
	max = ideograms.size();
}

std::string Pool::getRandom()
{
	int ran = rand() % max;
	return ideograms[ran];
}
