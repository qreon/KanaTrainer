#ifndef POOL_HPP
#define POOL_HPP

#include <vector>
#include <string>

class Pool
{
	private:
		std::vector<std::string> ideograms;
		int max;

	public:
		Pool();
		~Pool();

		void add(std::string s);
		std::string getRandom();
};

#endif //POOL_HPP