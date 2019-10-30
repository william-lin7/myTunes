struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *s, char *n, char *a);
void insert_inorder(struct song_node *s, char *n, char *a);
struct song_node * find_song(struct song_node *s, char *n, char *a);
