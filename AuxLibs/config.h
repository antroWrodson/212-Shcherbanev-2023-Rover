#pragma once

namespace CONFIG 
{

	namespace field
	{
		const int FIELD_X = 1024;
		const int FIELD_Y = 1024;
		const double FIELD_STEP = 0.1;
	}

	namespace log
	{
		const bool IS_LOGGING = true;
		const bool LOG_TIME = true;
		const char* LOG_FILE_BOUNDARY = "Log\\log_boundary.txt";
		const char* LOG_FILE_CONTROL = "Log\\log_control.txt";
	}

	namespace obstacles
	{
		const double DEFAULT_ROCK_RADIUS = 1;

		const double DEFAULT_LOG_RADIUS = 1;

		const double DEFAULT_GAUSSIAN_HEIGHT = 1;
		const double DEFAULT_X_DISPERSION = 1;
		const double DEFAULT_Y_DISPERSION = 1;
		const double DEFAULT_ANGLE = 0;
	}

	namespace file
	{
		const char* GNUPLOT = "plot.txt";
	}
}