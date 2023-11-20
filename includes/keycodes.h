/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:56:06 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/11 20:58:10 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KEYCODES_H__
# define __KEYCODES_H__

# ifdef __linux__
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# else
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124

# endif

#endif