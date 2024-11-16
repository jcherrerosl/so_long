/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:41:31 by juanherr          #+#    #+#             */
/*   Updated: 2024/11/15 13:48:52 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printerror(char *error_msg)
{
	ft_putstr_fd("\033[31mError\n", 2);
	ft_putendl_fd(error_msg, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}
