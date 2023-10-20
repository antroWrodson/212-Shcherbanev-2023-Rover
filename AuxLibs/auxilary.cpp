#include "auxilary.h"

using namespace aux;

// ����������� ���� ������������ ����� � ������� �������� � ����
using coordinate = pair<double>;
// ������, ������������� �������
coordinate orthogonal(coordinate dot) {
	return coordinate(-(dot.y), (dot.x));
}
// ����� ���������� ������� � ���������� ����� ����� �������
double distance(coordinate dot) {
	return dot.x * dot.x + dot.y * dot.y;
}
double distance(coordinate dot1, coordinate dot2) {
	return (dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y);
}