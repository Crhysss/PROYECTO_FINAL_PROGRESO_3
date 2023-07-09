#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITAS 100
#define MAX_NOMBRE 50
#define MAX_FECHA 11

typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    int cedula;
    char fecha[MAX_FECHA];
    char especialidad[MAX_NOMBRE];
    int hora;
} Cita;

Cita citas[MAX_CITAS];
int numCitas = 0;
