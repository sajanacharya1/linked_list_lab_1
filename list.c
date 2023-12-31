// list/list.c
// 
// Implementation for linked list.
//
// <Sajan Acharya>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
}


void list_free(list_t *l) {
  node_t *curr_node = l->head;
  while (curr_node != NULL){
    node_t *temp = curr_node;
    curr_node = curr_node->next;
    free(temp);
  }
  l->head = NULL;
}


void list_print(list_t *l) {
  if (l->head == NULL)
  {
    printf("Linkedlist is empty");
  }
  else
  {
    node_t* curr_node = l->head;
    while (curr_node != NULL) {
      printf("%d ", curr_node->value);
      curr_node = curr_node->next;
    }
  }
  printf("\n");
}


char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}


int list_length(list_t *l) 
{ 
  int length = 1;
  if (l->head == NULL)
  {
    length = -1;
  }
  else
  {
    node_t* curr_node = l->head;
    while (curr_node->next != NULL) {
      length += 1;
      curr_node = curr_node->next;
    }
  }
  printf("%d", length);
  return length;  
}  


void list_add_to_back(list_t *l, elem value) { 
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  if (l->head == NULL){
    l->head = new_node;
    return;
  }
  else{
    node_t* curr_node = l->head;
    while (curr_node->next != NULL){
      curr_node = curr_node->next;
    }
    curr_node->next = new_node;
  }
}


void list_add_to_front(list_t *l, elem value){
  node_t* curr_node = (node_t*) malloc(sizeof(node_t));
  curr_node->value = value;
  curr_node->next = NULL;
  if (l->head) {
    curr_node->next = l->head;      
    l->head = curr_node;
  }
  else{
    l->head = curr_node;    
  }
}


void list_add_at_index(list_t *l, elem value, int index) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t *curr_node = l->head;
    node_t *prev_node = NULL;
    int curr_index = 1;
    if (index < 1){
      return;
    }
    if (index == 1){
      new_node->next = curr_node;
      l->head = new_node;
      return;
    }
    while (curr_node != NULL && curr_index != index){
      prev_node = curr_node;
      curr_node = curr_node->next;
      curr_index++;
    }

    if (curr_index == index){
      prev_node->next = new_node;
      new_node->next = curr_node;
    }
}


elem list_remove_from_back(list_t *l) {
  if (l->head == NULL){ 
    return -1;
  }
  
  if(l->head->next == NULL){
    free(l->head);
    l->head = NULL;
    return 0;
  }
  else{
    node_t* curr_node = l->head;
    while (curr_node->next->next != NULL){
      curr_node = curr_node->next;
    }
    node_t* last_node = curr_node->next;
    curr_node->next = NULL;
    free(last_node);
    return 0;
  }
}


elem list_remove_from_front(list_t *l){
  if (l->head == NULL){
    return -1;
  }
  else{
    node_t* removed_node = l->head;
    l->head = l->head->next;
    free(removed_node);
  }
}


elem list_remove_at_index(list_t *l, int index) { 
  node_t *curr_node = l->head;
  node_t *previous_node = NULL;
  int curr_index = 1;
  if (index == 1){
    l->head = l->head->next;
    return;
  }

  while (curr_node != NULL && curr_index != index){
    previous_node = curr_node;
    curr_node = curr_node->next;
    curr_index++;
  }
  if (curr_node != NULL){
    previous_node->next = curr_node->next;
    return;
  }
  else{
   return -1; 
  }
}


bool list_is_in(list_t *l, elem value){
  node_t *curr_node = l->head;
  while (curr_node != NULL){
    if (curr_node->value == value){
      return true;
    }
    curr_node = curr_node->next;
  } 
  return false; 
}


elem list_get_elem_at(list_t *l, int index){ 
  if (l == NULL || index < 1){
    return -1;
  }
  node_t *curr_node = l->head;
  int curr_index = 1;
  while (curr_node != NULL && curr_index != index){
    curr_node = curr_node->next;
    curr_index++;
  }
  if (curr_index == index && curr_node != NULL){
    return curr_node->value;
  }
  else{
    return -1;
  }
}


int list_get_index_of(list_t *l, elem value) {
  node_t *curr_node = l->head;
  int curr_index = 1;
  while (curr_node != NULL){
    if (curr_node->value == value){
      return curr_index;
    }
    curr_node = curr_node->next;
    curr_index++;
  } 
  return -1;
}
