#include "auxilary.h"
#include "obstacles.h"

class pixel {
protected:
	aux::coordinate pos;	// Absolute position on surface
	double height;			// Absolute height in surface
	Obstacle* object;
	char color; 			// Color for heightmap form 0 to 255;
public:
	// Constructors
	pixel();
	pixel(double x, double y);
	pixel(double x, double y, double h);
	pixel(double x, double y, double h, Obstacle* obj);
	void operator=(const pixel& pix);

	// Get methods
	aux::coordinate getPosition();
	double getHeight();
	bool isOccupied();
	Obstacle* getObstacle();
	char getColor();

	// Update methods
	void setHeight(double h);
	void setObstacle(Obstacle*);
	void setColor(char col);
	double calculateHeight();
};