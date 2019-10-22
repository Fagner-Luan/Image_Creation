/*Implementações das funções que trabalham com os arquivos e estruturas para a leitura e criação dos arquivos*/
#include "../filemanip.h"
#include "../draw.h"


void readComandFile(char *fileName)
{
    /*
     Essa função faz a leitura do arquivo de primitivas e chama as funções necessárias dependendo da primitiva lida
    *Parametros : filename, o nome do arquivo a ser lido
    */
    
    comandFile = fopen(strcat(txtPath,fileName),"r");
    
    if (comandFile == NULL) {
        printf("Falha na abertura do arquivo!\n");
        return ;
    }
    
    while (1)
    {
        fscanf(comandFile, "%s", comand);
        if (strcmp(comand, "image") == 0) {
            fscanf(comandFile, "%d %d", &width, &height);
            
            image = createImage(width, height);
        }
        else if (strcmp(comand, "color") == 0) {
            fscanf(comandFile, "%hhu %hhu %hhu", &color.red, &color.green, &color.blue);
        }
        else if (strcmp(comand, "clear") == 0) {
            fscanf(comandFile, "%hhu %hhu %hhu", &clearColor.red, &clearColor.green, &clearColor.blue);
            
            cleanImage();
        }
        else if (strcmp(comand, "rect") == 0) {
            drawRect();
        }
        else if (strcmp(comand, "circle") == 0) {
            int radius;
            fscanf(comandFile, "%d %d %d", &point.x, &point.y, &radius);
            
            drawCircle();
        }
        else if (strcmp(comand, "polygon") == 0) {
            fscanf(comandFile, "%d",&numberOfPoints);
            for (int i = 0; i < numberOfPoints; i++) {
                fscanf(comandFile,"%d %d",&points[i].x,&points[i].y);
            }
            drawPolygon();
        }
        else if (strcmp(comand, "fill") == 0) {
            fscanf(comandFile,"%d %d",&point.x, &point.y);
            
            fill();
        }
        else if (strcmp(comand, "save") == 0) {
            fscanf(comandFile,"%s",imageSaveName);
            saveImage(imageSaveName);
        }
        else if (strcmp(comand, "open") == 0) {
            fscanf(comandFile,"%s",imageOpenName);
            openImage(imageOpenName);
        }
        
        if (feof(comandFile)) {
            break;
        }
    }//While
    
}//Função


void destroyFile(FILE *file) {
    
    /*Essa função é responsável por fechar os arquivos abertos;
    *Parametros: file, o arquivo a ser fechado.
    */
    
    if (file != NULL) {
        fclose(file);
    }
}
