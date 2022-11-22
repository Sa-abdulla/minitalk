/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:23:28 by sabdulla          #+#    #+#             */
/*   Updated: 2022/10/28 23:20:20 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_verify_args(pid_t pid, char *str)
{
	(void)pid;
	if (!str || !*str)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (sign == -1 && num >= LONG_MAX)
		return (0);
	if (sign == 1 && num >= LONG_MAX)
		return (-1);
	return (sign * num);
}

void	ft_sighandler(pid_t server_pid, char *str)
{
	int	i;
	int	err;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i & 1) == 1)
				err = kill(server_pid, SIGUSR1);
			else if ((*str >> i & 1) == 0)
				err = kill(server_pid, SIGUSR2);
			if (err < 0)
			{
				write (2, "Invalid PID \n", 14);
				return ;
			}
			usleep(150);
			i--;
		}
		str++;
	}
}

int	is_num(char *c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			n++;
		i++;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Invalid number of arguements. \n", 32);
		return (1);
	}
	if (is_num(argv[1]) != 0)
	{
		write (1, "Invalid PID\n", 12);
		return (1);
	}
	if (ft_verify_args(ft_atoi(argv[1]), argv[2]))
	{
		write(1, "Invalid Arguements. \n", 22);
		return (1);
	}
	ft_sighandler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
