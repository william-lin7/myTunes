#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "listMethods.h"
#include "libraryMethods.h"

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

  printf("\n%s\n", "------------------------Testing insert in order-------------------------");
  struct song_node * ordered_list;
  ordered_list = NULL;
  ordered_list = insert_front(ordered_list,"radiohead","street spirit");
  ordered_list = insert_inorder(ordered_list,"pink floyd","time");
  ordered_list = insert_inorder(ordered_list,"radiohead","paranoid android");
  ordered_list = insert_inorder(ordered_list,"pearl jam","yellow ledbetter");
  ordered_list = insert_inorder(ordered_list,"pearl jam","even flow");
  ordered_list = insert_inorder(ordered_list,"pearl jam","alive");
  ordered_list = insert_inorder(ordered_list,"ac/dc","thunderstruck");
  print_songs(ordered_list);

  printf("\n%s\n", "-------------------------Testing print node-------------------------");
  print_song(list_head);

  printf("\n%s\n", "-------------------------Testing find song-------------------------");
  struct song_node * found;
  printf("%s\n", "looking for [pearl jam: alive]");
  find_song(list_head, "pearl jam","alive");
  printf("%s\n", "looking for [bts: make it right]");
  find_song(list_head, "bts", "make it right");

  printf("\n%s\n", "-------------------------Testing random song--------------------------");
  struct song_node *random1 = malloc(sizeof(struct song_node));
  random1 = randomSong(list_head);
  printf("%s   :   %s\n", random1->artist, random1->name);

  printf("\n%s\n", "-------------------------Testing remove node--------------------------");
  print_songs(list_head);
  printf("removing [pearl jam: alive]\n");
  printf("removing [pearl jam: even flow]\n");
  removeNode(list_head, "pearl jam", "alive");
  removeNode(list_head, "pearl jam", "even flow");
  print_songs(list_head);

  printf("\n%s\n", "-------------------------Testing find artist-------------------------");
  printf("%s\n", "looking for [pearl jam]");
  find_artist(list_head, "pearl jam");

  printf("\n%s\n", "-------------------------Testing free songs-------------------------");
  list_head = free_songs(list_head);
  printf("list after freed list: ");
  print_songs(list_head);

  printf("\n%s\n", "=========================MUSIC LIBRARY TESTS========================");

  printf("\n%s\n", "------------------------Testing add song-------------------------");
  // add_song(library, "radiohead", "street spirit");
  // add_song(library, "radiohead","street spirit");
  // add_song(library, "pink floyd","time");
  // add_song(library, "radiohead","paranoid android");
  // add_song(library, "pearl jam","yellow ledbetter");
  // add_song(library, "pearl jam","even flow");
  // add_song(library, "pearl jam","alive");
  // add_song(library, "ac/dc","thunderstruck");
  add_song( "radiohead", "street spirit");
  // add_song( "radiohead","street spirit");
  // add_song( "pink floyd","time");
  // add_song( "radiohead","paranoid android");
  // add_song( "pearl jam","yellow ledbetter");
  // add_song( "pearl jam","even flow");
  // add_song( "pearl jam","alive");
  // add_song( "ac/dc","thunderstruck");
  // print_library();

  printf("\n%s\n", "------------------------Testing shuffle-------------------------");
  shuffle(ordered_list);

  return 0;
}
