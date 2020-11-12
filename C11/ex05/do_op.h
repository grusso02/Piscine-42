/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:29:10 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 10:33:53 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void	rec(int nb);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_add(int a, int b);
int		ft_minus(int a, int b);
int		ft_divide(int a, int b);
int		ft_multiply(int a, int b);
int		ft_modulo(int a, int b);

#endif
