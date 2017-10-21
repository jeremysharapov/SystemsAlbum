#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listheader.h"

void main(){
  int index;
  struct song_node *test = (struct song_node *)malloc(sizeof(struct song_node));
  struct song_node *pnt = test;
  strcpy(test -> artist, "bob");
  strcpy(test -> name, "test");
  test = insert_song_order(test, "pearl jam", "alive");
  test = insert_song_order(test, "pink floyd", "time");
  test = insert_song_order(test, "radiohead", "paranoid android");
  
  printf("\nTesting print_node\n");
  print_node(test);
  
  printf("\nTesting print_list\n");
  print_list(test);
  
  printf("\nTesting find_node\n");
  find_node(test, "pink floyd", "time");
  find_node(test, "pink floyd", "dime");
  
  printf("\nTesting find_artist\n");
  find_artist(test, "pearl jam");
  find_artist(test, "pink floyd");
  find_artist(test, "bad");
  
  printf("\nTesting random\n");
  srand(1);
  rando(test);
  srand(time(NULL));
  rando(test);
  srand(2000);
  rando(test);
  srand(50);
  rando(test);
  srand(666);
  rando(test);
  srand(69);
  rando(test);

  printf("\nTesting remove\n");
  test = remove_song(test, "bob", "test");
  test = remove_song(test, "bob", "test");
  test = remove_song(test, "pink floyd", "time");

  printf("\nTesting free_list\n");
  free_list(test);
}
