/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_seg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:51:33 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 19:57:32 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		seg1(char nb)
{
	if (nb == '0' || nb == '4' || nb == '5' || nb == '6'
			|| nb == '8' || nb == '9')
		glColor3f(1.f, 1.f, 1.f);
	else
		glColor3f(0.f, 0.f, 0.f);
}

void		seg2(char nb)
{
	if (nb == '0' || nb == '2' || nb == '3' || nb == '5'
			|| nb == '6' || nb == '7' || nb == '8' || nb == '9')
		glColor3f(1.f, 1.f, 1.f);
	else
		glColor3f(0.f, 0.f, 0.f);
}

void		seg3(char nb)
{
	if (nb == '0' || nb == '1' || nb == '2' || nb == '3'
			|| nb == '4' || nb == '7' || nb == '8' || nb == '9')
		glColor3f(1.f, 1.f, 1.f);
	else
		glColor3f(0.f, 0.f, 0.f);
}

void		seg4(char nb)
{
	if (nb == '2' || nb == '3' || nb == '4' || nb == '5'
			|| nb == '6' || nb == '8' || nb == '9')
		glColor3f(1.f, 1.f, 1.f);
	else
		glColor3f(0.f, 0.f, 0.f);
}

void		seg5(char nb)
{
	if (nb == '0' || nb == '2' || nb == '6' || nb == '8')
		glColor3f(1.f, 1.f, 1.f);
	else
		glColor3f(0.f, 0.f, 0.f);
}
