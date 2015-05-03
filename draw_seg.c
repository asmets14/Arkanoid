#include "arkanoid.h"


void ft_color(char nb, int seg_num)
{
	if (seg_num == 1)
	{
		if (nb == '0' || nb == '4' || nb == '5' || nb == '6' || nb == '8' || nb == '9')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);
	}
	else if (seg_num == 2)
	{

		if (nb == '0' || nb == '2' || nb == '3' || nb == '5' || nb == '6' || nb == '7' || nb == '8' || nb == '9')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);
	}
	else if (seg_num == 3)
	{
		if (nb == '0' || nb == '1' || nb == '2' || nb == '3' || nb == '4' || nb == '7' || nb == '8' || nb == '9')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);	
	}
	else if (seg_num == 4)
	{
		if (nb == '2' || nb == '3' || nb == '4' || nb == '5' || nb == '6' || nb == '8')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);	
	}
	else if (seg_num == 5)
	{
		if (nb == '0' || nb == '2' || nb == '6' || nb == '8')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);
	}
	else if (seg_num == 6)
	{
		if (nb == '0' || nb == '1' || nb == '3' || nb == '4' || nb == '5' || nb == '6' || nb == '7' || nb == '8' || nb == '9')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);
	}
	else if (seg_num == 7)
	{
		if (nb == '0' || nb == '2' || nb == '3' || nb == '5' || nb == '6' || nb == '8' || nb == '9')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);
	}
	
}
void draw_nb(t_seg *s, char nb, float add)
{
	glBegin(GL_LINES);
	ft_color(nb, 2);
	glVertex2f(s->seg2.x1 + add, s->seg2.y1);
	glVertex2f(s->seg2.x2 + add, s->seg2.y2);
	ft_color(nb, 4);
	glVertex2f(s->seg4.x1 + add, s->seg4.y1);
	glVertex2f(s->seg4.x2 + add, s->seg4.y2);
	ft_color(nb, 7);
	glVertex2f(s->seg7.x1 + add, s->seg7.y1);
	glVertex2f(s->seg7.x2 + add, s->seg7.y2);
	ft_color(nb, 1);
	glVertex2f(s->seg1.x1 + add, s->seg1.y1);
	glVertex2f(s->seg1.x2 + add, s->seg1.y2);
	ft_color(nb, 5);
	glVertex2f(s->seg5.x1 + add, s->seg5.y1);
	glVertex2f(s->seg5.x2 + add, s->seg5.y2);
	ft_color(nb, 3);
	glVertex2f(s->seg3.x1 + add, s->seg3.y1);
	glVertex2f(s->seg3.x2 + add, s->seg3.y2);
	ft_color(nb, 6);
	glVertex2f(s->seg6.x1 + add, s->seg6.y1);
	glVertex2f(s->seg6.x2 + add, s->seg6.y2);
	glEnd();
}

char *check_score(char *score, int ret )
{
	char	new_score[4];
;
	if(ret == 2)
	{
		new_score[0] = '0';
		new_score[1] = score[0];
		new_score[2] = score[1];
		new_score[3] = 0;
	}
	else if( ret == 1)
	{
		new_score[0] = '0';
		new_score[1] = '0';
		new_score[2] = score[0];
		new_score[3] = 0;
	}
	else 
	{
		new_score[0] = score[0];
		new_score[1] = score[1];
		new_score[2] = score[2];
		new_score[3] = 0;
	}
	return (ft_strdup(new_score));
}

void draw_seg(t_seg *s, t_env *e)
{
	char	*score;
	char	*new_score;
 
	score = ft_itoa(e->score);
	new_score = check_score(score, ft_strlen(score));
	glLineWidth (0.5);
	init_seg(s);
	draw_nb(s, new_score[0], 0.0);
	draw_nb(s, new_score[1], s->dizaine);
	draw_nb(s, new_score[2], s->unite);
	// draw_dizaine(s);
	// draw_unite(s);
}



































