/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguer <kmarguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:42:35 by kmarguer          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:07 by kmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*write_line(char *save);
char			*rest_of_string(char *save);
char			*string_read(int fd, char *save);

#endif
