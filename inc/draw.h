#ifndef DRAW_H
#define DRAW_H
/*Arquivo com as assinaturas das funções de desenho na imagem*/
#include "structures.h"

void cleanImage(Pixel clearColour);

void drawCircle(int xc, int yc, int x, int y, Pixel colour);

void bresenhamCircle(int xc, int yc, int radius, Pixel colour);

void drawPolygon(int numberOfPoints, Point *points, Pixel colour);

void fill(int i, int j, Pixel pixelColour, Pixel paintColour);

void drawRect(int numberOfPoints, Point *points, Pixel colour);

void drawLine(Point p1, Point p2, Pixel colour);

void insertPixel(int x, int y, Pixel colour);

#endif
