#include "Ndarray.h"
#include "Ndarray.cpp"
#include "NDInitializer.cpp"

int main()
{
	Ndarray a = Ndarray::arange(16);
	a.print();
	//~ Ndarray b=a.reshape({2,2,2,2});
	//~ b.print();
	//~ a.print();
	
	Ndarray b = Ndarray::array({{{1, 2},{2,5}},{{0,5},{3, 7}},{{2,5},{3, 4}}});
    b.print();
	
	return 0;
}
