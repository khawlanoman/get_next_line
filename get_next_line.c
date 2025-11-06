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
    char    *all_buffer;
    int     i;
    ssize_t     read_byte;
    
    i = 0;
    while (read_byte > 0)
    {
       read_byte = read(fd, buffer, BUFFER_SIZE);
       if (read_byte == 0)
       {
            break;
       }
       else if (read_byte == -1)
       {
            return ("error");
       }
        all_buffer = ft_strjoin(all_buffer, buffer);
        
    }
    
    

}