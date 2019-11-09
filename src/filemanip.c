/*Implementações das funções que trabalham com os arquivos e estruturas para a leitura e criação dos arquivos*/
#include "../inc/filemanip.h"
#include "../inc/draw.h"


void readComandFile(char *fileName)
{
    /*
     Essa função faz a leitura do arquivo de primitivas e chama as funções necessárias dependendo da primitiva lida
    *Parametros : filename, o nome do arquivo a ser lido
    */
    
    FILE *comandFile = fopen(strcat(txtPath,fileName),"r");
    
    if (comandFile == NULL) {
        printf("Falha na abertura do arquivo!\n");
        return ;
    }

    char comand[61];
    Pixel colour;
    
    while (True)
    {
        fscanf(comandFile, "%s", comand);
        if (strcmp(comand, "image") == 0) {
            
            fscanf(comandFile, "%d %d", &width, &height);
            
            image = createImage(width, height);
        }
        else if (strcmp(comand, "colour") == 0) {
            
            fscanf(comandFile, "%hhu %hhu %hhu", &colour.red, &colour.green, &colour.blue);
        }
        else if (strcmp(comand, "clear") == 0) {
            Pixel clearColour;
            fscanf(comandFile, "%hhu %hhu %hhu", &clearColour.red, &clearColour.green, &clearColour.blue);
            
            cleanImage(clearColour);
        }
        else if (strcmp(comand, "rect") == 0) {
            int numberOfPoints;
            fscanf(comandFile,"%d",&numberOfPoints);
            Point points[numberOfPoints];

            for (int i = 0; i < numberOfPoints; i++) {
                fscanf(comandFile,"%d %d",&points[i].x, &points[i].y);
            }

            drawRect(numberOfPoints, points, colour);
        }
        else if (strcmp(comand, "circle") == 0) {
            int radius;
            int xc, yc;
            fscanf(comandFile, "%d %d", &xc, &yc);
            
            bresenhamCircle(int xc, int yc, int radius, colour);
        }
        else if (strcmp(comand, "polygon") == 0) {
            int numberOfPoints;
            fscanf(comandFile,"%d",&numberOfPoints);
            Point points[numberOfPoints];
            
            fscanf(comandFile, "%d",&numberOfPoints);
            for (int i = 0; i < numberOfPoints; i++) {
                fscanf(comandFile,"%d %d",&points[i].x,&points[i].y);
            }
            drawPolygon(numberOfPoints,points, colour);
        }
        else if (strcmp(comand, "fill") == 0) {
            Point point;
            Pixel paintColour;
            fscanf(comandFile,"%d %d %hhu %hhu %hhu",&point.x, &point.y, &paintColour.red, &paintColour.green,
            &paintColour.blue);
            if (point.x < 0 || point.x > height - 1 || point.y < 0 || point.y > width -1) {
                printf("Coordenadas inválida!\n");
                return;
            }
            Pixel pixelColour = image[point.x][point.y];
            
            fill(point.x, point.y, pixelColour, paintColour);
        }
        else if (strcmp(comand, "save") == 0) {
            char imageSaveName[61];
            fscanf(comandFile,"%s",imageSaveName);
            saveImage(imageSaveName);
        }
        else if (strcmp(comand, "open") == 0) {
            char imageOpenName[61];
            fscanf(comandFile,"%s",imageOpenName);
            openImage(imageOpenName);
        }
        else if (strcmp(comand, "line") == 0) {
            Point p1, p2;
            fscanf(comandFile, "%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
            drawLine(p1, p2, colour);
        }
        
        if (feof(comandFile)) {
            break;
        }
    }//While

    fclose(comandFile);
    
}



