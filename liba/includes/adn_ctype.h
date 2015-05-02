/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_ctype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 12:18:03 by asmets            #+#    #+#             */
/*   Updated: 2015/03/25 12:18:11 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADN_CTYPE_H
# define ADN_CTYPE_H

int	adn_isspace(int c);
int	adn_isalpha(int c);
int	adn_isascii(int c);
int	adn_isdigit(int c);
int	adn_isprint(int c);
int	adn_tolower(int c);
int	adn_toupper(int c);
int	adn_ispunct(int c);

#endif
