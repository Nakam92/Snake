#ifndef _Snake_H
#define _Snake_H
#include <stdlib.h>
#include <stdio.h>
#define SNAKE_SIZE 4

typedef struct coord
{
    int x,y;
    struct coord * next;
}Coord;

enum Direction{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

typedef struct struc_snake
{
    Coord * segments_list;
    enum Direction dir;
    int size;
}Snake;

void crawl(Snake * serpent, int nbc, int nbl);
Snake* new_snake();
void add_segment(Snake * serpent, int x, int y);
void free_snake(Snake* serpent);

#endif
