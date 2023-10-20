#include "Obstacle.h"

using namespace std;
using namespace aux;

// ������������ ����� �����������
Obstacle::Obstacle() : center(coordinate(0, 0)) 
{}
Obstacle::Obstacle(double x, double y) : center(coordinate(x, y)) 
	{}

double Obstacle::Height(aux::coordinate dot)
{
	return 0.0;
}

bool Obstacle::IsHere(aux::coordinate dot)
{
	return (dot.x == center.x && dot.y == center.y);
}