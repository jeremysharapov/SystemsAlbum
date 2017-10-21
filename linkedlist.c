#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listheader.h"

void print_node(struct song_node *song){
  printf("%s : %s\n", song -> artist, song -> name);
}

void print_list(struct song_node *letter){
  while(letter){
    printf("%s : %s | ", letter -> artist, letter -> name);
    letter = letter -> next;
  }
  printf("\n");
}

struct song_node *insert_song_front(struct song_node *old, char *art, char *song){
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  new -> next = old;
  strcpy(new -> artist, art);
  strcpy(new -> name, song);
  return new;
}

struct song_node *insert_song_order(struct song_node *old, char *art, char *song){
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  struct song_node *start = old;
  strcpy(new -> artist, art);
  strcpy(new -> name, song);
  while(strcmp(art, old -> artist) >= 0 && old -> next != NULL){
    old = old -> next;
  }
  while(strcmp(song, old -> name) >= 0 && old -> next != NULL){
    old = old -> next;
  }
  new -> next = old -> next;
  old -> next = new;
  return start;
}

struct song_node *find_artist(struct song_node *start, char *art){
  printf("looking for [%s]\n", art);
  while(start){
    if (strcmp(start -> artist, art) == 0){
      printf("artist found! ");
      print_list(start);
      return start;
    }
    start = start -> next;
  }
  printf("artist not found\n");
  return NULL;
}

struct song_node *find_node(struct song_node *start, char *art, char *song){
  printf("looking for [%s : %s]\n", art, song);
  while(start){
    if (strcmp(start -> artist, art) == 0 && strcmp(start -> name, song) == 0){
      printf("node found! ");
      print_node(start);
      return start;
    }
    start = start -> next;
  }
  printf("node not found\n");
  return NULL;
}

struct song_node *remove_song(struct song_node *start, char *art, char *song){
  struct song_node *temp = start;
  printf("removing [%s : %s]\n", art, song);
  if (strcmp(start -> artist, art) == 0 && strcmp(start -> name, song) == 0){
    temp = start -> next;
    print_list(temp);
    return temp;
  }
  while (start -> next){
    if (strcmp(start -> next -> artist, art) == 0 && strcmp(start -> next -> name, song) == 0){
      start -> next = start -> next -> next;
      print_list(temp);
      return temp;
    }
    start = start -> next;
  }
  printf("remove failed: node not found\n");
  return temp;
}

struct song_node *rando(struct song_node *start){
  int length = 0;
  struct song_node *temp = start;
  while (temp){
    length++;
    temp = temp -> next;
  }
  int rando = rand() % length;
  for (rando; rando > 0; rando--){
    start = start -> next;
  }
  print_node(start);
  return start;
}
  

struct song_node *free_list(struct song_node *letter){
  struct song_node *start = (struct song_node *)malloc(sizeof(struct song_node));
  while(letter){
    printf("freeing node: ");
    print_node(letter);
    start = letter;
    letter = letter -> next;
    free(start);
  }
  printf("list after free_list: ");
  print_list(letter);
  return letter;
}

void print_letter(char letter){
  int i = letter - 96;
  printf("%c list\n", letter);
  print_list(table[i]);
  printf("\n");
}

void print_library(){
  int i = 1;
  for (i; i < 27; i++) {
    if (table[i]){
      print_letter(96 + i);
    }
  }
}

struct song_node *find_artist_lib(char *art){
  int i = art[0] - 96;
  return find_artist(table[i], art);
}

struct song_node *find_node_lib(char *art, char *song){
  int i = art[0] - 96;
  return find_node(table[i], art, song);
}

struct song_node *remove_song_lib(char *art, char *song){
  int i = art[0] - 96;
  return remove_song(table[i], art, song);
}



void clear_library(){
  int i = 1;
  for (i; i < 27; i++){
    while(table[i]){
      free_list(table[i]);
      table[i] = NULL;
    }
  }
}

struct song_node *add_song_lib(char *art, char *song){
  int i = art[0] - 96;
  if (table[i] == NULL){
    table[i] = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(table[i] -> artist, art);
    strcpy(table[1] -> name, song);
  }
  else{
    table[i] = insert_song_order(table[i], art, song);
  }
  return table[i];
}

struct song_node *find_artist_songs(char *art){
  int i = art[0] - 96;
  struct song_node *temp = find_artist(table[i], art);
  while(strcmp(temp -> artist, art) == 0){
    print_node(temp);
    temp = temp -> next;
  }
}

void shuffle() {
  int i = rand() % 26 + 1;
  while(table[i] == NULL){
    i = rand() % 26 + 1;
  }
  rando(table[i]);
  rando(table[i]);
  rando(table[i]);
}
