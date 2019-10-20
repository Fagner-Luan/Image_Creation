/*Arquivo com as implementações das funções que trabalham as imagens*/
#include "imagemanip.h"

Pixel **createImage(int width, int height) {
    /*Essa função cria um ponteiro de ponteiro de Pixel, aloca dinamicamente a memoria e retorna a estrutura alocada
    *parametros: width e height, numero de colunas e linhas respectivamente
    */
    
    Pixel **img = (Pixel**)malloc(height * sizeof(Pixel*));
    
    if (img == NULL) {
        printf("Erro na alocação de memoria!\n");
        exit(2);
    }
    
    for (int i = 0; i < height; i++) {
        img[i] = (Pixel*)malloc(width * sizeof(Pixel));
    }
    Pixel defaultColor = {255, 255, 255};
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = defaultColor;
        }
    }
    
    return img;
}

void saveImage(char *fileName) {
    /*Essa função é responsável por salvar a imagem ppm;
    *parametros: fileName, o nome do arquivo a ser salvo
    */
    
    imageFile = fopen(strcat(ppmPath,fileName), "w");
    
    if (imageFile == NULL) {
        printf("Falha na abertura do arquivo\n");
        exit(1);
    }
    
    fprintf(imageFile, "P3\n");
    fprintf(imageFile, "%d %d\n", width, height);
    fprintf(imageFile, "%d\n", 255);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(imageFile, "%hhu %hhu %hhu ", image[y][x].red, image[y][x].green, image[y][x].blue);
        }
        
        fprintf(imageFile, "\n");
    }
}


void destroyImage(Pixel **image, int height) {
    
    /*Essa função é responsável por liberar as memorias alocadas dinamicamente;
    *Parametros: image, variavel(matriz) a ser liberada;
    *Parametro: height, o numero de linhas da matriz a ser liberada
    */
    
    
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}


void openImage(char *fileName) {
    
    /*Essa função é responsável por carregar uma imagem a partir da especificação open;
    *Parametro: fileName, o nome do arquivo ppm a ser aberto.
    */
    
    newImgFile = fopen(strcat(ppmPath,fileName),"r");
    
    if (newImgFile == NULL) {
        printf("Falha na abertura do arquivo\n");
        exit(1);
    }
    
    char imageCode[4];//Codigo da imagem
    fscanf(newImgFile,"%s",imageCode);
    fscanf(newImgFile,"%d %d",&width, &height);
    fscanf(newImgFile,"%d", &quality);
    
    image = createImage(width, height);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(newImgFile, "%hhu %hhu %hhu", &image[y][x].red, &image[y][x].green, &image[y][x].blue);
        }
    }
}