#include "Field.h"
#include "exceptions.h"

////////////////////////	 Field Class		 ////////////////////////

// Constructors
Field::Field() : size({0, 0}), z_bound({0, 0}), step(0), pixels() 
{
	std::vector<Obstacle> obst;
	obstacles = obst;
}

Field::Field(int x, int y) : size({x, y}), z_bound({0, 0}), step(1), pixels()
{
	std::vector<Obstacle> obst;
	obstacles = obst;

	pixels = new pixel *[x];

	for (int i = 0; i < size.x; i++) 
	{
		pixels[i] = new pixel [y];
		for (int j = 0; j < size.y; j++) 
		{
			pixel temp(i * step, j * step);
			pixels[i][j] = temp;
		}
	}
}
	
Field::Field(int x, int y, double step) : size({x, y}), z_bound({0, 0}), step(step), pixels()
{
	std::vector<Obstacle> obst;
	obstacles = obst;


	for (int i = 0; i < size.x; i++) 
	{
		for (int j = 0; j < size.y; j++) 
		{
			pixel temp(i * step, j * step);
			pixels[i][j] = temp;
		}
	}
}

void Field::operator=(const Field& field) 
{
	this->size = field.size;
	this->step = field.step;
	this->obstacles = field.obstacles;
	this->pixels = field.pixels;
}
//

void Field::calculateField() 
{	
	double z;

	// Вычисление высот пикселей и нахождение верхней и нижней границы поля.
	for (int i = 0; i < size.x; i++) 
	{
		for (int j = 0; j < size.y; j++) 
		{
			z = pixels[i][j].calculateHeight();

			// Установление граничных точек z координат, для дальнейшей отрисовки.
			if (z_bound.x > z) 
			{
				z_bound.x = z;
			}
			if (z_bound.y < z) 
			{
				z_bound.y = z;
			}
		}
	}

	// Повторный обход, для установки цветов пикселей
	for (int i = 0; i < size.x; i++) 
	{
		for (int j = 0; j < size.y; j++) 
		{	
			double height = pixels[i][j].getHeight();
			if (height >= z_bound.y) 
				pixels[i][j].setColor(255);
			else if (height <= z_bound.x)
				pixels[i][j].setColor(0);
			else 
				pixels[i][j].setColor((char)((height - z_bound.x) / (z_bound.y - z_bound.x) * 256));
		}
	}
}

void Field::addObstacle(Obstacle obstacle) 
{
	for (int i = 0; i < size.x; i++) 
	{
		for (int j = 0; j < size.y; j++) {
			if (obstacle.IsHere({i * step, j * step}) && !pixels[i][j].isOccupied()) 
			{
				pixels[i][j].setObstacle(&obstacle);
			}
			else if (pixels[i][j].isOccupied()) 
				for (int k = 0; k < i; k++) 
				{
					for (int l = 0; l < j; l++) 
					{
						if (pixels[k][l].getObstacle() == &obstacle)
						{
							pixels[k][l].setObstacle(nullptr);
						}
					}
				}
				throw field_error("Colission error."); // Collision error
		}
	}
}

aux::pair<int> Field::getSize()
{
	return size;
}

pixel Field::getPixel(int i, int j) 
{
	if (size.x <= i || size.y <= j) 
		return;
	else 
		return pixels[i][j];
}

double Field::getStep()
{
	return step;
}

Field::~Field()
{
	for (int i; i < size.x; i++) 
	{
		delete pixels[i];
	}
	delete pixels;

	delete &obstacles;
}