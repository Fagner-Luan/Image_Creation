/*Arquivo com as implementações das funções de desenho*/
#include "../inc/draw.h"


void cleanImage(Pixel clearColor) {
    /*Essa função é responsável por limpar a imagem, dada uma certa cor; */
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x] = clearColor;
        }
    }
}

void drawCircle(int radius, Point point, Pixel color) {

}

void drawPolygon(int numberOfPoints, Point *points, Pixel color) {
	/*Essa função é responsável por desenhar os poligonos na imagem;
 *Parametros: numberOfPoints, o numero de pontos do poligono, *points o vetor de pontos do poligonos e color a cor para o desenho
*/



	Point first, last;

	first = points[0];
	last = points[numberOfPoints-1];

	for (int i = 0; i < numberOfPoints-1; i++) {
		drawLine(points[i], points[i+1], color);
	}

	drawLine(last, first, color);

}

void fill(int i, int j, Pixel pixelColor, Pixel paintColor) {
    /*Essa função é responsável por preencher uma determinada região da imagem com uma certa cor;
	
	*Parametros: i e j, variaveis para representar as linhas e colunas da matriz respectivamente, pixelColor e paintColor as cores do pixel do ponto escolhido e a cor a preencher respectivamente
	*/
	
	if (i >= 0 && i < height && j >= 0 && j < width && image[i][j] == pixelColor) {
		image[i][j] = paintColor;
		fill(i - 1, j, pixelColor, paintColor);
		fill(i + 1, j, pixelColor, paintColor);
		fill(i, j - 1, pixelColor, paintColor);
		fill(i, j + 1, pixelColor, PaintColor);
	}
}

void drawRect(int numberOfPoints, Point *points, Pixel color) {

}

// Só está funcionando para o oitavo quadrante de Bresenham
void drawLine(Point p1, Point p2, Pixel color) {
    int d = 0, dx = 0, dy = 0, incE = 0, incNE = 0;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    d = 2 * dy - dx;
    incE = 2 * dy; // increm. que move para E
    incNE = 2 * (dy - dx); // increm. que move para NE
    int x = p1.x, y = p1.y;
    image[y][x] = color;
    while(x <= p2.x && y <= p2.y) {
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
