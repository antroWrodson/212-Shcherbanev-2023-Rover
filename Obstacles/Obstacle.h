#pragma once

#include <cmath>
#include "auxilary.h"

// ������������ ����� �����������
class Obstacle {
protected:
	aux::coordinate center;
public:
	Obstacle();
	Obstacle(double x, double y);

	// ���������� ������ ������� ������� � ������ �����
	virtual double Height(aux::coordinate dot);

	// ��������, ��������� �� ����������� � ������ �����
	virtual bool IsHere(aux::coordinate dot);
};