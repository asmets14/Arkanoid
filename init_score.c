#include "arkanoid.h"

void init_seg2(t_seg *s)
{
	s->dizaine = 0.07;
	s->unite = 0.14;
	s->seg5.x1 = -0.5;
	s->seg5.x2 = -0.5;
	s->seg5.y1 = 0.95;
	s->seg5.y2 = 0.91;
	s->seg6.x1 = -0.45;
	s->seg6.x2 = -0.45;
	s->seg6.y1 = 0.95;
	s->seg6.y2 = 0.91;
	s->seg7.x1 = -0.5;
	s->seg7.x2 = -0.45;
	s->seg7.y1 = 0.91;
	s->seg7.y2 = 0.91;
	
}
void init_seg(t_seg *s)
{
	s->seg1.x1 = -0.5;
	s->seg1.x2 = -0.5;
	s->seg1.y1 = 0.99;
	s->seg1.y2 = 0.95;
	s->seg2.x1 = -0.5;
	s->seg2.x2 = -0.45;
	s->seg2.y1 = 0.99;
	s->seg2.y2 = 0.99;
	s->seg3.x1 = -0.45;
	s->seg3.x2 = -0.45;
	s->seg3.y1 = 0.99;
	s->seg3.y2 = 0.95;
	s->seg4.x1 = -0.5;
	s->seg4.x2 = -0.45;
	s->seg4.y1 = 0.95;
	s->seg4.y2 = 0.95;
	init_seg2(s);
}