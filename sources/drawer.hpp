#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <set>
#include <vector>

#include "category.hpp"
#include "pool.hpp"
class Drawer
{
	private:
		std::vector<Category*> cat;
		std::set<int> series;
		Pool* p;

		void fillPool();

	public:
		Drawer();
		~Drawer();

		void addSeries(int n);
		void addCategory(Category* c);
		int countCategories();
		int countSeries();
		void displayContent();
		Category* get(int i);
		void menu();

		void start();
};

#endif //DRAWER_HPP