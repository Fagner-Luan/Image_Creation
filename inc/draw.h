#ifndef DRAW_H
#define DRAW_H
/*Arquivo com as assinaturas das funções de desenho na imagem*/

void cleanImage(Pixel clearColor);

void drawCircle(int radius, Point point);

void drawPolygon(int numberOfPoints, Point *points);

void fill(int i, int j, Pixel pixelColor, Pixel paintColor);

void drawRect(int numberOfPoints, Point *points);

void drawLine(Point p1, Point p2, Pixel color);

#endif
