//~ #include "Module_np.h"
Ndarray Module_np::arange(size_t n)const
{
	return Ndarray::arange(n);
}

Ndarray Module_np::array(std::initializer_list<double>list)const
{
	NDInitializer init(list);
	return Ndarray::array(init);
}

Ndarray Module_np::array(std::initializer_list<NDInitializer>list)const
{
	return Ndarray::array(list);
}

Ndarray Module_np::zeros(const std::vector<size_t>& dimensions)const
{
	return Ndarray::zeros(dimensions);
}

Ndarray Module_np::ones(const std::vector<size_t>& dimensions)const
{
	return Ndarray::ones(dimensions);
}
