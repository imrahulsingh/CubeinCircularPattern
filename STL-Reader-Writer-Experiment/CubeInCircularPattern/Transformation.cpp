
#include <iostream>
#include "Transformation.h"
#include "Solid.h"
#include "Point.h"
#include "Vector.h"


Solid Transformation:: translateSolidVertexAlongVector(Solid &firstSolid, Vector  &unitVector,
	                                  int &noOfvertices, int &noOfFacets, float &radius)
{
	Solid instanceSolid;

	//[TODO #2] : Write your function here, to translate the solid along a given vector.

    for (int s = 0; s < noOfFacets; s++) {
        Vector vec1 = unitVector.operator*(radius);
        Point d1 = firstSolid.getFacetNormal(s);
        Point p1 = vec1.operator+(d1);
        instanceSolid.setFacetNormal(p1);
    }

    for (int i = 0; i < noOfvertices; i++) {
        Vector vec2 = unitVector.operator*(radius);
        Point d2 = firstSolid.getFacetVertex(i);
        Point p2 = vec2.operator+(d2);
        instanceSolid.setFacetVertex(p2);
    }

	return instanceSolid;
}