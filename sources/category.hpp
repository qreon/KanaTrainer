#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <iostream>
#include <string>
#include <vector>

class Category
{
	private:
		std::string name;
		std::vector<std::string> contents;
		int index;
		
		std::string toString();
		friend std::ostream& operator<<(std::ostream& os, Category c);
		friend std::ostream& operator<<(std::ostream& os, Category* c);
		std::ostream& endl(std::ostream & os);

	public:
		Category(std::string name, std::vector<std::string> cont);
		~Category();

		void addContent(std::string content);
		void fill(std::vector<std::string>& cont);

		std::string getName();
		std::string bracketName();
		std::string getFirst();
		std::string getNext();
		int count();
};

#endif //CATEGORY_HPP
