#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include <MLV/MLV_all.h>
#include <getopt.h>

#define X 640
#define Y 480
#define DIFFICULTY 4

int nb_fruits(Grid *grid)
{
    int i, j;
    int nb = 0;
    for (i = 0; i < (grid->nbl); i++)
    {
        for (j = 0; j < (grid->nbc); j++)
        {
            if (grid->grid[i][j] == FRUIT)
            {
                nb += 1;
            }
        }
    }
    printf("nombre de fruits : %d \n", nb);
    return nb;
}

int count_nb_ligne(FILE *f)
{
    int nb = 0;
    char c;

    while (!feof(f))
    {
        c = fgetc(f);

        if (c == '\n')
        {

            nb++;
        }
    }
    return nb;
}

void copy(char *source, char *grid)
{
    int i;
    for (i = 0; source[i] != '\0' && source[i] != '\n'; i++)
    {
        grid[i] = source[i];
    }
}

int main(int argc, char *argv[])
{
    /* déclarations des variables : a mettre au début de la fonction pour respecter la norme ANSI */
    int i, nbl, nbc;
    int k;
    int loop_count;
    enum Element nb;
    MLV_Keyboard_button touche;
    Snake *snake;
    /*Coord tab[SNAKE_SIZE];*/
    FILE *stream;
    Grid *g;
    char *buf;
    size_t size_buf;
    int next_option;
    const char *short_opt = "hi:";

   /* const char *program_name;*/

    char filename[] = "";

    const struct option long_opt[] = {
        {"help", 0, NULL, 'h'},
        {"grid", 1, NULL, 'i'},
        {NULL, 0, NULL, 0}};

   /* program_name = argv[0];*/
    next_option = 0;

    while (next_option != -1)
    {
        next_option = getopt_long(argc, argv, short_opt, long_opt, NULL);
        switch (next_option)
        {
        case 'h':
            printf("Snake 2022\n");
            printf("-h : Help\n");
            printf("-i Chemin_fichier : pour lancer avec une grille\n");
            printf("Vous pouvez lancer le jeu avec la commande bin/snake\n");
            return 0;

        case 'i':
            strcpy(filename, optarg);
            break;
        default:
            break;
        }
    }
    /*si l'option -i n'est pas utilisé*/
    if (strcmp(filename, "") == 0)
    {
        printf("Aucun fichier n'a été sélectionné, on utilise donc le fichier par défault\n");
        strcpy(filename, "src/levels/default");
    }

    stream = fopen(filename, "r");
    /* si le fichier est introuvable*/
    if (stream == NULL)
    {
        printf("Introuvable, utilisation de la grille par défaut \n");
        stream = fopen("src/levels/default", "r");
    }

    buf = NULL;
    size_buf = 0;

    nbl = count_nb_ligne(stream);
    rewind(stream);
    nbc = getline(&buf, &size_buf, stream);

    if (nbc == -1)
    {
        printf("Erreur, le fichier est mal formé");
        exit(1);
    }

    else
        nbc--;

    g = allocate_grid(nbl, nbc);
    copy(buf, g->grid[0]);

    for (i = 1; i < nbl; i++)
    {
        int size_tmp = getline(&buf, &size_buf, stream);

        if (size_tmp != nbc + 1)
        {
            printf("Il y a un problème, il faut quitter le programme");
            exit(1);
        }
        copy(buf, g->grid[i]);
    }

    free(buf);
    fclose(stream);

    nb = nb_fruits(g);

    /* création du serpent*/
    snake = new_snake();
    snake->size = SNAKE_SIZE;
    for (k = 0; k < SNAKE_SIZE; k++)
    {
        add_segment(snake, 2, k + 1);
    }
    snake->dir = RIGHT;
    place_snake(g, snake);

    

    MLV_create_window("SNAKE", "3R-IN1B", X, Y); /* création de l'écran de jeu*/
    MLV_change_frame_rate(30); /*images par secondes*/

    loop_count = 0; 

    while (
        MLV_get_event(
            &touche, NULL, NULL,
            NULL, NULL,
            NULL, NULL, NULL,
            NULL) == MLV_NONE ||
        touche != MLV_KEYBOARD_ESCAPE)
    {

        MLV_clear_window(MLV_COLOR_SPRING_GREEN);

        loop_count = (loop_count + 1) % DIFFICULTY;

        if (loop_count == 0)
        {
            enum Element recup = move_snake(g, snake);
            /* Affichage de l'écran de fin de jeu pour chaque cas*/
            if (recup == FRUIT)
            {
                nb--;
                if (nb == 0)
                {
                    MLV_clear_window(MLV_COLOR_GREEN);
                    MLV_draw_text(250, 225, "VOUS AVEZ GAGNE", MLV_COLOR_BLACK);
                    MLV_actualise_window();
                    MLV_wait_seconds(5);
                    exit(0);
                }
            }
            if (recup == WALL)
            {
                MLV_clear_window(MLV_COLOR_RED);
                MLV_draw_text(175, 225, "PERDU! TU AS TOUCHE UN MUR", MLV_COLOR_BLACK);
                MLV_actualise_window();
                MLV_wait_seconds(5);
                exit(0);
            }
            if (recup == SNAKE)
            {
                MLV_clear_window(MLV_COLOR_RED);
                MLV_draw_text(175, 225, "PERDU! TU T'ES MORDU LA QUEUE", MLV_COLOR_BLACK);
                MLV_actualise_window();
                MLV_wait_seconds(5);
                exit(0);
            }

        
        }

        draw_grid(g);
        MLV_actualise_window();

        /* Affectation des touches directionneles du clavier pour chaque direction du serpent*/
        switch (touche)
        {
        case MLV_KEYBOARD_DOWN:
            snake->dir = BOTTOM;
            break;
        case MLV_KEYBOARD_UP:
            snake->dir = TOP;
            break;
        case MLV_KEYBOARD_LEFT:
            snake->dir = LEFT;
            break;
        case MLV_KEYBOARD_RIGHT:
            snake->dir = RIGHT;
            break;
        default:
            break;
        }

        touche = MLV_KEYBOARD_NONE;
        MLV_delay_according_to_frame_rate();
    }
    /*libération de la mémoire*/
    free_snake(snake);
    free_grid(g);

    MLV_free_window();

    /* fin de la fonction */
    return 0;
}