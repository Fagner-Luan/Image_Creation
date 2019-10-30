/*Arquivo com as implementações das funções de desenho*/
#include "../inc/draw.h"


void cleanImage(Pixel clearColor) {
    
    /*Essa função é responsável por limpar a imagem, dada uma certa cor;
    
    *Parametros: a função não recebe parametros.
    
    */
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x] = clearColor;
        }
    }
}

void drawCircle(int radius, Point point, Pixel color) {

}

void drawPolygon(int numberOfPoints, Point *points, Pixel color) {

}

void fill(int i, int j, Pixel pixelColor, Pixel paintColor) {

}

void drawRect(int numberOfPoints, Point *points, Pixel color) {

}

void drawLine(Point p1, Point p2, Pixel color) {
    int d = 0, dx = 0, dy = 0, incE = 0, incNE = 0;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    d = 2 * dy - dx;
    incE = 2 * dy; // increm. que move para E
    incNE = 2 * (dy - dx); // increm. que move para NE
    int x = p1.x, y = p1.y;
    image[y][x] = color;
    while(x < p2.x) {
        if (d <= 0) {
            d = d + incE; // escolhe E
            x++;
        } else {
            d = d + incNE;
            x++;
            y++; // pois é maior que 45º
        }
        image[y][x] = color;
    } //fim while
}
