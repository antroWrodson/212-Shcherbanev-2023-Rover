#include "Control.h"

using namespace CONFIG::field;
using namespace CONFIG::obstacles;

// Конструктор
Control::Control() : surface(Field()), fieldCalculated(false)
{}

// Создание поля
aux::pair<int> Control::generateField(int x, int y, double step)
{
    surface = Field(x, y, step);
    return aux::pair<int>(int(x / 2), int(y / 2));
}


// Добавление объектов
void Control::generateGauss(int x, int y, double h, double s1, double s2, double phi)
{
    if (fieldCalculated == false)
        throw controller_error("Field is already calculated. No more new obstacles.");

    try 
    {
        surface.addObstacle(Gaussian(x * surface.getStep(), y * surface.getStep(), h, s1, s2, phi));
    }
    catch (const field_error& err) 
    {
        throw controller_error("Can't add this object.");
    }
}
void Control::generateRock(int x, int y, double r)
{
    if (fieldCalculated == false)
        throw controller_error("Field is already calculated. No more new obstacles.");

    try 
    {
        surface.addObstacle(Rock(x * surface.getStep(), y * surface.getStep(), r));
    }
    catch (const field_error& err) 
    {
        throw controller_error("Can't add this object.");
    }
}
void Control::generateLog(int x1, int y1, int x2, int y2, double r)
{
    if (fieldCalculated == false)
        throw controller_error("Field is already calculated. No more new obstacles.");

    // Если указаны не все координаты, считаем её центром и вытягиваем по X на два радиуса. Таким образом, стандартное бревно параллельно оси X и длина равна диаметру.
    if (x1 == x2)
    {
        x1 -= r;
        x2 += r;
    }

    try 
    {
        surface.addObstacle(Log(x1 * surface.getStep(), y1 * surface.getStep(), x2 * surface.getStep(), y2 * surface.getStep(), r));
    }
    catch (const field_error& err) 
    {
        throw controller_error("Can't add this object.");
    }
}
	
void Control::calculateField()
{
    fieldCalculated = true;

}
void Control::fieldGraphics(const char* filename)
{
    std::ofstream out;
    pixel pix;
    out.open(filename);

    for (int i = 0; i < surface.getSize().x; i++) 
    {
        for (int j = 0; j < surface.getSize().y; j++) 
        {
            pix = surface.getPixel(i, j);
            out << pix.getPosition().x << " " << pix.getPosition().y << " " << pix.getHeight() << std::endl;
        }
    }
}