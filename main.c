#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listMethods.h"

int main(){
  //creating a list
  // printf("%s\n", "----------------------Printing empty list:-------------------");
  struct song_node * list_head;
  list_head = NULL;
  // print_songs(list_head);


  printf("\n%s\n", "-------------------------Adding artists and songs-------------------------");
  list_head = insert_front(list_head,"radiohead","street spirit");
  list_head = insert_front(list_head,"pink floyd","time");
  list_head = insert_front(list_head,"radiohead","paranoid android");
  list_head = insert_front(list_head,"pearl jam","yellow ledbetter");
  list_head = insert_front(list_head,"pearl jam","even flow");
  list_head = insert_front(list_head,"pearl jam","alive");
  list_head = insert_front(list_head,"ac/dc","thunderstruck");
  print_songs(list_head);

  printf("\n%s\n", "-------------------------Testing print node-------------------------");
  print_song(list_head);

  printf("\n%s\n", "-------------------------Testing find song-------------------------");
  struct song_node * found;
  printf("%s\n", "looking for [pearl jam: alive]");
  find_song(list_head, "pearl jam","alive");
  printf("%s\n", "looking for [bts: make it right]");
  find_song(list_head, "bts", "make it right");

  printf("\n%s\n", "-------------------------Testing find artist-------------------------");
  printf("%s\n", "looking for [pearl jam]");
  find_artist(list_head, "pearl jam");

  printf("\n%s\n", "-------------------------Testing free songs-------------------------");
  list_head = free_songs(list_head);
  printf("list after freed list: ");
  print_songs(list_head);

  return 0;
}
