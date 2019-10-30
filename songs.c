#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listMethods.h"

//insert nodes at the front
struct song_node * insert_front(struct song_node *s, char *n, char *a){
  struct song_node* newSong = (struct song_node *)malloc(sizeof(s));
  newSong->name = n;
  newSong->artist = a;
  newSong->next = s;
  return newSong;
}

//insert nodes in order - alphabetical by Artist then by Song
void insert_inorder(struct song_node *s, char *n, char *a){
  /**
  struct song_node* newSong = (struct song_node *)malloc(sizeof(n));
  newSong->name = n;
  newSong->artist = a;
  while ((s->next) != NULL && (s->artist).compareTo(a) < 0){
    s = s->next;
  }
  while ((s->next) != NULL && (s->name).compareTo(n) < 0 && (s->artist).compareTo(a) == 0){
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
  **/
}
//sorry i commented this out first bc it was giving errors but i wasn't sure how to fix them 

//print the entire list
void print_list(struct song_node *n) {
  while (n != NULL) {
    printf(" %s : %s |", n->artist, n->name);
    n = n->next;
  }
  printf("%s\n", "]");
}

//find and return a pointer to a node based on artist and song name
struct song_node * find_song(struct song_node *s, char *n, char *a) {
  while (s!=NULL) {
    if (s->name == n && s->artist == a) {
      return s;
    }
  }
  return NULL; //if it's not found - not sure if this is what he wants though
}
