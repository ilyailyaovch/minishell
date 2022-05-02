/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:42:28 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 12:15:57 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_buff_line(int fd, char *line)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!(ft_strchr(line, '\n')) && (bytes != 0))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free (buff);
	return (line);
}

char	*ft_find_real_line(char *memory)
{
	int		coun;
	int		len_line;
	char	*line;

	coun = 0;
	len_line = 0;
	if (!memory[0])
		return (NULL);
	while (memory[len_line] && memory[len_line] != '\n')
		len_line++;
	line = (char *)malloc(sizeof(char) * (len_line + 1 + 1));
	if (!line)
		return (NULL);
	while (memory[coun] && memory[coun] != '\n')
	{
		line[coun] = memory[coun];
		coun++;
	}
	if (memory[coun] == '\n')
	{
		line[coun] = memory[coun];
		coun++;
	}
	line[coun] = '\0';
	return (line);
}

char	*ft_get_next_buff_line(char *remain)
{	
	char	*str;
	int		len_line;
	int		coun;

	len_line = 0;
	coun = 0;
	while (remain[len_line] && remain[len_line] != '\n')
		len_line++;
	if (!remain[len_line])
	{
		free(remain);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remain) - len_line + 1));
	if (!str)
		return (NULL);
	len_line = len_line + 1;
	while (remain[len_line])
		str[coun++] = remain[len_line++];
	str[coun] = '\0';
	free (remain);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*memory;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!memory)
	{
		memory = (char *)malloc(sizeof(char));
		memory[0] = '\0';
	}
	memory = ft_get_buff_line(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_find_real_line(memory);
	memory = ft_get_next_buff_line(memory);
	return (line);
}
