#include <iostream>
#include <math.h>
#include <string>

using namespace std;

float distance(float x1, float x2)
{
	return sqrt(pow(x1-x2,2));
}

float LJ_potential(float dist, float epsilon, float sigma)
{
	return 4*epsilon*(pow(sigma/dist,12)-pow(sigma/dist,6));
}

int main()
{
	for (int i=2; i < 10; i++){
        cout << LJ_potential(distance(0,i),2.0,3.5) << endl;
    }
	return 0;
}


void thisIsATest () {
    string str = "Test";
}