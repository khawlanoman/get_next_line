/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:11:11 by khnoman           #+#    #+#             */
/*   Updated: 2025/11/04 11:11:13 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
    char    *buffer;
    static char    *all_buffer;
    static char    *stash;
    static char   *line;
    int k;
    int     i;
    ssize_t     read_byte;
    
      i = 0;
      k = 0;
    read_byte = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
          return (NULL);
    while (read_byte > 0)
    {
       read_byte = read(fd, buffer, BUFFER_SIZE);
       if (read_byte == (-1))
       {  
            free (buffer);
            return (NULL);
       }
       buffer[read_byte] = '\0';
       all_buffer = ft_strjoin(all_buffer, buffer); 
       while (all_buffer[i])
       {
            if (all_buffer[i] =='\n')
            {
               line = ft_substr(all_buffer,k,i);
               stash = ft_substr(all_buffer, i + 1,(ft_strlen(all_buffer) - (i+1)));
               free(all_buffer);
               all_buffer = stash;
               return (line);
               
            }
            i++;
       }
      if (read_byte == 0)
      {
         return (NULL);
      }
    }
    free (buffer);
    return (line);
}