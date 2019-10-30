/*Arquivo principal do programa*/
#include "../inc/filemanip.h"

int main(int argc, char *argv[])
{
	int userChoice;
	Bool keepRunning = True;
	
	int arguments = argc;
	
	do {
		
		if (arguments == 2) {
			strcpy(comandFileName, argv[1]);
		}
		else {
			printf("Digite o nome do arquivo de especificações: ");
			scanf("%s", comandFileName);
		}
		
		arguments = 0;
		
		readComandFile(comandFileName);
		
		//destroyFile(comandFile);
		//destroyFile(imageFile);
		//destroyFile(newImgFile);
		destroyImage(image, height);
		
		printf("Digite 1 para trabalhar outro arquivo ou 2 para encerrar: ");
		scanf("%d", &userChoice);
		
		if (userChoice == 2) {
			keepRunning = False;
		}
		
	}while (keepRunning);
	
	return 0;
}
