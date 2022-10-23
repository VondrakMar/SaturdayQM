#include <iostream>
#include <math.h>
#include <string>
using namespace std;


class Atom {
  public:     
	int el;
    float x, y, z;        
    float v_x, v_y, v_z;
	float f_x = 0.0;
	float f_y = 0.0;
	float f_z = 0.0;


	Atom(int aEl, float aX,float aY,float aZ, float aV_x,float aV_y,float aV_z){
		el = aEl;
		x = aX;
		y = aY;
		z= aZ;
		v_x = aV_x;
		v_y = aV_y;
		v_z = aV_z;

	}
};

void print_coord(Atom* atom, int nAt)
{
	for (int ti = 0; ti < nAt ; ti++)
	{
		cout << "H" << " " << atom[ti].x << " " << atom[ti].y << " " << atom[ti].x << endl;
	}
	
}

float LJ_potential(Atom& atom1, Atom& atom2, float epsilon, float sigma)
{
	float dist = sqrt(pow(atom1.x - atom2.x,2));
	float energy = 4*epsilon*(pow(sigma/dist,12)-pow(sigma/dist,6));
	float force = 48*epsilon*(pow(sigma,12)/pow(dist,13)-0.5*pow(sigma,6)/pow(dist,7));
	return energy;
}

void LJ_f(Atom* molecule, int nAt, float epsilon, float sigma)
{
	float dist_x, dist_y, dist_z;
	float force_x, force_y, force_z;
	float r2, r2i, r6i;
	for (int i = 0; i < nAt-1; i++){
		for (int j = i+1; j < nAt; j++){
			
			dist_x = sqrt(pow(molecule[i].x - molecule[j].x,2));
			dist_y = sqrt(pow(molecule[i].y - molecule[j].y,2));
			dist_z = sqrt(pow(molecule[i].z - molecule[j].z,2));
			// cout << dist_x << endl;
			// cout << dist_y << endl;
			// cout << dist_z << endl;
			force_x = 48*epsilon*(pow(sigma,12)/pow(dist_x,13)-0.5*pow(sigma,6)/pow(dist_x,7));
			force_y = 48*epsilon*(pow(sigma,12)/pow(dist_y,13)-0.5*pow(sigma,6)/pow(dist_y,7));
			force_z = 48*epsilon*(pow(sigma,12)/pow(dist_z,13)-0.5*pow(sigma,6)/pow(dist_z,7));
			molecule[i].f_x = molecule[i].f_x + force_x*dist_x;
			molecule[j].f_x = molecule[j].f_x - force_x*dist_x; 
			molecule[i].f_y = molecule[i].f_y + force_y*dist_y;
			molecule[j].f_y = molecule[j].f_y - force_y*dist_y; 
			molecule[i].f_z = molecule[i].f_z + force_z*dist_z;
			molecule[j].f_z = molecule[j].f_z - force_z*dist_z; 
		}
	}
}


void verlet_system(Atom* molecule, int nAt, float dt = 1.0)
{
	int step = 0;
	float pred_x, pred_y, pred_z, force_x, force_y, force_z;
	float new_x, new_y, new_z;
	float vx, vy, vz;
	
	for (int i = 0; i < nAt; i++){
		pred_x = molecule[i].x - molecule[i].v_x;
		pred_y = molecule[i].y - molecule[i].v_y;	
		pred_z = molecule[i].z - molecule[i].v_z;
		for (int j = 0; j < nAt; j++){
			LJ_f(molecule, nAt, 0.5,0.1);
			new_x = 2*molecule[i].x - pred_x + dt*dt*2*molecule[i].f_x;
			vx = (new_x-pred_x)/(2*dt);
			pred_x = molecule[i].x;
			molecule[i].x = new_x;
			new_y = 2*molecule[i].y - pred_y + dt*dt*2*molecule[i].f_y;
			vy = (new_y-pred_y)/(2*dt);
			pred_y = molecule[i].y;
			molecule[i].y = new_y;
			new_y = 2*molecule[i].z - pred_z + dt*dt*2*molecule[i].f_z;
			vz = (new_z-pred_z)/(2*dt);
			pred_z = molecule[i].z;
			molecule[i].z = new_z;
		}
	}

}

void verlet_system_test(Atom* molecule, int nAt, float dt = 1.0)
{
	int step = 0;
	float pred_x, pred_y, pred_z, force_x, force_y, force_z;
	float new_x, new_y, new_z;
	float vx, vy, vz;
	for (int i = 0; i < nAt; i++)
	{
		force_x=0.2;
		force_y=0.2;
		force_z=0.2;
		pred_x = molecule[i].x - molecule[i].v_x;
		pred_y = molecule[i].y - molecule[i].v_y;
		pred_z = molecule[i].z - molecule[i].v_z;
		new_x = 2*molecule[i].x - pred_x + dt*dt*2*force_x;
		vx = (new_x-pred_x)/(2*dt);
		pred_x = molecule[i].x;
		molecule[i].x = new_x;
		new_y = 2*molecule[i].y - pred_y + dt*dt*2*force_y;
		vy = (new_y-pred_y)/(2*dt);
		pred_y = molecule[i].y;
		molecule[i].y = new_y;
		new_y = 2*molecule[i].z - pred_z + dt*dt*2*force_z;
		vz = (new_z-pred_z)/(2*dt);
		pred_z = molecule[i].z;
		molecule[i].z = new_z;
	}

}

void verlet(Atom atom1, float vel, float dt = 0.1)
{
	int step = 0;
	float pred_x = atom1.x - atom1.v_x;
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


