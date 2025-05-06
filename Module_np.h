//~ #include "Ndarray.h"
//~ #include "NDInitializer.h"

class Module_np
{
	public:
		Ndarray arange(size_t n)const;
		Ndarray array(std::initializer_list<double>list)const;
		Ndarray array(std::initializer_list<NDInitializer>list)const;
		Ndarray zeros(const std::vector<size_t>& dimensions)const;
		Ndarray ones(const std::vector<size_t>& dimensions)const;
};

const Module_np np;//déclaration globale d'un objet np 
