#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listMethods.h"

//insert nodes at the front
struct song_node * insert_front(struct song_node * s, char *a, char *n){
  struct song_node* newSong = malloc(sizeof(struct song_node));
  strcpy(newSong->name,n);
  strcpy(newSong->artist,a);
  newSong->next = s;
  return newSong;
}

//print the entire list
void print_songs(struct song_node *n) {
  while (n != NULL) {
    printf(" %s : %s \n", n->artist, n->name);
    n = n->next;
  }
  printf("\n");
}

//print singular node
void print_song(struct song_node *n) {
  printf("%s : %s\n", n->artist, n->name);
  n = n->next;
}

//insert nodes in order - alphabetical by Artist then by Song
struct song_node * insert_inorder(struct song_node *s, char *a, char *n){
  struct song_node* newSong = (struct song_node *)malloc(sizeof(n));
  strcpy(newSong->name,n);
  strcpy(newSong->artist,a);
  struct song_node *previous = s;
  struct song_node *first = s;
  if ((s == NULL) || (strcmp(s->name, n) <= 0 && strcmp(s->artist, a) <= 0)){
    newSong->next = s;
    return newSong;
  }
  s = s->next;
  while ((s->next) != NULL && strcmp(s->artist, a) > 0){
    previous = s;
    s = s->next;
  }
  while ((s->next) != NULL && strcmp(s->name, n) > 0 && strcmp(s->artist, a) == 0){
    previous = s;
    s = s->next;
  }
  if (s->next == NULL){
    s->next = newSong;
    newSong->next = NULL;
    free(previous);
  }
  else{
    previous->next = newSong;
    newSong->next = s;
    free(previous);
  }
  return first;
}

//find and return a pointer to a node based on artist and song name

struct song_node * find_song(struct song_node *s, char *a, char *n) {
  while (s!=NULL) {
    if (strcmp(s->artist,a) == 0 && strcmp(s->name,n) == 0) {
      printf("%s ", "Song with desired artist found!");
      print_song(s);
      return s;
    }
    s = s->next;
    // printf("%s\n", "still looking");
  }
  printf("%s\n", "Song not found");
  return NULL; //if it's not found - not sure if this is what he wants though
}


//find and return a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node *s, char *a) {
  while (s!=NULL) {
    if (strcmp(s->artist,a) == 0) {
      printf("%s ", "Desired artist found!");
      print_songs(s);
      return s;
    }
    s=s->next;
  }
  printf("%s\n", "Song not found");
  return NULL;
}

// removes a specific song
void removeNode(struct song_node *s, char *a, char *n){
  struct song_node *previous = malloc(sizeof(struct song_node));
  previous = s;
  if (s == NULL) return;
  if ((strcmp(s->artist, a) == 0) && (strcmp(s->name, n) == 0)){
    free(previous);
    free(s);
  }
  else{
    if (s->next == NULL){
      free(previous);
    }
    else{
      s = s->next;
      while ((s != NULL) && !(strcmp(s->artist, a) == 0) && !(strcmp(s->name, n) == 0)){
        previous = s;
        s = s->next;
      }
      previous->next = s->next;
      s->next = NULL;
      free(previous);
    }
  }
}

struct song_node * free_songs(struct song_node *s){
  struct song_node * previous_node;
  // print_list(s);

  while (s!=NULL) {
    previous_node = s;
    s = previous_node->next;
    printf("freeing node: %s | %s\n", previous_node->artist, previous_node->name);
    free(previous_node);
    previous_node = NULL;
  }
  s = NULL;
  return s;
}
