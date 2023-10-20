#define _USE_MATH_DEFINES
#include "Gaussian.h"

using namespace aux;

Gaussian::Gaussian(double x, double y, double h, double s1, double s2, double phi) : height(h), dispersion(aux::coordinate(s1, M_PI * phi / 180), aux::coordinate(M_PI * phi / 180, s2)) {
		center = coordinate(x, y);
	}

// ��������
double Gaussian::Height(coordinate dot) {
	double sx = dispersion.x.x;
	double sy = dispersion.y.y;
	double phi = dispersion.x.y;

	double a = pow(cos(phi) / sx, 2) + pow(sin(phi) / sy, 2);
	double b = sin(2 * phi) * (- pow(1 / sx, 2) + pow(1 / sy, 2));
	double c = pow(sin(phi) / sx, 2) + pow(cos(phi) / sy, 2);

	return height * exp(-0.5 * (a * pow((center.x - dot.x), 2)
		+ b * (center.x - dot.x) * (center.y - dot.y) + c * pow((center.y - dot.y), 2)));
}


bool Gaussian::IsHere(coordinate dot) {
	// Gaussian function get enough effect, if distance to dot smaller than 3 * sigma.
	return 9 * dispersion.x.x * dispersion.x.x < distance(center, dot) && 9 * dispersion.y.y * dispersion.y.y < distance(center, dot);
}