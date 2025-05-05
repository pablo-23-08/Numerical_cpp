//~ #include "Module_np.h"
Ndarray Module_np::arange(size_t n)const
{
	return Ndarray::arange(n);
}

Ndarray Module_np::array(std::initializer_list<NDInitializer>list)const
{
	return Ndarray::array(list);
}
