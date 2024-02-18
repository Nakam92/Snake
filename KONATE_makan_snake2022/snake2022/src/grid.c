#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include <MLV/MLV_all.h>

void debug(Grid *grid)
{
    int i;
    int j;
    for (i = 0; i<(grid->nbl); i++)
    {

        for (j = 0; j<(grid->nbc); j++)
        {
            printf("%c", grid->grid[i][j]);
        }

        printf("\n");
    }
}

int compute_size(int w, int h, Grid *grid)
{
    int a, min1, min2;
    min1 = w / (grid->nbc);
    min2 = h / (grid->nbl);
    if (min1 <= min2)
    {
        a = min1;
    }
    else
    {
        a = min2;
    }
    return a; 
}

void draw_grid(Grid *grid)
{
    int i, j, x, y;
    int w = MLV_get_window_width();
    int h = MLV_get_window_height();
    int a = compute_size(w, h, grid);

    for (i = 0, x = 0; i < (grid->nbl); i++, x = x + a)
    {

        for (j = 0, y = 0; j < (grid->nbc); j++, y = y + a)
        {
            if (grid->grid[i][j] == WALL)
            {
                MLV_draw_filled_rectangle(y, x, a, a, MLV_COLOR_BLACK);
            }
            else if (grid->grid[i][j] == FRUIT)
            {
                MLV_draw_filled_rectangle(y, x, a, a, MLV_COLOR_RED);
            }
            else if (grid->grid[i][j] == EMPTY)
            {
                MLV_draw_filled_rectangle(y, x, a, a, MLV_COLOR_DARK_GREEN);
            }
            else if (grid->grid[i][j] == SNAKE)
            {
                MLV_draw_filled_rectangle(y, x, a, a, MLV_COLOR_GREEN2);
            }
        }
    }
}



void place_snake(Grid *grid, Snake *serpent)
{
    int sX; /* position du serpent selon l'axe des abscisses*/
    int sY; /* position du serpent selon l'axe des ordonnées*/

    Coord *current = serpent->segments_list;
    while (current != NULL)
    {
        sX = current->x;
        sY = current->y;

        grid->grid[sX][sY] = SNAKE;
        current = current->next;
    }

    /*int i;
    for(i=0;i<SNAKE_SIZE;i++)
    {
        grid[serpent.pos[i].y][serpent.pos[i].x] = SNAKE;

    }*/
}

enum Element move_snake(Grid *grid, Snake *serpent)
{
    Coord *current = serpent->segments_list;
    Coord *prev = NULL;

    int x = serpent->segments_list->x;
    int y = serpent->segments_list->y;
    enum Element element;
    grid->grid[x][y] = EMPTY;
    crawl(serpent, grid->nbl, grid->nbc);
    while (current != NULL)
    {
        prev = current;
        current = current->next;
    }

    element = grid->grid[prev->x][prev->y];
    grid->grid[prev->x][prev->y] = SNAKE;

    return element;
}

Grid *allocate_grid(int n, int m)
{
    int i;
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    if (grid == NULL)
    {
        fprintf(stderr, "Erreur  allocation dynamique\n");
        exit(1);
    }
    grid->nbl = n;
    grid->nbc = m;

    grid->grid = (char **)malloc(sizeof(char *) * (grid->nbl));
    if (grid->grid == NULL)
    {
        fprintf(stderr, "Erreur  allocation dynamique\n");
        exit(1);
    }

    for (i = 0; i < (grid->nbl); i++)
    {
        grid->grid[i] = (char *)malloc(sizeof(char) * (grid->nbc)); /*création du tableau à deux dimensions */
    }
    return grid;
}

void free_grid(Grid *grid)
{
    int i;

    for (i = 0; i < (grid->nbl); i++)
    {
        free(grid->grid[i]); /* libération du tableau à deux dimensions */
    }

    free(grid->grid);

    free(grid);
}