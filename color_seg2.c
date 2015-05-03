/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_seg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:58:12 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 19:59:58 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		seg6(char nb)
{
	if (nb == '0' || nb == '1' || nb == '3' || nb == '4'
			|| nb == '5' || nb == '6' || nb == '7'
			|| nb == '8' || nb == '9')
		glColor3f(1.f, 1.f, 1.f);
	else
		glColor3f(0.f, 0.f, 0.f);
}

void		ft_color_seg(char nb, int seg_num)
{
	if (seg_num == 1)
		seg1(nb);
	else if (seg_num == 2)
		seg2(nb);
	else if (seg_num == 3)
		seg3(nb);
	else if (seg_num == 4)
		seg4(nb);
	else if (seg_num == 5)
		seg5(nb);
	else if (seg_num == 6)
		seg6(nb);
	else if (seg_num == 7)
	{
		if (nb == '0' || nb == '2' || nb == '3' || nb == '5'
				|| nb == '6' || nb == '8' || nb == '9')
			glColor3f(1.f, 1.f, 1.f);
		else
			glColor3f(0.f, 0.f, 0.f);
	}
}
