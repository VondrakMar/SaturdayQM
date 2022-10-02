#include <iostream>
#include <math.h>
#include <string>
#include <my_math.hpp>
using namespace std;


class Atom {
  public:     
	int el;
    float x;        
    float v_x;

	Atom(int aEl, float aX, float aV_x){
		el = aEl;
		x = aX;
		v_x = aV_x;
	}
};

float LJ_potential(Atom& atom1, Atom& atom2, float epsilon, float sigma)
{
	float dist = sqrt(pow(atom1.x - atom2.x,2));
	float energy = 4*epsilon*(pow(sigma/dist,12)-pow(sigma/dist,6));
	float force = 48*epsilon*(pow(sigma,12)/pow(dist,13)-0.5*pow(sigma,6)/pow(dist,7));
	return energy;
}

void verlet(Atom atom1, float vel, float dt = 0.1)
{
	int step = 0;
	float pred_x = atom1.x - 0.1;
	float force=2.0;
	float xx;
	float vi;

	while (step < 10){
		cout << atom1.x << endl;
		force = 1.0;
		xx = 2*atom1.x - pred_x + dt*dt*2*force;
		vi = (xx-pred_x)/(2*dt);
		pred_x = atom1.x;
		atom1.x = xx;
		step++;
	}
	
}

int main()
{
	Atom atom1(1, 1.2,0);
	verlet(atom1,1.2,0.1);
	return 0;
}


