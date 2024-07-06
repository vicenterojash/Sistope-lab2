/*El broker ha de llevarse la ejecucion del programa
como una especie de main */
#include <stdio.h>
#define READ 0
#define WRITE 1
#define FIN "FIN"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <getopt.h>
#include <math.h>


int main(int argc,char * argv[]){
    /* Estructura de argv*/
    /*
    
    argv[0] = ./lab2 
argv[1] = -N 
argv[2] = imagen 
argv[3] = -f 
argv[4] = 2 (cantidad filtros)
argv[5] = -p 
argv[6] = 20 (factor saturacion)
argv[7] = -u 
argv[8] = 3 (umbral binarizacion)
argv[9] = -v 
argv[10] = 1 (umbral clasificacion)
argv[11] = -C (nombre carpeta resultante)
argv[12] = ejemplo_nombre 
argv[13] = -R (nombre de archivo resultante)
argv[14] = result 
argv[15] = -W (cantidad workers)
argv[16] = 5 
argv[17] = (null) (ultima posicion nula por necesidades de la implementacion)
*/


     printf("Se ejecuta el broker :) \n\n");

    /*TODO: VER TEL TEMA DE LA BANDERA DE SALIDA */
    char * nombreArchivoSalida= argv[14];
    float factorSaturacion = atof(argv[4]);
    float umbralBinarizacion = atof(argv[8]);
    float umbralClasificacion = atof(argv[10]);
    char * nombreCarpetaResultante= argv[12];
    char * nombreArchivoCSV= argv[14];
    int cantidadWorkers = atoi(argv[16]);

    /*Se imprime toda la informacion del array para saber si se transifirio correctamente la informacion */
    printf("Argv de Broker \n :");
    for (int i = 0; i < 18; i++)
        {
            printf("argv[%i] = %s \n", i, argv[i]);
        }

    
   
    return 0;

}