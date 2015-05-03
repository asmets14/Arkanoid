#include "arkanoid.h"

void draw_centaine(t_seg *s)
{
	glBegin(GL_LINES);
	glColor3f( 1.f, 1.f, 1.f);
	glVertex2f( s->seg2.x1, s->seg2.y1 );
	glVertex2f( s->seg2.x2, s->seg2.y2 );
	glVertex2f( s->seg4.x1, s->seg4.y1 );
	glVertex2f( s->seg4.x2,s->seg4.y2 );
	glVertex2f( s->seg7.x1, s->seg7.y1 );
	glVertex2f( s->seg7.x2, s->seg7.y2 );
	glVertex2f( s->seg1.x1, s->seg1.y1 );
	glVertex2f( s->seg1.x2,s->seg1.y2 );
	glVertex2f( s->seg5.x1, s->seg5.y1 );
	glVertex2f( s->seg5.x2,s->seg5.y2 );
	glVertex2f( s->seg3.x1,s->seg3.y1 );
	glVertex2f( s->seg3.x2, s->seg3.y2 );
	glVertex2f( s->seg6.x1,s->seg6.y1 );
	glVertex2f( s->seg6.x2,s->seg6.y2 );
	glEnd();
}

void draw_dizaine(t_seg *s)
{
	glBegin(GL_LINES);
	glColor3f( 1.f, 1.f, 1.f);
	glVertex2f( s->seg2.x1 + s->dizaine, s->seg2.y1 );
	glVertex2f( s->seg2.x2 + s->dizaine, s->seg2.y2 );
	glVertex2f( s->seg4.x1 + s->dizaine, s->seg4.y1 );
	glVertex2f( s->seg4.x2 + s->dizaine, s->seg4.y2 );
	glVertex2f( s->seg7.x1 + s->dizaine, s->seg7.y1 );
	glVertex2f( s->seg7.x2 + s->dizaine, s->seg7.y2 );
	glVertex2f( s->seg1.x1 + s->dizaine, s->seg1.y1 );
	glVertex2f( s->seg1.x2 + s->dizaine, s->seg1.y2 );
	glVertex2f( s->seg5.x1 + s->dizaine, s->seg5.y1 );
	glVertex2f( s->seg5.x2 + s->dizaine, s->seg5.y2 );
	glVertex2f( s->seg3.x1 + s->dizaine, s->seg3.y1 );
	glVertex2f( s->seg3.x2 + s->dizaine, s->seg3.y2 );
	glVertex2f( s->seg6.x1 + s->dizaine, s->seg6.y1 );
	glVertex2f( s->seg6.x2 + s->dizaine, s->seg6.y2 );
	glEnd();
}

void draw_unite(t_seg *s)
{
	glBegin(GL_LINES);
	glColor3f( 1.f, 1.f, 1.f);
	glVertex2f( s->seg2.x1 + s->unite, s->seg2.y1 );
	glVertex2f( s->seg2.x2 + s->unite, s->seg2.y2 );
	glVertex2f( s->seg4.x1 + s->unite, s->seg4.y1 );
	glVertex2f( s->seg4.x2 + s->unite, s->seg4.y2 );
	glVertex2f( s->seg7.x1 + s->unite, s->seg7.y1 );
	glVertex2f( s->seg7.x2 + s->unite, s->seg7.y2 );
	glVertex2f( s->seg1.x1 + s->unite, s->seg1.y1 );
	glVertex2f( s->seg1.x2 + s->unite, s->seg1.y2 );
	glVertex2f( s->seg5.x1 + s->unite, s->seg5.y1 );
	glVertex2f( s->seg5.x2 + s->unite, s->seg5.y2 );
	glVertex2f( s->seg3.x1 + s->unite, s->seg3.y1 );
	glVertex2f( s->seg3.x2 + s->unite, s->seg3.y2 );
	glVertex2f( s->seg6.x1 + s->unite, s->seg6.y1 );
	glVertex2f( s->seg6.x2 + s->unite, s->seg6.y2 );
	glEnd();
}

void draw_seg(t_seg *s)
{
	glLineWidth (0.5);
	init_seg(s);
	draw_centaine(s);
	draw_dizaine(s);
	draw_unite(s);
}