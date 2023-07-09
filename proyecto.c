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