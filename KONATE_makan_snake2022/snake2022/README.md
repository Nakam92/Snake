# Titre: Snake 
Version : alpha
----------------
Un jeu de type Snake qui s'éxecute sur la console. Ecrit en C à l'aide de la bibliothèque MLV.
Le joueur gagne si le serpent mange tous les fruits. Le joueur perd si le serpent entre en collision avec un mur ou s'il se mord la queue.

## Sommaire
   -----------------

   1. Système requis

   2. Installation

   3. Contenu de l'archive

   4. Compilation

   5. Comment jouer

   -------------------

## 1. Système requis

   Système d'exploitation Linux (Ubuntu, Debian, Kali...).
   VM (Machine Virtuel) sous Linux.

## 2. Installation 

    Pour jouer au jeu, vous devez installer la library MLV.

    Installer de la bibliothèque MLV-2.0.2 sous Linux : (Debian, Ubuntu, Kali ...)

    Commencez par installer les bibliothèques sdl, sdl-gfx, sdl-mixer, sdl-ttf, sdl-image, sdl-image, xml2 et glib2.0 en tapant les commandes suivante:

	- sudo apt-get install libsdl-gfx1.2-dev libsdl1.2-dev libsdl-mixer1.2-dev 
	- sudo apt-get install libsdl-ttf2.0-dev libglib2.0-dev libxml2-dev 
	- sudo apt-get install libsdl-image1.2-dev

    Téléchargez ensuite les paquets de la bibliothèque :

    - http://download.savannah.gnu.org/releases/mlv/mlv-2.0.2/libmlv0_2.0.2-1_amd64.deb
    - http://download.savannah.gnu.org/releases/mlv/mlv-2.0.2/libmlv0-dev_2.0.2-1_amd64.deb

    (si vous utilisez un ordinateur 32 bits, vous devez utilisez les paquets http://download.savannah.gnu.org/releases/mlv/mlv-2.0.2/libmlv0_2.0.2-1_i386.deb et http://download.savannah.gnu.org/releases/mlv/mlv-2.0.2/libmlv0-dev_2.0.2-1_i386.deb à la place)

    Installez-les en tapant la commande suivante :
        sudo dpkg -i libmlv0_2.0.2-1_amd64.deb libmlv0-dev_2.0.2-1_amd64.deb
        (si vous utilisez un ordinateur 32 bits, tapez la commande suivante : sudo dpkg -i libmlv0_2.0.2-1_i386.deb libmlv0-dev_2.0.2-1_i386.deb)

    N'oubliez pas que pour compiler vos programme, il vous faut les outils de compilation. Si vous n'avez pas encore installé ces outils, tapez la commande suivantes:
        sudo apt-get install build-essential

## 3. Contenu de l'archive

Un dossier snake2022 contenant : 
    - Makefile : Fichier utilisés par le programme make pour exécuter un ensemble d'actions, comme la compilation d'un projet etc. 
    - README.txt : Fichier que vous lisez actuellement


    Sous répertoire doc : composé de deux documents
        user.pdf : Contient le manuel d'utilisiation du programme pour l'utilisateur
        dev.pdf : un manuel developpeur pour le projet, destiné à expliquer l'architechture du projet

    Sous répertoire src contenant : 
        Grid.txt : Fichier contenant une grille pré

	    Fichiers .c :
            -game.c : Fichier source qui contient le main et la boucle principale de jeu
            -grid.c : Fichier source qui contient tous les fonctions attenant à la grille
            -snake.c : Fichier source qui contient tous les fonctions attenant au snake

	    Fichiers .h :
            -grid.h : Headers du fichier grid.c contenant les prototypes et structures.
            -snake.h : Headers du fichier snake.c contenant les prototypes et structures.
        
        Sous répertoire"levels":
		    -default.txt : Grille par défaut si l'option -i n'est pas utilisé
    
    Sous répertoire bin : 
        vide lorsqu'on décompresse l'archive, et contenant les .o et le (ou les) exécutables après compilation



## 4. Compilation

    Pour éxecuter  ce jeu, vous devez vous rendre dans le fichier que vous avez décompressé.
    Vous devez par la suite vous déplacer dans le fichier snake via le terminal à l'aide de la commande cd.
    Une fois dans le fichier snake2022 vous pouvez compiler en tapant la commande make.
    ------
    Execution
    Pour éxecuter le programme, tapez la commande : "bin/snake" dans le dossier  KONATE_makan_snake2022/snake2022
    Vous avez l'option de lancez une grille de jeu prédéfinie en tapant la commande : bin/snake suivie de "-i src/grid.txt"

## 5. Comment joouer
    
    Pour savoir comment jouer veuillez lire le document user.pdf

BON JEU !

