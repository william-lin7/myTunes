#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listMethods.h"

//insert nodes at the front
struct song_node * insert_front(struct song_node * s, char *a, char *n){
  struct song_node* newSong;
  newSong = malloc(sizeof(struct song_node));
  strcpy(newSong->name,n);
  strcpy(newSong->artist,a);
  newSong->next = s;
  return newSong;
}

//print the entire list
void print_songs(struct song_node *n) {
  while (n != NULL) {
    printf(" %s : %s |", n->artist, n->name);
    n = n->next;
  }
  printf("\n");
}

//print singular node
void print_song(struct song_node *n) {
  printf("%s : %s\n", n->artist, n->name);
  n = n->next;
}

/**
//insert nodes in order - alphabetical by Artist then by Song
void insert_inorder(struct song_node *s, char *a, char *n){
  struct song_node* newSong = (struct song_node *)malloc(sizeof(n));
  strcpy(newSong->name,n);
  strcpy(newSong->artist,a);
  while ((s->next) != NULL && strcmp(s->artist, a) < 0){
    s = s->next;
  }
  while ((s->next) != NULL && strcmp(s->name, n) < 0 && strcmp(s->artist, a) == 0){
    s = s->next;
  }
  if (s->next == NULL){
    s->next = newSong;
    newSong->next = NULL;
  }
  else{
    struct song_node* temp = (struct song_node *)malloc(sizeof(n));
    temp = s->next;
    s->next = newSong;
    newSong->next = temp;
    free(temp);
    temp = NULL;
  }
}
**/
//sorry i commented this out first bc it was giving errors but i wasn't sure how to fix them

//find and return a pointer to a node based on artist and song name

struct song_node * find_song1(struct song_node *s, char *a, char *n) {
  while (s!=NULL) {
    if (strcmp(s->name,n) == 0 && strcmp(s->artist,a)) {
      return s;
      printf("%s\n", "found");
    }
    s = s->next;
    // printf("%s\n", "still looking");
  }
  printf("%s\n", "not found");
  return NULL; //if it's not found - not sure if this is what he wants though
}


//find and return a pointer to the first song of an artist based on artist name
struct song_node * find_song2(struct song_node *s, char *a) {
  // while (s!=NULL) {
  //   if ((s->artist).compareTo(a) == 0) {
  //     return s;
  //   }
  //   s=s->next;
  // }
  return NULL;
}

struct song_node * free_songs(struct song_node *s){
  struct song_node * previous_node;
  struct song_node * current_node = s;
  // print_list(s);

  while (current_node!=NULL) {
    previous_node = current_node;
    current_node = previous_node->next;
    printf("freeing node: %s | %s\n", previous_node->artist, previous_node->name);
    free(previous_node);
    previous_node = NULL;
  }
  current_node = NULL;
  return s;
}
