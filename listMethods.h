struct song_node{
  char artist[100];
  char name[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *s, char *a, char *n);
void insert_inorder(struct song_node *s, char *a, char *n);
void print_songs(struct song_node *n);
void print_song(struct song_node *n);
struct song_node * find_song1(struct song_node *s, char *a, char *n);
struct song_node * find_song2(struct song_node *s, char *a);
struct song_node * free_songs(struct song_node *s);
