/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:53:12 by weast             #+#    #+#             */
/*   Updated: 2025/03/05 14:54:10 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 2)
		ft_printf("you HAVE NEVER typed in: %s\n", argv[1]);

    return 0;
}
