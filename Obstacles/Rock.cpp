// ������
#include "Rock.h"

Rock::Rock(double x, double y, double r) : radius(r) {
	center = aux::coordinate(x, y);
}

double Rock::Height(aux::coordinate dot) {
	// Radius of sphere
	return std::sqrt(radius * radius - distance(center, dot));
}

bool Rock::IsHere(aux::coordinate dot) {
	// Distance to center smaller than radius.
	return radius * radius < distance(center, dot);
}