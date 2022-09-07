#include <iostream>
#include "Vector.h"
#include "Point.h"

void Vector::setVectorCoefficients(float &value)
{
	this->vectorCoefficients.push_back(value);
}
void Vector::rotateVector(Vector &userVector, Vector &normalToUserVector, float angle)
 {
	//[TODO #1] : Write your function here, to rotate a vector by a given angle.
	float radians = (float)(angle * 3.141592) / 180;
	Vector instance;

	float magnitude = sqrt(userVector.vectorCoefficients[0] * userVector.vectorCoefficients[0]
		+ userVector.vectorCoefficients[1] * userVector.vectorCoefficients[1]
		+ userVector.vectorCoefficients[2] * userVector.vectorCoefficients[2]);
	//magnitude = sqrt(magnitude);

	instance = Vector::crossProduct(normalToUserVector, userVector);

	instance.vectorCoefficients[0] = instance.vectorCoefficients[0] / magnitude;
	instance.vectorCoefficients[1] = instance.vectorCoefficients[1] / magnitude;
	instance.vectorCoefficients[2] = instance.vectorCoefficients[2] / magnitude;

	this->vectorCoefficients.push_back(cos(radians) * normalToUserVector.vectorCoefficients[0] +
		sin(radians) * instance.vectorCoefficients[0]);
	this->vectorCoefficients.push_back(cos(radians) * normalToUserVector.vectorCoefficients[1] +
		sin(radians) * instance.vectorCoefficients[1]);
	this->vectorCoefficients.push_back(cos(radians) * normalToUserVector.vectorCoefficients[2] +
		sin(radians) * instance.vectorCoefficients[2]);
}
void Vector::findUnitVector()
{
	//[TODO #1] : Write your function here, to find unit vector.
	Vector unitVector;
	double magnitude = sqrt(pow(this->vectorCoefficients[0], 2) + pow(this->vectorCoefficients[1], 2) + pow(this->vectorCoefficients[2], 2));
	for (int i = 0; i < 3; i++) {
		unitVector.vectorCoefficients.push_back(this->vectorCoefficients[i] / magnitude);
	}
}
Vector Vector::crossProduct(Vector& one, Vector& two)
{
	//[TODO #1] : Write your function here, to return a vector which is a cross product of two vectors.
	Vector crossProduct;
	double x = one.vectorCoefficients[1] * two.vectorCoefficients[2] - one.vectorCoefficients[2] * two.vectorCoefficients[1];
	crossProduct.vectorCoefficients.push_back(x);
	double y = -1 * (one.vectorCoefficients[0] * two.vectorCoefficients[2] - one.vectorCoefficients[2] * two.vectorCoefficients[0]);
	crossProduct.vectorCoefficients.push_back(y);
	double z = one.vectorCoefficients[0] * two.vectorCoefficients[1] - one.vectorCoefficients[1] * two.vectorCoefficients[0];
	crossProduct.vectorCoefficients.push_back(z);
	return crossProduct;
}

Vector Vector ::operator*(float & radius)
{
	Vector newVector;
	for (int i = 0; i < 3; i++)
	{
		newVector.vectorCoefficients.push_back(this->vectorCoefficients[i] * radius);
	}
	return newVector;
}

Point Vector::operator +(Point &anyCorner)
{
	Point newPoint;
	newPoint.setX(anyCorner.getX() + this->vectorCoefficients[0]);
	newPoint.setY(anyCorner.getY() + this->vectorCoefficients[1]);
	newPoint.setZ(anyCorner.getZ() + this->vectorCoefficients[2]);
	return newPoint;
}
