/*Arquivo com as implementações das funções de desenho*/
#include "../inc/draw.h"
#include "../inc/structures.h"

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

void drawRect() {

}

void drawLine() {
    
}
