#include <iostream>
#include <fstream>
#include <string>

#include "config.h"
#include "exceptions.h"
#include "auxilary.h"
#include "obstacles.h"

#include "Field.h"


class Control {
protected:
	Field surface;
	bool fieldCalculated;
public:
	Control();

	// Генерация поля
	aux::pair<int> generateField(int x=CONFIG::field::FIELD_X, int y=CONFIG::field::FIELD_Y, double step=CONFIG::field::FIELD_STEP);

	// Добавление препятствий
	void Control::generateGauss(int x, int y, 
									double h=CONFIG::obstacles::DEFAULT_GAUSSIAN_HEIGHT, 
									double s1=CONFIG::obstacles::DEFAULT_X_DISPERSION, 
									double s2=CONFIG::obstacles::DEFAULT_Y_DISPERSION, 
									double phi=CONFIG::obstacles::DEFAULT_ANGLE);
	void generateRock(int x, int y, double r=CONFIG::obstacles::DEFAULT_ROCK_RADIUS);
	void generateLog(int x1, int y1, int x2, int y2, double r=CONFIG::obstacles::DEFAULT_LOG_RADIUS);
	
	// Финальные рассчёты
	void calculateField();
	void fieldGraphics(const char* filename=CONFIG::file::GNUPLOT);
};