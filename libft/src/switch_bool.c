/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_bool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:49:11 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/15 11:04:36 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	switch_bool(short v)
{
	if (v == 1)
		v = 0;
	else if (v == 0)
		v = 1;
	else
		v = 0;
	return (v);
}
