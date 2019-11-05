#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listMethods.h"
#include "libraryMethods.h"

//Add song nodes.
void add_song(char *a, char *n) {
  int index = *(a+0) - 97;
  library[index] = insert_front(library[index], a, n);
}

//Search for a song given song and artist name (return a pointer).
struct song_node * search(char *a, char *n) {
  struct song_node * found = malloc(sizeof(struct song_node));
  int index = *(a+0) - 97;
  found = find_song(library[index], a, n);
  return found;
}

// Search for an artist.
struct song_node * search_artist(char *a) {
  struct song_node * found = malloc(sizeof(struct song_node));
  int index = *(a+0) - 97;
  found = find_artist(library[index],a);
  return found;
}

// Print out all the entries under a certain letter.
void print_letter(char *l) {
  int index = *(l+0) - 97;
  if (library[index] != NULL) {
    printf("%s list:\n", l);
    print_songs(library[index]);
  }
  else {
    printf("%s: no songs with %s letter\n", l, l);
  }
}

// Print out all the songs of a certain artist
void print_artist(char *a) {
  int index = *(a+0) - 97;
  find_artist(library[index], a);
}

//Print out the entire library.
void print_library() {
  printf("Printing Library ....\n");
  char * letters = "abcdefghijklmnopqrstuvwxyz";
  int index;
  for (index = 0; index<26;index++) {
    if (library[index] != NULL) {
      printf("%c list\n", *(letters+index));
      print_songs(library[index]);
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
void delete_song(char *a, char *n) {
  int index = *(a+0)-97;
  printf("Deleting %s by %s: \n", n, a);
  removeNode(library[index],a,n);
}

 // Clear the library.
 void clear() {
   int i = 0;
   for (i = 0; i<26;i++) {
     library[i] = free_songs(library[i]);
   }
 }
