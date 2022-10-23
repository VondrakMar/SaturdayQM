import copy
from ase import Atoms
import numpy as np
import matplotlib.pyplot as plt
from ase.build import molecule

voda = molecule("H2O")

MD = Atoms()
mols = []

def verlet(molecule):
    nAt = len(molecule)
    temp_pos = molecule.get_positions()
    mols.append(voda)
	for i in range(nAt):
		pred_x = atom1.x - 0.2
		pred_y = molecule[i].y - molecule[i].v_y	
		pred_z = molecule[i].z - molecule[i].v_z
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
    '''

verlet(voda)

'''
class atom():
    def __init__(self,x,y,z,v_x,v_y,v_z):
        self.x = x
        self.y = y
        self.z = z
        self.v_x = v_x
        self.v_y = v_y
        self.v_z = v_z

atom1 = atom(0.5,0.0,0.0)
atom2 = atom(0.0,0.0,0.0)


def LJ_energy(atom1,atom2,epsilon,sigma):
    #distance = np.sqrt(np.power(atom1.x-atom2.x,2)+np.power(atom1.y-atom2.y,2)+np.power(atom1.z-atom2.z,2))
    distance =atom1.x - atom2.x
    return 4*epsilon*(pow(sigma/distance,12)-pow(sigma/distance,6))

def LJ_forces_num(atom1,atom2,epsilon,sigma,d=0.01):
    temp = copy.copy(atom1)
    temp.x += d
    LJplus = LJ_energy(temp,atom2,epsilon,sigma)
    temp.x += -2.0*d
    LJminus = LJ_energy(temp,atom2,epsilon,sigma)
    return -(LJplus-LJminus)/(2.0*d)

def LJ_forces_an(atom1,atom2,epsilon,sigma):
    distance =atom1.x - atom2.x
    return 48*epsilon*(pow(sigma,12)/pow(distance,13)-0.5*pow(sigma,6)/pow(distance,7))


distances = np.arange(0,5,0.001)
LJs = []
LJ_forces = []
LJ_a = []
for a in distances:
    temp = copy.copy(atom1)
    temp.x += a
    LJs.append(LJ_energy(temp,atom2,2,2))
    LJ_forces.append(LJ_forces_num(temp,atom2,2,2))
    LJ_a.append(LJ_forces_an(temp,atom2,2,2))

plt.plot(distances,LJs)
plt.plot(distances,LJ_forces)
plt.plot(distances,LJ_a)
plt.ylim((-3,3))
plt.show()
'''