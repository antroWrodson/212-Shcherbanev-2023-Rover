#include "Obstacle.h"

// ����� ���������
class Gaussian : public Obstacle {
protected:
	aux::pair<aux::coordinate> dispersion;
	const double height;
public:
	Gaussian(double x, double y, double h, double s1, double s2, double phi);

	double Height(aux::coordinate dot);

	bool IsHere(aux::coordinate dot);
};