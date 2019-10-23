#ifndef STRUCTURES_H
#define STRUCTURES_H
/*Arquivo contendo as definições de estruturas e algumas estruturas usadas no projeto*/

#include <stdio.h>
#include <stdlib.h>


#define MAX_TAM 100

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

//variavel para armazenar o numero de pontos 
static int numberOfPoints;

//vetor de pontos
static Point points[MAX_TAM];

//Estruturas necessárias para o projeto

//variavel para a imagem
static Pixel **image;

//variavel para o arquivo de especificações
static FILE *comandFile = NULL;

//variavel para o arquivo da imagem
static FILE *imageFile = NULL;
static FILE *newImgFile = NULL;

//variavel para armazenar a cor escolhida
static Pixel color;

//variavel para armazenar a cor da primitiva clear
static Pixel clearColor;

//variaveis para largura e altura da imagem
static int width;
static int height;

//variaveis para os nomes dos arquivos
static char comandFileName[61];
static char imageOpenName[61];
static char imageSaveName[61];

//variavel para nome da primitiva
static char comand[31];

//variaveis para caminhos dos arquivos
static char txtPath[] = "../TXT/";

static char ppmPath[] = "../ppm/";

//variavel para o ponto da primitiva fill ou outro ponto necessario
static Point point;

//variavel para armazenar a qualidade da imagem
static int quality;

#endif
