#include <cstring>

#include "auxilary.h"

#include "Control.h"

class Boundary {
protected:
	Control controller;
	aux::pair<int> cursor;
public:
	Boundary();

	void command(char* cmd);
};