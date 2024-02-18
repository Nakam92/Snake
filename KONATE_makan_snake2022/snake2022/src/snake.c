#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#define SNAKE_SIZE 4

void crawl(Snake * serpent, int nbc, int nbl){

    int i;
    int dx=0; /* direction selon x*/
    int dy=0; /*direction selon y*/
    Coord * current = serpent->segments_list; /*coordonnée current*/ 
    Coord * prev = NULL; /* coordonnée précédente*/

    if(serpent->dir == LEFT){
      dy=-1;

      /*coordonnee.x = (serpent->pos[0].x-1+NBC)%NBC;
      coordonnee.y = serpent->pos[0].y;*/
    }
    else if (serpent->dir == RIGHT){
      dy=1;

      /*coordonnee.x = (serpent->pos[0].x+1+NBC)%NBC;
      coordonnee.y = serpent->pos[0].y;*/
    }

    else if (serpent->dir == TOP){
      dx=-1;

      /*coordonnee.x = serpent->pos[0].x;
      coordonnee.y = (serpent->pos[0].y-1+NBL)%NBL;*/
      }
    else if (serpent->dir == BOTTOM) {
      dx=1;

      /*coordonnee.x = serpent->pos[0].x;
      coordonnee.y = (serpent->pos[0].y+1+NBL)%NBL;*/
    }

    for(i=SNAKE_SIZE-1;i>0;i--){
            /*serpent->pos[i]=serpent->pos[i-1];*/
            prev = current;
            current= current->next;
            prev->x = current->x;
            prev->y = current->y;
    }
    /*serpent->pos[0]=coordonnee;*/
    prev->next->x = (prev->x+dx+nbc)%nbc;
    prev->next->y = (prev->y+dy+nbl)%nbl;
}

Snake* new_snake()
{
  Snake* snake;
  snake = malloc(sizeof(Snake));
  snake->size = 0;
  snake->segments_list = NULL;

  return snake;

}

void add_segment(Snake * serpent, int x, int y){

    Coord* position = malloc(sizeof(Coord));
    Coord * current = serpent->segments_list;
    Coord * prev = NULL;
    if(position == NULL){
      fprintf(stderr,"Erreur  d'allocation dynamique\n");
      exit(1);
   }

    position->x = x;
    position->y = y;
    position->next = NULL;



    if(serpent->segments_list == NULL)
    {
        serpent->segments_list = position;
        return;
    }

    while(current != NULL)
    {
        prev = current;
        current = current -> next;
    }

    prev->next = position;

}

void free_snake(Snake* serpent){

  Coord* free_segment;

  while (serpent->segments_list != NULL)
  {
      free_segment = serpent->segments_list;

      serpent->segments_list = serpent->segments_list->next;

      free(free_segment);
  }

  free(serpent);

}