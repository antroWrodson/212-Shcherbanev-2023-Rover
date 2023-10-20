#include "Obstacle.h"

// ����� �����
class Rock : public Obstacle {
protected:
	double radius;
public:
	Rock(double x, double y, double r);

	double Height(aux::coordinate dot);

	bool IsHere(aux::coordinate dot);
};