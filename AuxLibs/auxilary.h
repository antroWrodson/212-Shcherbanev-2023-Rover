#pragma once

namespace aux
{
	// ��������� ��������� ��������� ����������� � ����������� �������� �� ���
	template <typename T>
	struct pair {
		T x, y;

		pair()
		{}
		pair(T a, T b) : x(a), y(b)
		{}

		pair operator+(const pair other) {
			return pair(x + other.x, y + other.y);
		}

		pair operator-(const pair other) {
			return pair(x - other.x, y - other.y);
		}

		pair operator*(double scalar) {
			return pair(x * scalar, y * scalar);
		}

	};


	// ����������� ���� ������������ ����� � ������� �������� � ����
	using coordinate = pair<double>;
	// ������, ������������� �������
	coordinate orthogonal(coordinate dot);
	// ����� ���������� ������� � ���������� ����� ����� �������
	double distance(coordinate dot);
	double distance(coordinate dot1, coordinate dot2);
}
