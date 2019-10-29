#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node * insert_front(struct song_node *n, int x){
  struct song_node *newSong = (struct song_node*)malloc(sizeof(struct song_node));
  newSong->i = x;
  newSong->next = n;
  return newSong;
}

void * insert_inorder(struct song_node *s, char *n, char *a){
  struct song_node *newSong = (struct song_node*)malloc(sizeof(struct song_node));
  newSong->name = n;
  newSong->artist = a;
  while ((s->next) != NULL && (s->a).compareTo(a) < 0){
    s = s.next;
  }
  while ((s->next) != NULL && (s->n).compareTo(n) < 0 && (s->a).compareTo(a) == 0){
    s = s.next;
  }
  if (s->next == NULL){
    s->next = newSong;
    newSong->next = NULL
  }
  else{
    struct song_node *temp = (struct song_node*)malloc(sizeof(struct song_node));
    temp = s->next;
    s->next = newSong;
    newSong->next = temp;
    free(temp);
    temp = NULL;
  }
}
