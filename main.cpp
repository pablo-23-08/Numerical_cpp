#include "Ndarray.h"
#include "Ndarray.cpp"
#include "NDInitializer.cpp"
#include "Module_np.h"
#include "Module_np.cpp"

int main()
{
	Ndarray a=np.arange(16);
	a.print();
	a.shape();
	
	Ndarray b=a.reshape({2,2,2,2});
	b.print();
	b.shape();
	
	b=np.arange(24).reshape({1,2,3,4});
	b.print();
	b.shape();
	
	Ndarray c=np.array({{{1,2},{2,5}},{{0,5},{3,7}},{{2,5},{3,4}}});
    c.print();
	c.shape();
	
	return 0;
}
