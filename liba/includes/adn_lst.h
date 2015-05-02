/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:21:25 by asmets            #+#    #+#             */
/*   Updated: 2015/03/25 16:53:32 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADN_LST_H
# define ADN_LST_H

typedef struct	s_elem
{
	void			*data;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_lst
{
	t_elem	*head;
}				t_lst;

void			adn_lst_fusion(t_elem *elem1, t_elem *elem2);
void			adn_lst_put_end(t_lst *list, t_elem *elem);
void			adn_lst_put_up(t_lst *list, t_elem *elem);
void			adn_create_lst_end(t_lst *list, void *name);
t_lst			*adn_lst_newlist(void);
t_elem			*adn_lst_newelem(void *data);
int 			adn_lst_len(t_lst *list);
void 			adn_free_lst(t_lst *list);



#endif
