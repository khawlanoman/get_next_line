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

static char *read_file(int fd, char *buffer, char *all_buffer)
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
      all_buffer = ft_strjoin(all_buffer, buffer);
      if (!all_buffer)
         return (NULL);
      if (read_byte < BUFFER_SIZE)
         break ;
   }
   return (all_buffer);
}

static char *extract_line(char *all_buffer, char **stash)
{
   int   i;
   char *line;

   i = 0;
   while (all_buffer)
   {
      if (all_buffer[i] == '\n')
      {
         line = ft_substr(all_buffer, 0, i + 1);
         *stash =  ft_substr(all_buffer, i + 1, ft_strlen(all_buffer) - (i + 1));
         free(all_buffer);
         return (line);
      }
      i++;
   }
   line = ft_substr(all_buffer, 0 , ft_strlen(all_buffer));
   *stash = NULL;
   free(all_buffer);
   return (line);
}

static   char *handle_last_return(char *all_buffer)
{
   char *line;

   if (all_buffer && *all_buffer != '\0')
   {
      line = all_buffer;
      all_buffer = NULL;
      return (line);
   }
   free (all_buffer);
   all_buffer = NULL;
   return (NULL);
}

char *get_next_line(int fd)
{
    char    *buffer;
    static char    *all_buffer;
    static char    *stash;
    char   *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
      return (NULL);
   buffer = malloc(BUFFER_SIZE + 1);
   if (!buffer)
      return (NULL);
   all_buffer = read_file(fd, buffer, all_buffer);
   free (buffer);
   if (!all_buffer)
      return (NULL);
   line = extract_line(all_buffer, &stash);
   if (line)
   {
      all_buffer = stash;
      return (line);
   }

    return (handle_last_return(all_buffer));
}