#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

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
};
