#ifndef IMAGEMANIP_H
#define IMAGEMANIP_H
/*Arquivo contendo as assinaturas das funções que cuidam das imagens*/
#include "structures.h"


Pixel **createImage(int width, int height);

void destroyImage(Pixel **image, int height);

void saveImage(char *fileName);

void openImage(char *fileName);

#endif