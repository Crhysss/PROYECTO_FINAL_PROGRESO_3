#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITAS 100
#define MAX_NOMBRE 50
#define MAX_FECHA 11

// Estructura que representa una cita médica
typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    int cedula;
    char fecha[MAX_FECHA];
    char especialidad[MAX_NOMBRE];
    int hora;
} Cita;

Cita citas[MAX_CITAS];  // Arreglo de estructuras Cita para almacenar las citas
int numCitas = 0;  // Variable para mantener el conteo del número de citas

// Función para guardar las citas en un archivo de texto
void guardarCitas() {
    FILE *archivo;
    archivo = fopen("citas.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }
    
    fprintf(archivo, "%-12s  %-13s  %-14s  %-16s  %-2s\n", "Nombre", "Apellido", "Cedula", "Fecha de cita", "Hora");
    
    for (int i = 0; i < numCitas; i++) {
        fprintf(archivo, "%-10s  ;  %-10s  ;  %-10d  ;  %-14s  ;  %-6d\n", citas[i].nombre, citas[i].apellido, citas[i].cedula,
                citas[i].fecha, citas[i].hora);
    }

    fclose(archivo);
}


// Función para cargar las citas desde un archivo de texto
void cargarCitas() {
    FILE *archivo;
    archivo = fopen("citas.txt", "r");

    if (archivo == NULL) {
        printf("No se encontro el archivo de citas.\n");
        return;  // Retorna sin realizar ninguna acción adicional
    }

    while (!feof(archivo)) {
    fscanf(archivo, "%[^;];  %[^;];  %d;  %[^;];  %[^;];  %d\n", citas[numCitas].nombre,
           citas[numCitas].apellido, &citas[numCitas].cedula, citas[numCitas].fecha,
           citas[numCitas].especialidad, &citas[numCitas].hora);
    numCitas++;
}


    fclose(archivo);
}

// Función para agregar una nueva cita
void agregarCita() {
    if (numCitas >= MAX_CITAS) {
        printf("Se ha alcanzado el limite de citas.\n");
        return;  // Retorna sin realizar ninguna acción adicional
    }

    Cita nuevaCita;
    printf("Ingrese los datos de la cita:\n");
    printf("Nombre: ");
    scanf("%s", nuevaCita.nombre);
    printf("Apellido: ");
    scanf("%s", nuevaCita.apellido);
    printf("Cedula: ");
    scanf("%d", &nuevaCita.cedula);
    printf("Fecha (dd/mm/aaaa): ");
    scanf("%s", nuevaCita.fecha);

    // Selección de especialidad
    int opcionEspecialidad;
    printf("Especialidad:\n");
    printf("1. Pediatria\n");
    printf("2. Odontologia\n");
    printf("3. Medicina-Interna\n");
    printf("4. Dermatologia\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcionEspecialidad);

    switch (opcionEspecialidad) {
        case 1:
            strcpy(nuevaCita.especialidad, "Pediatria");
            break;
        case 2:
            strcpy(nuevaCita.especialidad, "Odontologia");
            break;
        case 3:
            strcpy(nuevaCita.especialidad, "Medicina-Interna");
            break;
        case 4:
            strcpy(nuevaCita.especialidad, "Dermatologia");
            break;
        default:
            printf("Opción invalida. No se asignara una especialidad.\n");
            nuevaCita.especialidad[0] = '\0';
            break;
    }

    printf("Hora (9-12, 14-17): ");
    scanf("%d", &nuevaCita.hora);

    // Validar si la cita ya está agendada para esa fecha, especialidad y hora
    for (int i = 0; i < numCitas; i++) {
        if (strcmp(nuevaCita.fecha, citas[i].fecha) == 0 &&
            strcmp(nuevaCita.especialidad, citas[i].especialidad) == 0 &&
            nuevaCita.hora == citas[i].hora) {
            printf("Ya hay una cita agendada para esa fecha, especialidad y hora.\n");
            return;  // Retorna sin realizar ninguna acción adicional
        }
    }

    citas[numCitas++] = nuevaCita;
    guardarCitas();

    printf("La cita se ha agendado exitosamente.\n");
}

// Función para mostrar todas las citas agendadas
void mostrarCitas() {
    if (numCitas == 0) {
        printf("No hay citas agendadas.\n");
        return;  // Retorna sin realizar ninguna acción adicional
    }

    printf("Citas agendadas:\n");
    printf("------------------------------\n");
    for (int i = 0; i < numCitas; i++) {
        printf("Nombre: %s %s", citas[i].nombre, citas[i].apellido);
        printf("Cedula: %d\n", citas[i].cedula);
        printf("Fecha: %s\n", citas[i].fecha);
        printf("Especialidad: %s\n", citas[i].especialidad);
        printf("Hora: %d\n", citas[i].hora);
        printf("------------------------------\n");
    }
}

int main() {
    cargarCitas();

    int opcion;
    do {
        printf("Sistema de Agendamiento de Citas\n");
        printf("1. Agregar cita\n");
        printf("2. Mostrar citas\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
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
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
    }
} while (opcion != 3);

return 0;
}