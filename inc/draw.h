#ifndef DRAW_H
#define DRAW_H
/*Arquivo com as assinaturas das funções de desenho na imagem*/
#include "structures.h"

void cleanImage(Pixel clearColor);

void drawCircle(int xc, int yc, int x, int y, Pixel color);

void bresenhamCircle(int xc, int yc, int radius, Pixel color);

void drawPolygon(int numberOfPoints, Point *points, Pixel color);

void fill(int i, int j, Pixel pixelColor, Pixel paintColor);

void drawRect(int numberOfPoints, Point *points, Pixel color);

void drawLine(Point p1, Point p2, Pixel color);

void insertPixel(int x, int y, Pixel color);

#endif
