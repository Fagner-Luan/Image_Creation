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
    
    while (True)
    {
        fscanf(comandFile, "%s", comand);
        if (strcmp(comand, "image") == 0) {
            
            fscanf(comandFile, "%d %d", &width, &height);
            
            image = createImage(width, height);
        }
        else if (strcmp(comand, "color") == 0) {
            Pixel color;
            fscanf(comandFile, "%hhu %hhu %hhu", &color.red, &color.green, &color.blue);
        }
        else if (strcmp(comand, "clear") == 0) {
            Pixel clearColor;
            fscanf(comandFile, "%hhu %hhu %hhu", &clearColor.red, &clearColor.green, &clearColor.blue);
            
            cleanImage(clearColor);
        }
        else if (strcmp(comand, "rect") == 0) {
            int numberOfPoints;
            fscanf(comandFile,"%d",&numberOfPoints);
            Point points[numberOfPoints];

            for (int i = 0; i < numberOfPoints; i++) {
                fscanf(comandFile,"%d %d",&points[i].x, &points[i].y);
            }

            drawRect(numberOfPoints, points);
        }
        else if (strcmp(comand, "circle") == 0) {
            int radius;
            Point point;
            fscanf(comandFile, "%d %d %d", &point.x, &point.y, &radius);
            
            drawCircle(radius, point);
        }
        else if (strcmp(comand, "polygon") == 0) {
            int numberOfPoints;
            fscanf(comandFile,"%d",&numberOfPoints);
            Point points[numberOfPoints];
            
            fscanf(comandFile, "%d",&numberOfPoints);
            for (int i = 0; i < numberOfPoints; i++) {
                fscanf(comandFile,"%d %d",&points[i].x,&points[i].y);
            }
            drawPolygon(numberOfPoints,points);
        }
        else if (strcmp(comand, "fill") == 0) {
            Point point;
            Pixel paintColor;
            fscanf(comandFile,"%d %d %hhu %hhu %hhu",&point.x, &point.y, &paintColor.red, &paintColor.green,
            &paintColor.blue);
            if (point.x < 0 || point.x > height - 1 || point.y < 0 || point.y > width -1) {
                printf("Coordenadas inválida!\n");
                return;
            }
            Pixel pixelColor = image[point.x][point.y];
            
            fill(point.x, point.y, pixelColor, paintColor);
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
        
        if (feof(comandFile)) {
            break;
        }
    }//While

    fclose(comandFile);
    
}



