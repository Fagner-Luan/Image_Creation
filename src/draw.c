/*Arquivo com as implementações das funções de desenho*/
#include "../inc/draw.h"


void cleanImage(Pixel clearColour) {
    /*Essa função é responsável por limpar a imagem, dada uma certa cor; 
     *Parâmetros: clearColour, a cor para limpar a imagem.
    */
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x] = clearColour;
        }
    }
}



void drawPolygon(int numberOfPoints, Point *points, Pixel colour) {
	/*Essa função é responsável por desenhar os poligonos na imagem;
 *Parametros: numberOfPoints, o numero de pontos do poligono, *points o vetor de pontos do poligonos e colour a cor para o desenho
*/


	int ponots = numberOfPoints;


	for (int i = 0; i < pontos; i++) {
		drawLine(points[i], points[(i+1)%n], colour);
	}

}

void fill(int i, int j, Pixel pixelColour, Pixel paintColour) {
    /*Essa função é responsável por preencher uma determinada região da imagem com uma certa cor;
	
	*Parametros: i e j, variaveis para representar as linhas e colunas da matriz respectivamente, pixelColour e paintColour as cores do pixel do ponto escolhido e a cor a preencher respectivamente
	*/
	
	if (i >= 0 && i < height && j >= 0 && j < width && image[i][j].red == pixelColour.red && image[i][j].green == pixelColour.green && image[i][j].blue == pixelColour.blue) {
		image[i][j] = paintColor;
		fill(i - 1, j, pixelColour, paintColour);
		fill(i + 1, j, pixelColour, paintColour);
		fill(i, j - 1, pixelColour, paintColour);
		fill(i, j + 1, pixelColour, PaintColour);
	}
}

void drawRect(int numberOfPoints, Point *points, Pixel colour) {
    /*Função responsável por desenhar um retângulo;
     *Parâmetros: numberOfPoints, o número de pontos, points o vetor de pontos e colour a cor pintar a imagem
    */

    int pontos = numberOfPoints;
    
    for (int i = 0; i < pontos; i++) {
        
        drawLine(points[i], points[(i+1)%pontos], colour);
    }
}


void drawLine(Point p1, Point p2, Pixel colour){
    /*Função responsável por desenhar linhas na imagem;
     *Parâmetros: p1 e p2 as coordenadas para o desenho,
                  colour a cor a desenhar a linha.
    */


    int w = p2.x - p1.x;
    int h = p2.y - p1.y;
    int dx1, dy1, dx2, dy2;
    
    dx1 = 0;
    dy1 = 0;
    dx2 = 0;
    dy2 = 0;
    
    if (w < 0) {
        
        dx1 = -1;
    }
    else if (w > 0) {
        
        dx1 = 1;
    }
    
    if (h < 0) {
        
        dy1 = -1;
    }
    else if (h > 0) {
        
        dy1 = 1;
    }
    
    if (w < 0) {
        
        dx2 = -1;
    }
    else if (w > 0) {
        
        dx2 = 1;
    }
    
    int l = abs(w);
    int s = abs(h);
    
    if (l < s) {
        
        l = abs(h);
        s = abs(w);
        
        if (h < 0) {
            
            dy2 = -1;
        }
        else if (h > 0) {
            
            dy2 = 1;
        }
        dx2 = 0;
    }
    
    int num = l >> 1;
    
    for (int i = 0; i <= l; i++) {
        insertPixel(p1.x, p1.y, colour);
        num += s;
        
        if (num > l) {
            
            num -= l;
            p1.x += dx1;
            p1.y += dy1;
        }
        else {
            
            p1.x += dx2;
            p1.y += dy2;
        }
    }
}


void insertPixel(int x, int y, Pixel colour)
{
	/*Essa função é responsável por inserir uma cor no pixel determinado;
	 *Parametros: x e y as coordenadas e color a cor a pintar a imagem.
	*/
	
	image[x][y] = colour;
}


void drawCircle(int xc, int yc, int x, int y, Pixel colour) 
{
	/*Função responsável por plotar os pixels do circulo;
	 *Parametros: xc e xy, as coordenadas x e y
	              x e y valores recebidos da função para desenhos do circulo de Bresenham
		      colour a cor a pintar a imagem;
       */
	
	insertPixel(xc+x, yc+y, colour); 
    	insertPixel(xc-x, yc+y, colour); 
    	insertPixel(xc+x, yc-y, colour); 
    	insertPixel(xc-x, yc-y, colour); 
    	insertPixel(xc+y, yc+x, colour); 
    	insertPixel(xc-y, yc+x, colour); 
    	insertPixel(xc+y, yc-x, colour); 
    	insertPixel(xc-y, yc-x, colour); 
}


void bresenhamCircle(int xc, int yc, int radius, Pixel colour)
{
	/*Função responsável por fazer o circulo ditamente;
	 *Parametros: xc e yc, coordenadas do centro da imagem
	              radius, o raio do circulo
		      colour a cor a pintar a imagem
        */
	
	int x, y, d;
	
	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	
	drawCircle(xc, yc, x, y, colour);
	
	while (y >= x) {
		x++;
		
		if (d > 0) {
			y--;
			d += 4 * (x - y) + 10;
		}
		else {
			d += 4 * x + 6;
			drawCircle(xc, yc, x, y, colour);
		}
	}
}
