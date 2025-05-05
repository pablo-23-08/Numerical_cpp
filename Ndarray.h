#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
//~ #include <initializer_list>
#include "NDInitializer.h"

class Ndarray
{
	private:
		std::vector<double> data;
		std::vector<size_t> shape;
		size_t total_size;
		
		size_t get_index(const std::vector<size_t>& indices)const;
		void print_array(size_t offset, size_t dim, size_t indent, size_t width)const;
		size_t get_max_width()const;

	public:
		Ndarray(const std::vector<size_t>& dimensions);
		static Ndarray arange(int size);
		Ndarray reshape(const std::vector<size_t>& new_shape)const;
		void print()const;
		static Ndarray array(const NDInitializer& init);
		//~ static Ndarray array(std::initializer_list<std::initializer_list<double>> values);
		//~ static Ndarray array(std::initializer_list<std::initializer_list<std::initializer_list<double>>> values);
		//~ template<typename T>
		//~ static Ndarray array(std::initializer_list<T> values);

};
