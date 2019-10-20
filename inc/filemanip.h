#ifndef FILEMANIP_H
#define FILEMANIP_H
/*Aqruivo contendo as assinaturas das funçōes que trabalham com arquivos*/

#include "imagemanip.h"
#include <string.h>

void readComandFile(char *fileName);

void destroyFile(FILE *file);

#endif