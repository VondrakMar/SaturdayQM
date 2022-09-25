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





int main()
{
	Atom atom1(1, 1.2,0);
	cout << atom1.x;
	// for (int i=2; i < 10; i++){
        // cout << LJ_potential(distance(0,i),2.0,3.5) << endl;
    // }
	return 0;
}


void thisIsATest () {
    string str = "Test";
}
