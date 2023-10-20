#include "config.h"
#include "Pixel.h"

////////////////////////	Pixel class	////////////////////////

// Constructors
pixel::pixel() : pos(aux::coordinate()), height(), object(nullptr), color() {}
pixel::pixel(double x, double y) : pos(aux::coordinate(x, y)), height(0), object(nullptr), color(0) {}
pixel::pixel(double x, double y, double h) : pos(aux::coordinate(x, y)), height(h), object(nullptr), color(0) {}
pixel::pixel(double x, double y, double h, Obstacle* obj) : pos(aux::coordinate(x, y)), height(h), object(obj), color(0) {}

void pixel::operator=(const pixel& pix) 
{
	pos = pix.pos;
	height = pix.height;
	object = pix.object;
	color = pix.color;
}

// Get methods
aux::coordinate pixel::getPosition() 
{
	return pos;
}
double pixel::getHeight() 
{
	return height;
}
bool pixel::isOccupied() 
{
	return object != nullptr;
}
Obstacle* pixel::getObstacle()
{
	return object;
}
char pixel::getColor()
{
	return color;
}

// Manually set height
void pixel::setHeight(double h) 
{
	height = h;
}
void pixel::setObstacle(Obstacle* obj)
{
	object = obj;
}
void pixel::setColor(char col)
{
	color = col;
}
// Calculate height by an obstacle
double pixel::calculateHeight() 
{
	height = (*object).Height(pos);
	return height;
}