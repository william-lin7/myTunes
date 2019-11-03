#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listMethods.h"

int main(){
  //creating a list
  printf("%s\n", "Printing empty list:");
  struct song_node * list_head;
  list_head = NULL;
  print_songs(list_head);

  printf("\n%s\n", "Adding artists and songs");
  list_head = insert_front(list_head, "thunderstruck", "ac/dc");
  list_head = insert_front(list_head, "alive", "pearl jam");
  list_head = insert_front(list_head, "even flow", "pearl jam");
  //list_head = insert_front(list_head, "yellow ledbetter", "pearl jam");
  list_head = insert_front(list_head, "time", "pink floyd");
  removeNode(list_head, "even flow", "pearl jam");
  // list_head = insert_front(list_head,"radiohead","paranoid android");
  print_songs(list_head);

  return 0;
}
