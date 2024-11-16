/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:36:55 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 02:38:41 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_strchr_count(const char *s, int c)
{
    size_t	count;

    count = 0;
    while (*s)
    {
        if (*s == (unsigned char)c)
            count++;
        s++;
    }
    return (count);
}