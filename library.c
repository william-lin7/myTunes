#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listMethods.h"
#include "libraryMethods.h"

//Add song nodes.
void add_song(char *a, char *n) {
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  while (strcmp((letters+i),&a[0]) != 0 && i <= 25) {
    i++;
    printf("%d, %c, %c\n",i, *(letters+i), a[0]);
  }
  if (strcmp(&letters[i], &a[0]) == 0) {
    printf("value??\n");
    insert_inorder(&library[i], a, n);
    printf("%c ,%c, inserted!\n", letters[i], a[0]);
  }
}

//Search for a song given song and artist name (return a pointer).
struct song_node * search(struct song_node *s, char *a, char *n) {
  struct song_node * found = malloc(sizeof(struct song_node));
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (i = 0; i <26; i++) {
    if (strcmp(&letters[i],&a[0])) {
      found = find_song(&library[i], a, n);
    }
  }
  return found;
}

// Search for an artist.
struct song_node * search_artist(struct song_node *s, char *a) {
  struct song_node * found = malloc(sizeof(struct song_node));
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (i = 0; i <26; i++) {
    if (strcmp(&letters[i],&a[0])) {
      found = find_artist(&library[i],a);
    }
  }
  return found;
}

// Print out all the entries under a certain letter.
void print_letter(struct song_node *s, char *l) {
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (i = 0; i<26;i++) {
    if (strcmp(&letters[i],l)) {
      print_songs(&library[i]);
    }
  }
}

// Print out all the songs of a certain artist
void print_artist(char *a) {
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (i = 0; i<26;i++) {
    if (strcmp(&letters[i],&a[0])) {
      find_artist(&library[i], a);
    }
  }
}

//Print out the entire library.
void print_library() {
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (i = 0; i<26;i++) {
    if (&library[i] != NULL) {
      printf("Printing %c list\n", letters[i]);
      print_songs(&library[i]);
    }
  }
}

//Shuffle - print out a series of randomly chosen songs.
void shuffle(struct song_node *s) {
  struct song_node *countingNode = malloc(sizeof(struct song_node));
  countingNode = s;
  int size = 0;
  while (countingNode != NULL){
    size++;
    countingNode = countingNode->next;
  }
  int i = 10;
  while (i > 0){
    struct song_node *dummy = s;
    int randNum = rand() % size;
    while (randNum > 0){
      dummy = dummy->next;
      randNum--;
    }
    print_song(dummy);
    i--;
  }
  free(countingNode);
  countingNode = NULL;
}

// Delete a song
void delete_song(struct song_node *s, char *a, char *n) {
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (i = 0; i<26;i++) {
    if (strcmp(&letters[i],&a[0])) {
      removeNode(s,a,n);
    }
  }
}

 // Clear the library.
 void clear(struct song_node *s) {
   int i = 0;
   for (i = 0; i<26;i++) {
     free_songs(&library[i]);
   }
 }
