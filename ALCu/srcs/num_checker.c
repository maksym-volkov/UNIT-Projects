/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:49:58 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/10 18:54:15 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

int				is_4k_plus_one(int num)
{
	num--;
	if (num == 0)
		return (0);
	if (!(num % 4))
		return (1);
	return (0);
}