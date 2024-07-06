/*LAB 2 Sistemas operativos
 */
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char nombrePrefijo[20]; /*N*/
    int cantidadFiltros = 0; /*F*/
    float factorSaturacion = 0;
    float umbralBinarizacion = 0;
    float umbralClasificacion = 0;
    char nombreCarpetaResultante[100];
    char nombreArchivoCSV[1000];
    int cantidadWorkers = 0;
    // variables de verificacion de parametros
    int N_verification = 0, f_verification = 0, umbral_verification1 = 0, umbral_verification2 = 0, W_verification = 0, C_verification = 0, R_verification = 0, p_verification = 0;

    /*getOpt*/
    int opt; // option
    /*variables para el excev del broker */

   char * f; /*cantidad de filtros*/
    char * p; /* factor de saturacion*/
    char * u; /* umbral binarizacion*/
    char * v; /*umbral clasificacion*/
    char * W; /*cantidad workers*/
    char * C; /*nombre carpeta resultante*/
    char * R; /*nombre archivo resultante*/


    while ((opt = getopt(argc, argv, "N:f:p:u:v:W:C:R:")) != -1)
    {
        /*Se realizan las asignaciones de punteros con optarg*/
        switch (opt)
        {
        case 'N':
            strcpy(nombrePrefijo, optarg);
            printf("prefijo  %s\n", nombrePrefijo);
            N_verification = 1;
            break;
        case 'f':
            cantidadFiltros = atoi(optarg);
            f_verification = 1;
             /*asignacion con optarg*/
            f = optarg;
            break;
        case 'p':
            factorSaturacion = atof(optarg);
            p_verification = 1;
             /*asignacion con optarg*/
            p = optarg;
            break;
        case 'u':
            umbralBinarizacion = atof(optarg);
            umbral_verification1 = 1;
             /*asignacion con optarg*/
            u = optarg;
            break;
        case 'v':
            umbralClasificacion = atof(optarg);
            umbral_verification2 = 1;
             /*asignacion con optarg*/
            v = optarg;
            break;
        case 'W':
            cantidadWorkers = atoi(optarg);
            W_verification = 1;
             /*asignacion con optarg*/
            W = optarg;
            break;
        case 'C':
            strcpy(nombreCarpetaResultante, optarg);
            C_verification = 1;
             /*asignacion con optarg*/
            C = optarg;
            break;
        case 'R':
            strcpy(nombreArchivoCSV, optarg);
            R_verification = 1;
             /*asignacion con optarg*/
            R = optarg;
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
    // si no se da un numero de la cantidad de filtros
    if (f_verification == 0)
    {
        cantidadFiltros = 3;
    }
    // si no se da un valor para el factor de saturacion.
    if (p_verification == 0)
    {
        factorSaturacion = 1.3;
    }
    // si no se da valores a los umbrales, por defecto toman el valor 0.5
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
    char *argv2[] = {"./lab2", "-N", f, "-f", p, "-u", u, "-v", v, "-W", W, "C",C,"R",R, NULL};

    // Crear el proceso hijo
    int pid = fork();
    if (pid == 0)
    {
        execv("./broker", argv2);
        printf("Error execv en broker");
        return 0;
    }

    return 0;
}
