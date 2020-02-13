/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:16:43 by ydonse            #+#    #+#             */
/*   Updated: 2019/02/14 10:18:47 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_abs(long nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}
