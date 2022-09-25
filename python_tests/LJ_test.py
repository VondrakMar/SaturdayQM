import copy
import numpy as np
import matplotlib.pyplot as plt


class atom():
    def __init__(self,x,y,z):
        self.x = x
        self.y = y
        self.z = z

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
