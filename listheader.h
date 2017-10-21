struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_node(struct song_node *song);

void print_list(struct song_node *letter);

struct song_node *insert_song_front(struct song_node *old, char *art, char *song);

struct song_node *insert_song_order(struct song_node *old, char *art, char *song);

struct song_node *find_artist(struct song_node *start, char art[256]);

struct song_node *find_node(struct song_node *start, char art[256], char song[256]);

struct song_node *remove_song(struct song_node *start, char art[256], char song[256]);

struct song_node *rando(struct song_node *start);

struct song_node *free_list(struct song_node *letter);
