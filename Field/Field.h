#include <vector>
#include "auxilary.h"
#include "obstacles.h"
#include "Pixel.h"


class Field {
protected:
	aux::pair<int> size;
	aux::coordinate z_bound;
	double step;
	std::vector<Obstacle> obstacles;
	pixel **pixels;
public:
	Field();
	Field(int, int);
	Field(int, int, double);
	void operator=(const Field& field);

	void calculateField();
	void addObstacle(Obstacle);

	aux::pair<int> getSize();
	pixel getPixel(int, int);
	double getStep();

	~Field();
};
