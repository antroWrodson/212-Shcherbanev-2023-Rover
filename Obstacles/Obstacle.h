#pragma once

#include <cmath>
#include "auxilary.h"

// Родительский класс препятствия
class Obstacle {
protected:
	aux::coordinate center;
public:
	Obstacle();
	Obstacle(double x, double y);

	// Вычисление высоты данного объекта в данной точке
	virtual double Height(aux::coordinate dot);

	// Проверка, находится ли препятствие в данной точке
	virtual bool IsHere(aux::coordinate dot);
};