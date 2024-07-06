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
    /**/

    if (argc != 18) {
        fprintf(stderr, "Número incorrecto de argumentos. Se esperaban 18, pero se recibieron %d.\n", argc);
        
    }

     printf("Se ejecuta el broker :)");

    /*TODO: VER TEL TEMA DE LA BANDERA DE SALIDA */
    char * nombreArchivoSalida= argv[14];
    int factorSaturacion = atof(argv[4]);
    
   
    return 0;

}