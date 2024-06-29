/*LAB 2 Sistemas operativos
*/
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "broker.h"


int main(int argc, char *argv[]) {
    char nombrePrefijo[20];
    int cantidadFiltros = 0;
    float factorSaturacion=0;
    float umbralBinarizacion=0;
    float umbralClasificacion=0;
    char nombreCarpetaResultante[100];
    char nombreArchivoCSV[1000];
    int cantidadWorkers=0;
    //variables de verificacion de parametros
    int N_verification=0, f_verification=0, umbral_verification1=0,umbral_verification2=0,W_verification=0, C_verification=0, R_verification=0, p_verification=0;

    /*getOpt*/
    int opt; //option


    while ((opt = getopt(argc,argv,"N:f:p:u:v:W:C:R:")) != -1)
    {
        switch (opt)
        {
        case 'N':
            strcpy(nombrePrefijo,optarg);
            printf("prefijo  %s\n",nombrePrefijo);
            N_verification = 1;
            break;
        case 'f':
            cantidadFiltros=atoi(optarg);
            f_verification = 1;
            break;
        case 'p':
            factorSaturacion=atof(optarg);
            p_verification = 1;
            break;
        case 'u':
            umbralBinarizacion=atof(optarg);
            umbral_verification1 = 1;
            break;
        case 'v':
            umbralClasificacion=atof(optarg);
            umbral_verification2= 1;
            break;
        case 'W':
            cantidadWorkers=atoi(optarg);
            W_verification=1;
            break;
        case 'C':
            strcpy(nombreCarpetaResultante,optarg);
            C_verification = 1;
            break;
        case 'R':
            strcpy(nombreArchivoCSV,optarg);
            R_verification = 1;
            break;
        default:
            break;
        
        }
         
    }
    if (R_verification == 0)
        {
            printf("El nombre del archivo CSV no fue ingresado\n.");
            return 0;
        }
        if (W_verification == 0)
        {
            printf("La cantidad de workers no fue ingresada.\n");
            return 0;
        }
        if (N_verification == 0)
        {
            printf("El nombre del prefijo no fue ingresado.\n");
            return 0;
        }
        if (C_verification == 0)
        {
            
            printf("El nombre de la carpeta resultante no fue ingresado.\n");
            return 0;
        }
        //si no se da un numero de la cantidad de filtros
        if (f_verification == 0)
        {
            cantidadFiltros = 3;
        }
        //si no se da un valor para el factor de saturacion.
        if (p_verification == 0)
        {
            factorSaturacion = 1.3;
        }
        //si no se da valores a los umbrales, por defecto toman el valor 0.5
        if (umbral_verification1 == 0)
        {
            umbralBinarizacion = 0.5;
        }
        if (umbral_verification2 == 0)
        {
            umbralClasificacion = 0.5;
        }

        /*
        
        CREACION DEL BROKER
        
        
        */

        return 0;}