/*
** list.c for List in /home/mei/Rendu/sudoki-bi/fini/srcs/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 01:40:11 2016 Michel Mancier
** Last update Sun Feb 28 20:40:39 2016 Jean PLANCHER
*/

#include "list.h"

static t_list	*get_newnode(int i, int j, int n)
{
  t_list	*ret;

  ret = malloc(sizeof(t_list));
  if (ret != NULL)
    {
      ret->i = i;
      ret->j = j;
      ret->nb_val = n;
      ret->next = NULL;
    }
  return ret;
}

void	free_list(t_list **head)
{
  t_list	*tmp;

  while ((tmp = *head) != NULL)
    {
      *head = (*head)->next;
      free(tmp);
    }
}

void	add_to_head(t_list **head, int i, int j, int n)
{
  t_list	*elem;

  elem = get_newnode(i, j, n);
  if (elem != NULL)
    {
      elem->next = *head;
      *head = elem;
    }
}

void	insert_order(t_list **head, t_list *elem)
{
  if (*head == NULL)
    {
      *head = elem;
      elem->next = NULL;
    }
  else if ((*head)->nb_val < elem->nb_val)
    insert_order(&(*head)->next, elem);
  else
    {
      elem->next = *head;
      *head = elem;
    }
}

t_list	*sort_list(t_list *list)
{
  t_list	*curr;
  t_list	*list2;
  t_list	*tmp;

  list2 = NULL;
  curr = list;
  while (curr != NULL)
    {
      tmp = curr->next;
      insert_order(&list2, curr);
      curr = tmp;
    }
  return (list2);
}
