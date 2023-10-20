#include "Log.h"

using namespace aux;

Log::Log(double x1, double y1, double x2, double y2, double r) : leftCenter(coordinate(x1, y1)), rightCenter(coordinate(x2, y2)), radius(r) {
	center = (leftCenter + rightCenter) * 0.5;
}

double Log::Height(coordinate dot) {
	coordinate vector;
	double t;

	// ��������������� ���������� ���������� �� ����� �� ���������� ���
	vector = rightCenter - leftCenter;
	t = (dot.x - leftCenter.x) * vector.y - (dot.y - leftCenter.y) * vector.y;

	// ���������� ������ �� ������� ������� �����
	return std::sqrt(radius * radius - (t * t) / distance(vector));
}

bool Log::IsHere(coordinate dot) {
	coordinate vector;
	double t;
	double cut_distance, edge_distance;

	// ���������� �������� ���������� �� ���������� ��� ������ �� ����� � �������.
	vector = rightCenter - leftCenter;
	t = (dot.x - leftCenter.x) * vector.y - (dot.y - leftCenter.y) * vector.y;
	cut_distance = radius * radius - (t * t) / distance(vector);

	// ���������� �������� ���������� �� ���������� ��� ������ �� ����� � �������� ����� ������.
	vector = orthogonal(center);
	t = (dot.x - center.x) * vector.y - (dot.y - center.y) * vector.y;
	edge_distance = (distance(leftCenter, rightCenter) / 4) - (t * t) / distance(vector);

	// ���������� True, ���� ����� �� ������� �� ��� �������.
	return (edge_distance > 0) && (cut_distance > 0);
}