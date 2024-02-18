#ifndef _Grid_H
#define _Grid_H
#include <stdlib.h>
#include <stdio.h>
#include "snake.h"


/*const char* program_name;*/
/*structure de la grille de jeu*/
typedef struct Grid
{
    char ** grid;
    int nbc;
    int nbl;
}Grid;
/*fin de structure*/
void debug(Grid * grid);
void draw_grid(Grid * grid);
void place_snake(Grid * grid, Snake * serpent);
int compute_size(int w, int h, Grid * grid);
enum Element {WALL = 'w', EMPTY =' ', FRUIT= 'f',SNAKE= 's'};

enum Element move_snake(Grid * grid,Snake *serpent);

Grid* allocate_grid(int n, int m); 
void free_grid(Grid * grid); /* libère toute la mémoire occup"e par la grille)*/
#endif