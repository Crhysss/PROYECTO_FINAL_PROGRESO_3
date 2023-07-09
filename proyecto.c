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
// Función para guardar las citas en un archivo de texto
void guardarCitas() {
    FILE *archivo;
    archivo = fopen("citas.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < numCitas; i++) {
        fprintf(archivo, "%s;%s;%d;%s;%s;%d\n", citas[i].nombre, citas[i].apellido, citas[i].cedula,
                citas[i].fecha, citas[i].especialidad, citas[i].hora);
    }

    fclose(archivo);
}
int main() {
    cargarCitas();

    int opcion;
    do {
        printf("Sistema de Agendamiento de Citas\n");
        printf("1. Agregar cita\n");
        printf("2. Mostrar citas\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarCita();
                break;
            case 2:
                mostrarCitas();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}