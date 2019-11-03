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
  list_head = insert_front(list_head,"radiohead","street spirit");
  list_head = insert_front(list_head,"pink floyd","time");
  list_head = insert_front(list_head,"radiohead","paranoid android");
  list_head = insert_front(list_head,"pearl jam","yellow ledbetter");
  list_head = insert_front(list_head,"pearl jam","even flow");
  list_head = insert_front(list_head,"pearl jam","alive");
  list_head = insert_front(list_head,"ac/dc","thunderstruck");

  print_songs(list_head);

  printf("\n%s\n", "Testing find song");
  struct song_node * found;
  found = find_song1(list_head, "pearl jam","alive");
  if (found != NULL) {
    printf("%s\n", "Song with desired artist found! ");
    print_song(found);
  }

  return 0;
}
