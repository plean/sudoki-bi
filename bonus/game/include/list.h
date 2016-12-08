/*
** list.h for List in /home/mei/Rendu/sudoki-bi/fini/include/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 00:51:36 2016 Michel Mancier
** Last update Sun Feb 28 01:39:36 2016 Michel Mancier
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_list
{
  int		i;
  int		j;
  int		nb_val;
  struct s_list	*next;
}		t_list;

void	free_list(t_list **head);
void	add_to_head(t_list **head, int i, int j, int n);
void	insert_order(t_list **head, t_list *elem);
t_list	*sort_list(t_list *list);

#endif /* !LIST_H_ */
