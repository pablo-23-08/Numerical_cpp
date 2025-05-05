//~ #include <iostream>
#include <vector>
#include <initializer_list>

class NDInitializer
{
	public:
		NDInitializer(std::initializer_list<double>list);
		NDInitializer(std::initializer_list<NDInitializer>list);
		std::vector<double>data;
		std::vector<size_t>form;
};
