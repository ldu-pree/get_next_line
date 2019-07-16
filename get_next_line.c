/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:44:52 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/07/16 12:55:11 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	//checks the length of the line so it stops when it either reaches a newline character or a null character
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		//sets line equal to the string of s[fd] that startsat 0 and ends at len
		*line = ft_strsub(s[fd], 0, len);
		//allocates memory for a string of size s[fd] and len and 1 byte extra for null and copies from s[fd] to tmp
		tmp = ft_strdup(s[fd] + len + 1);
		//frees s[fd] to prevent leaks
		free(s[fd]);
		//sets s[fd] to tmp the result of the copy
		s[fd] = tmp;
		//now checks if the start of the string is equal to null if so then deletes the string
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	//ret is the amount of bytes the function reads from filedescriptor
	/*checking for valid inputs*/
	if (fd < 0 || line == NULL)
		return (-1);
	/*while the bytes it reads from the file of fd into buf is bigger than 0*/
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		//final character is null since it is a string it needs to end with null
		buf[ret] = '\0';
		//this creates a string that wecan read from andwrite toaswell as return
		if (s[fd] == NULL)
			//allocates it 2 bytes of memory
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		//frees s to prevent any leaks
		free(s[fd]);
		s[fd] = tmp;
		//searches for a newline character in buf and once found it breaks this loop
		if (ft_strchr(buf, '\n'))
			break ;
	}
	//now returns -1 if ret is smaller than 0 since there would then be no characters in the line
	if (ret < 0)
		return (-1);
	//or 0 if there is only a null character
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	//finally checks the line
	return (ft_new_line(s, line, fd, ret));
}
