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
	a.size();
	
	Ndarray b=a.reshape({2,2,2,2});
	b.print();
	b.shape();
	b.size();
	
	b=np.arange(24).reshape({1,2,3,4});
	b.print();
	b.shape();
	b.size();
	
	Ndarray c=np.array({{{1,2},{2,5}},{{0,5},{3,7}},{{2,5},{3,4}}});
    c.print();
	c.shape();
	c.size();
	
	//Utilisation de la méthode zeros
	Ndarray d=np.zeros({2,3});
	std::cout<<"Tableau de zéros:"<<std::endl;
	d.print();
	d.shape();
	d.size();
	
	//Utilisation de la méthode ones
	Ndarray e=np.ones({2,2,3});
	std::cout<<"Tableau de ones 3D:"<<std::endl;
	e.print();
	e.shape();
	e.size();
	
	//Addition de tableaux
	Ndarray m1=np.array({{1,2},{3,4}});
	Ndarray m2=np.array({{5,6},{7,8}});
	Ndarray m3=np.array({{5,6},{7,8}});
	(m1+m2+m3).print();
	
	//Soustraction de tableaux
	Ndarray m4=np.array({{1,2},{3,4}});
	Ndarray m5=np.array({{5,6},{7,8}});
	Ndarray m6=np.array({{5,6},{7,8}});
	(m4-m5-m6).print();
	
	//Multiplication de tableaux
	Ndarray m7=np.array({{1,2},{3,4}});
	Ndarray m8=np.array({{5,6},{7,8}});
	Ndarray m9=np.array({{5,6},{7,8}});
	(m7*m8*m9).print();
	
	//division de tableaux
	Ndarray m10=np.array({{20,2},{3,4}});
	Ndarray m11=np.array({{5,6},{7,8}});
	Ndarray m12=np.array({{5,0},{7,8}});
	(m10/m11/m12).print();
		
	return 0;
}

