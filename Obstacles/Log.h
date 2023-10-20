#include "Obstacle.h"

// Класс бревна
class Log : public Obstacle {
protected:
	aux::coordinate leftCenter, rightCenter;
	const double radius;
public:
	Log(double x1, double y1, double x2, double y2, double r);

	double Height(aux::coordinate dot);

	bool IsHere(aux::coordinate dot);

};