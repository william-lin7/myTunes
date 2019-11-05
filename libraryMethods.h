struct song_node library[26];

// void add_song(struct song_node *lib[], char *a, char *n);
void add_song(char *a, char *n);
struct song_node * search(struct song_node *s, char *a, char *n);
struct song_node * search_artist(struct song_node *s, char *a);
void print_letter(struct song_node *s, char *l);
void print_artist(char *a);
void print_library();
void shuffle(struct song_node *s);
void delete_song(struct song_node *s, char *a, char *n);
void clear(struct song_node *s);
