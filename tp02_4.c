#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT 5 //cantidad de computadoras

struct compu
{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef computadora;

void listarUnaComputadora(computadora *pc, int i);
void listarComputadoras(computadora *pc);
void mostrarPCMasVieja(computadora *pc);
void mostrarPCMasVeloz(computadora *pc);

void main(){
    srand(time(NULL));
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    computadora *PC;
    PC = malloc(CANT*sizeof(computadora));
    printf("==============================");
    printf("\n==========BIENVENIDO==========");
    printf("\n==============================");
    printf("\n\nCargando %i computadoras...", CANT);
    for (int i = 0; i < CANT; i++)
    {
        (PC+i)->velocidad = rand()%3+1;
        (PC+i)->anio = rand()%8+2015;
        (PC+i)->cantidad = rand()%8+1;
        (PC+i)->tipo_cpu = &tipos[rand()%6][0];
    }
    printf("\nCarga completa.");
    printf("\n==============================");
    printf("\n\nListado de computadoras:");
    listarComputadoras(PC);
    printf("\n==============================");
    printf("\n\nComputadora mas vieja:");
    mostrarPCMasVieja(PC);
    printf("\n==============================");
    printf("\n\nComputadora mas veloz:");
    mostrarPCMasVeloz(PC);
    free(PC);
}

void listarUnaComputadora(computadora *pc, int i)
{
    printf("\n  -Computadora [%i]:", i+1);
    printf("\n      Velocidad de procesamiento: %i", (pc+i)->velocidad);
    printf("\n      Anio de fabricacion: %i", (pc+i)->anio);
    printf("\n      Cantidad de nucleos: %i", (pc+i)->cantidad);
    printf("\n      Tipo de procesador: %s", (pc+i)->tipo_cpu);
}

void listarComputadoras(computadora *pc)
{
    for (int i = 0; i < CANT; i++)
    {
        listarUnaComputadora(pc, i);
    }
}

void mostrarPCMasVieja(computadora *pc)
{
    int valor = pc->anio, indice;
    for (int i = 0; i < CANT; i++)
    {
        if ((pc+i)->anio <= valor)
        {
            valor = (pc+i)->anio;
            indice = i;
        }
    }
    listarUnaComputadora(pc, indice);
}

void mostrarPCMasVeloz(computadora *pc)
{
    int valor = pc->velocidad, indice;
    for (int i = 0; i < CANT; i++)
    {
        if ((pc+i)->velocidad >= valor)
        {
            valor = (pc+i)->velocidad;
            indice = i;
        }
    }
    listarUnaComputadora(pc, indice);
}//las ultimas 2 funciones son muy similares pero no encuentro como vincularlas :(