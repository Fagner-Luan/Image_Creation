#ifndef STRUCTURES_H
#define STRUCTURES_H
/*Arquivo contendo as definições de estruturas e algumas estruturas usadas no projeto*/

#include <stdio.h>
#include <stdlib.h>

//Tipo pixel para as imagens
typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}Pixel;

//Tipo Boolean para o funcionamento do projeto
typedef enum{False, True}Bool;

//Tipo Point para armazenar uma coordenada
typedef struct
{
    int x;
    int y;
}Point;

/*Estruturas necessárias para o projeto*/

//variavel para a imagem
static Pixel **image;

//altura e largura da imagem
static int width, height;

//variaveis para caminhos dos arquivos
static char txtPath[] = "../TXT/";

static char ppmPath[] = "../ppm/";

#endif
