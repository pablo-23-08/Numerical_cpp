#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <limits>
#include "NDInitializer.h"

class Ndarray
{
	private:
		std::vector<double>data;
		std::vector<size_t>form;
		size_t total_size;
		
		size_t get_index(const std::vector<size_t>& indices)const;
		void print_array(size_t offset, size_t dim, size_t indent, size_t width)const;
		size_t get_max_width()const;

	public:
		Ndarray(const std::vector<size_t>& dimensions);
		static Ndarray arange(int size);
		static Ndarray array(const NDInitializer& init);
		static Ndarray zeros(const std::vector<size_t>& dimensions);
		static Ndarray ones(const std::vector<size_t>& dimensions);
		Ndarray reshape(const std::vector<size_t>& new_form)const;
		void print()const;
		void shape()const;
		void size()const;
		Ndarray operator+(const Ndarray& other)const;
		Ndarray operator-(const Ndarray& other)const;
		Ndarray operator*(const Ndarray& other)const;
		Ndarray operator/(const Ndarray& other)const;
		
};
