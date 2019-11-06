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


	int ponots = numberOfPoints;
	Point first, last;

	first = points[0];
	last = points[pontos-1];

	for (int i = 0; i < pontos; i++) {
		drawLine(points[i], points[(i+1)%n], color);
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


void insertPixel(int x, int y, Pixel color)
{
	/*Essa função é responsável por inserir uma cor no pixel determinado;
	 *Parametros: x e y as coordenadas e color a cor a pintar a imagem.
	*/
	
	image[x][y] = color;
}


void drawCircle(int xc, int yc, int x, int y, Pixel color) 
{
	/*Função responsável por plotar os pixels do circulo;
	 *Parametros: xc e xy, as coordenadas x e y
	              x e y valores recebidos da função para desenhos do circulo de Bresenham
		      color a cor a pintar a imagem;
       */
	
	insertPixel(xc+x, yc+y, color); 
    	insertPixel(xc-x, yc+y, color); 
    	insertPixel(xc+x, yc-y, color); 
    	insertPixel(xc-x, yc-y, color); 
    	insertPixel(xc+y, yc+x, color); 
    	insertPixel(xc-y, yc+x, color); 
    	insertPixel(xc+y, yc-x, color); 
    	insertPixel(xc-y, yc-x, color); 
}


void bresenhamCircle(int xc, int yc, int radius, Pixel color)
{
	/*Função responsável por fazer o circulo ditamente;
	 *Parametros: xc e yc, coordenadas do centro da imagem
	              radius, o raio do circulo
		      color a cor a pintar a imagem
        */
	
	int x, y, d;
	
	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	
	drawCircle(xc, yc, x, y);
	
	while (y >= x) {
		x++;
		
		if (d > 0) {
			y--;
			d += 4 * (x - y) + 10;
		}
		else {
			d += 4 * x + 6;
			drawCircle(xc, yc, x, y);
		}
	}
}
