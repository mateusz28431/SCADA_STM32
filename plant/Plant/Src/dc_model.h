/*
 * dc_model.h
 *
 *  Created on: 29.10.2016
 *      Author: Admin
 */

#ifndef APPLICATION_USER_DC_MODEL_H_
#define APPLICATION_USER_DC_MODEL_H_

typedef struct
{
	float R;
	float ke;
	float km;
	float J;
	float Mobc;
}dc_data;

typedef struct
{
	float a;
	float b;
	float c;
}model_parameters;

typedef struct
{
	float x1;
	float x2;
}states;

void compute_dx(states *dx, states * x, model_parameters * p, float u);
void set_parameters(dc_data * dc, model_parameters * p);
void rk4(states * x,model_parameters * parameters, float u,float h);
#endif /* APPLICATION_USER_DC_MODEL_H_ */


