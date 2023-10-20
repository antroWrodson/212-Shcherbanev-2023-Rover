#include "Boundary.h"

Boundary::Boundary()
{
    controller = Control();
    cursor = {0, 0};
}

void Boundary::command(char* msg)
{   
    char* cmd = strtok(msg, " ");
    char* arg;

    if (cmd == NULL) 
    {
        return;
    }

    else if (cmd == "Field") 
    {
        // Scan X size argument.
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            cursor = controller.generateField();
            return;
        }
        int x = std::stoi(arg);

        // Scan Y size argument.
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            cursor = controller.generateField(x);
            return;
        } 
        int y = std::stoi(arg);

        // Scan for step.
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            cursor = controller.generateField(x, y);
            return;
        } 
        int s = std::stoi(arg);

        // Full generation.
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            cursor = controller.generateField(x, y, s);
            return;
        }
        // Too many arguments.
        else
        {
            return;
        }
    }

    else if (cmd == "Gauss") 
    {
        // Scan X coordinate
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(cursor.x, cursor.y);
        }
        int x = std::stoi(arg);

        // Reading Y coordinate
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(x, cursor.y);
        }
        int y = std::stoi(arg);

        // Reading height
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(x, y);
        }
        double h = std::stod(arg);

        // Reading X dispersion
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(x, y, h);
        }
        double sx = std::stod(arg);

        // Reading Y dispersion
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(x, y, h, sx, sx);
        }
        double sy = std::stod(arg);

        // Reading angle.
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(x, y, h, sx, sy);
        }
        double phi = std::stoi(arg);

        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateGauss(x, y, h, sx, sy, phi);
        }
        // Too many arguments.
        else
        {
            return;
        }
    }

    else if (cmd == "Rock") 
    {
        // Scan X coordinate
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateRock(cursor.x, cursor.y);
        }
        int x = std::stoi(arg);

        // Reading Y coordinate
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateRock(x, cursor.y);
        }
        int y = std::stoi(arg);

        // Reading height
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateRock(x, y);
        }
        double h = std::stod(arg);

        // Full parameters generation
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateRock(x, y, h);
        }
        // Too many arguments.
        else
        {
            return;
        }
    }

    else if (cmd == "Log") 
    {
        // Scan X coordinate
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateLog(cursor.x, cursor.y, cursor.x, cursor.y);
        }
        int x1 = std::stoi(arg);

        // Reading Y coordinate
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateLog(x1, cursor.y, x1, cursor.y);
        }
        int y1 = std::stoi(arg);

        // Reading height
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateLog(x1, y1, x1, y1);
        }
        int x2 = std::stoi(arg);

        // Reading X dispersion
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateLog(x1, y1, x2, y1);
        }
        int y2 = std::stoi(arg);

        // Reading Y dispersion
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateLog(x1, y1, x2, y2);
        }
        double r = std::stod(arg);

        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.generateLog(x1, y1, x2, y2, r);
        }
        // Too many arguments.
        else
        {
            return;
        }
    }

    else if (cmd == "Calculate") 
    {
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.calculateField();
        }
        // Too many arguments.
        else
        {
            return;
        }
    }

    else if (cmd == "Plot") 
    {
        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.fieldGraphics();
        }
        char* filename = arg;

        if ((arg = strtok(msg, " ")) == NULL) 
        {
            controller.fieldGraphics(arg);
        }
        // Too many arguments.
        else
        {
            return;
        }
    }
}