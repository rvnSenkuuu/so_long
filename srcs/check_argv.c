/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:01:21 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/18 12:44:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	check_argv(int argc, char **argv)
{
	const char	*file_extension;

	if (argc < 2)
		put_error(ERROR_USAGE);
	file_extension = ft_strrchr(argv[1], '.');
	if (!file_extension || ft_strncmp(file_extension, ".ber", 5) != 0)
		put_error(ERROR_WRONG_EXT);
}
