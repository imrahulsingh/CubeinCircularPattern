#pragma once
#include "point.h"
#include <vector>

using namespace std;

class Vector
{
 private :
	vector <float> vectorCoefficients; //find a better way to write this class variable
 public:
	void setVectorCoefficients(float &value);
	void rotateVector(Vector &userVector, Vector &normalToUserVector, float angle);
	void findUnitVector();
	static Vector crossProduct(Vector &one, Vector &two);
	Vector operator *(float &radius);
	Point operator +(Point &firstCorner);
};