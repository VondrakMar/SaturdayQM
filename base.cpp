#include <iostream>
#include <math.h>
#include <string>

#include <MD.hpp>
using namespace std;


int main()
{
	
	
	Atom atom1(1, 2.2, 1.0, 1.3, 0.2, 0.5, -0.1);
	cout << atom1.y << endl;
	Atom molecule[3] =
	{	
		{1, 2.2, 1.0, 1.3, 0.2, 0.5, -0.1},
		{1, 0.2, -1.0, -1.2, 0.5, -0.1, 0.2},
		{1, 0.5, 0.5, 1.2, -0.1, -0.2,-0.1},
	};
	int ii = 0;
	print_coord(molecule,3);
	while (ii < 10)
	{
		cout  << "3" << endl << "step " << ii << endl;
		verlet_system(molecule, 3);
		print_coord(molecule, 3);
		ii++;
	}
	
	/*
	for (int i = 0; i < 3; i++)
	{
		cout << molecule[i].z << endl;
	}
	//Atom atom1(1, 1.2,0);
	// verlet(atom1,1.2,0.1);
	*/
	return 0;
}


