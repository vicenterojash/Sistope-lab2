/*El broker ha de llevarse la ejecucion del programa
como una especie de main */
#include <stdio.h>
#define READ 0
#define WRITE 1
#define FIN "FIN"

int main(char * argv[]){
    /* Estructura de argv*/
    /**/

    /*TODO: VER TEL TEMA DE LA BANDERA DE SALIDA */
    char * nombreArchivoSalida= argv[15];
    int factorSaturacion = atoi(argv[1]);
    
    printf("Se ejecuta el broker :)");

}