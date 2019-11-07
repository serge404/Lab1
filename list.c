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
  list_t *l = malloc(sizeof(list_t));
  //l->head->value = 0;
  //l->hytt5head->next = NULL;
  return l;
}

void list_free(list_t *l) 
{
  
}

void list_print(list_t *l) 
{
  
}

int list_length(list_t *l) 
{ 
  
}

void list_add_to_back(list_t *l, elem value) 
{
  
}

void list_add_to_front(list_t *l, elem value) 
{
  
}

void list_add_at_index(list_t *l, elem value, int index) 
{
  
}

elem list_remove_from_back(list_t *l)
{ 
  
  
}

elem list_remove_from_front(list_t *l) 
{ 
  
}

elem list_remove_at_index(list_t *l, int index) 
{ 
  
}

bool list_is_in(list_t *l, elem value) 
{
  
}

elem list_get_elem_at(list_t *l, int index) 
{ 
  
}

int list_get_index_of(list_t *l, elem value)
{
  
}