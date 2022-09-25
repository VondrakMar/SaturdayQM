#include <iostream>
#include <math.h>
#include <string>

float distance(float x1, float x2)
{
	return sqrt(pow(x1-x2,2));
}

float LJ_potential(float dist, float epsilon, float sigma)
{
	return 4*epsilon*(pow(sigma/dist,12)-pow(sigma/dist,6));
}