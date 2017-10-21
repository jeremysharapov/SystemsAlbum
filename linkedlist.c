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

struct song_node *find_artist(struct song_node *start, char art[256]){
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

struct song_node *find_node(struct song_node *start, char art[256], char song[256]){
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

struct song_node *remove_song(struct song_node *start, char art[256], char song[256]){
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
