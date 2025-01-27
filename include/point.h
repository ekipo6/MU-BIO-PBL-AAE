#pragma once
typedef struct point_t {

	double t;
	double x;
	double y;
	double vx;
	double vy;
	double v;
	double theta; 
}point_t;

// delcaration of the freepoints fucntion
void freePoints (point_t** points);
