/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:40:21 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/17 10:46:08 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_error(char *error_str)
{
	write(STDOUT_FILENO, error_str, ft_strlen(error_str));
	exit(EXIT_FAILURE);
}