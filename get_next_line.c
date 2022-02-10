/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguer <kmarguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:42:32 by kmarguer          #+#    #+#             */
/*   Updated: 2022/01/17 01:10:34 by kmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*string_read(int fd, char *buffer)
{
	char	*buff;
	int		counter;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	counter = 1;
	while (!ft_strchr(buffer, '\n') && counter != 0)
	{
		counter = read(fd, buff, BUFFER_SIZE);
		if (counter == -1)
		{
			free(buff);
			return (0);
		}
		buff[counter] = 0;
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*write_line(char *buffer)
{
	char	*string;
	int		counter;

	counter = 0;
	if (!*buffer)
		return (0);
	while (buffer[counter] != '\n' && buffer[counter])
		counter++;
	string = (char *)malloc(sizeof(char) * (counter + 2));
	if (!string)
		return (0);
	counter = 0;
	while (buffer[counter] != '\n' && buffer[counter])
	{
		string[counter] = buffer[counter];
		counter++;
	}
	if (buffer[counter] == '\n')
	{
		string[counter] = buffer[counter];
		counter++;
	}
	string[counter] = 0;
	return (string);
}

char	*rest_of_string(char *buffer)
{
	char	*rest;
	int		buf_c;
	int		rest_c;

	buf_c = 0;
	while (buffer[buf_c] != '\n' && buffer[buf_c])
		buf_c++;
	if (!buffer[buf_c])
	{
		free(buffer);
		return (0);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - buf_c));
	if (!rest)
		return (0);
	buf_c++;
	rest_c = 0;
	while (buffer[buf_c])
		rest[rest_c++] = buffer[buf_c++];
	rest[rest_c] = 0;
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;

	if (!(fd > -1 && BUFFER_SIZE > 0))
		return (0);
	buffer = string_read(fd, buffer);
	if (!buffer)
		return (NULL);
	string = write_line(buffer);
	buffer = rest_of_string(buffer);
	return (string);
}
