/*
 * dc_model.c
 *
 *  Created on: 29.10.2016
 *      Author: Admin
 */
#include "dc_model.h"

void compute_dx(states *dx, states * x, model_parameters * p, float u)
{
	dx->x1 = x->x2;
	dx->x2 = -p->a*x->x2+p->b*u-p->c;
}
void set_parameters(dc_data * dc, model_parameters * p)
{
	p->a = (dc->ke*dc->km)/((dc->J*dc->R));
	p->b = dc->km/((dc->J*dc->R));
	p->c = dc->Mobc/dc->J;
}
void rk4(states * x,model_parameters * p, float u,float h)
{
	float h2 = h/2.0f;
	float h3 = h/3.0f;
	float h6 = h/6.0f;
	states dx1, dx2, dx3, dx4;
	states x_temp;
	x_temp.x1 = x->x1;
	x_temp.x2 = x->x2;

	compute_dx(&dx1,&x_temp,p,u);
	//x1
	x_temp.x1 = x->x1 + h2*dx1.x1;
	x_temp.x2 = x->x2 + h2*dx1.x2;

	compute_dx(&dx2,&x_temp,p,u);

	//x2
	x_temp.x1 = x->x1 + h2*dx2.x1;
	x_temp.x2 = x->x2 + h2*dx2.x2;

	compute_dx(&dx3,&x_temp,p,u);

	//x3
	x_temp.x1 = x->x1 + h*dx3.x1;
	x_temp.x2 = x->x2 + h*dx3.x2;

	compute_dx(&dx4,&x_temp,p,u);

	x->x1 = x->x1  + h3*(dx2.x1+dx3.x1) + h6*(dx1.x1+dx4.x1);
	x->x2 = x->x2 + h3*(dx2.x2+dx3.x2) + h6*(dx1.x2+dx4.x2);

}

