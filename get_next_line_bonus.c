/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:49:22 by khnoman           #+#    #+#             */
/*   Updated: 2025/11/12 10:49:23 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char *read_file(int fd, char *buffer, char **stash)
{
   ssize_t  read_byte;

   read_byte = 1;
   while (read_byte > 0)
   {
      read_byte = read(fd, buffer, BUFFER_SIZE);
      if (read_byte == (-1))
      {
            free (buffer);
            return (NULL);
      }
      buffer[read_byte] = '\0';
      stash[fd] = ft_strjoin(stash[fd], buffer);
      if (!stash[fd])
         stash[fd] = ft_strdup(buffer);
      else
        stash[fd] = ft_strjoin(stash[fd], buffer);
      if (read_byte < BUFFER_SIZE)
         break ;
   }
   return (stash[fd]);
}

static char *extract_line(char **stash,int fd )
{
   int   i;
   char *line;
   char *tmp;

   i = 0;
   if (!stash[fd])
        return NULL;
   while (stash[fd][i])
   {
      if (stash[fd][i] == '\n')
      {
         line = ft_substr(stash[fd], 0, i + 1);
         tmp =  ft_substr(stash[fd], i + 1, ft_strlen(stash[fd]) - (i + 1));
         free(stash[fd]);
         stash[fd] = tmp;
         return (line);
      }
      i++;
   }
   line = ft_substr(stash[fd], 0 , ft_strlen(stash[fd]));
   free(stash[fd]);
   stash[fd] = NULL; 
   return (line);
}


char *get_next_line(int fd)
{
    char    *buffer;
    //static char    *all_buffer;
    static char    *stash[1024];
    char   *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
      return (NULL);
   buffer = malloc(BUFFER_SIZE + 1);
   if (!buffer)
      return (NULL);
   stash[fd] = read_file(fd, buffer, stash);
   free (buffer);
   if (!stash[fd])
      return (NULL);
   line = extract_line(&stash[fd], fd);
   return (line);
}