/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_arr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:27:03 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:27:57 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADN_ARR_H
# define ADN_ARR_H

# include <stddef.h>
# include <adn_lst.h>

size_t		adn_arr_len(void *tab);
t_lst		*adn_tab_to_lst(char **tab);
void		*adn_arr_new(size_t size);
void		adn_arr_iter(void *arr, void (*f)(void *arr, void *context),
			void *context);
void		adn_arr_add_end(void *arr, void *elem);

#endif
