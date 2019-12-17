// list/list.c
// 
// Implementation for linked list.
//
// Serge Selenou

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() 
{ 
  list_t *l;
  l = malloc(sizeof(list_t));
    l->head = NULL;
  return l;
}

void list_free(list_t *l) 
{
  if (l == NULL)
    return;
  node_t *current = l->head;
  node_t *next_node = NULL;
  while (current != NULL)
  {
    next_node = current->next;
    free(current);
    current = next_node;
  }
  l->head = NULL;
  free(l);
}

void list_print(list_t *l) 
{
  node_t *current = l->head;
  node_t *next_node = NULL;
  while (current->next != NULL)
  {
    printf("%d\n", current->value);
    next_node = current->next;
    current = next_node;
  }
  printf("%d\n", current->value);
}

int list_length(list_t *l) 
{ 
  int length = 0;
  node_t *current = l->head;
  while (current != NULL)
  {
    length ++;
    current = current->next;
  }
  return length; 
}

void list_add_to_back(list_t *l, elem value) 
{
  node_t *current = l->head;
  while (current->next != NULL) {
    current = current->next;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  current->next = new_node;
}

void list_add_to_front(list_t *l, elem value) 
{
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) 
{
  int i = 0;
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  
  node_t *current = l->head;
  node_t *next_node = NULL;
  
  while (current != NULL && i < index)
  {
    i++;
    next_node = current->next;
    current = next_node;
  }
  next_node = current->next;
  current->next = new_node;
  new_node->next = next_node;
}

elem list_remove_from_back(list_t *l)
{
  node_t *prev = l->head;
  node_t *current = prev->next;
  
  while (current->next != NULL)
  {
		prev = current;
    current = current->next;
  }
	prev->next = NULL;
  elem retval = current->value;
  free(current);
  return retval;  
}

elem list_remove_from_front(list_t *l) 
{ 
  node_t *current = l->head;
  l->head = current->next;
  elem retval = current->value;
  free(current);
  return retval;
}

elem list_remove_at_index(list_t *l, int index) 
{ 
  int i = 0;
  node_t *prev = l->head;
	node_t *current = prev->next;
  while (current->next != NULL && i < (index - 1))
  {
    i++;
		prev = current;
    current = current->next;
  }
  node_t *temp = current;
  prev->next = current->next;
  elem retval = temp->value;
  free(temp);
  return retval;
}

bool list_is_in(list_t *l, elem value) 
{
  node_t *current = l->head;
  while (current->next != NULL)
  {
    if (current->value == value)
      return true;
    current = current->next;
  }
  return false;  
}

elem list_get_elem_at(list_t *l, int index) 
{ 
  elem retval;
  node_t *current = l->head; 
  int count = 0; 
  while (current->next != NULL && count < index) 
  {  
    count++; 
    current = current->next;
  }
  if (current != NULL)
    retval = current->value;
	return retval; 
}

int list_get_index_of(list_t *l, elem value)
{
  int index = -1;
  node_t *current = l->head;
  
  while (current != NULL)
  {
    if (current->value == value){
			return index;
		} 
    else {
      index++;
			current = current->next;
		}
  }
  return index;
}