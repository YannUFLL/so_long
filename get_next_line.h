/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:14:00 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/13 01:12:37 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_extract_line(char *str_save);
char	*ft_update_save(char *str_save);
size_t	ft_strlenG(const char *s);
int		ft_strchrG(const char *s, int c);
char	*ft_strjoin_andfree_s1(char *s1, const char *s2);
size_t	ft_strlcpyG(char *dst, char *src, size_t dstsize);
int		ft_check_endfile(char *str_line, int control);

#endif
