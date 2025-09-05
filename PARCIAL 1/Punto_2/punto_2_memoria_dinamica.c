#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de estudiante
typedef struct {
    char *nombre;      // memoria dinámica para nombre
    char *apellido;    // memoria dinámica para apellido
    unsigned int edad : 7;  // bitfield: ocupa solo 7 bits (0-127, suficiente)
    unsigned int id : 25;   // bitfield: ocupa 25 bits (hasta 33 millones de IDs)
    float *calificaciones;  // arreglo dinámico de calificaciones
    int num_materias;       // cuántas materias tiene
} Estudiante;

// Crear un nuevo estudiante
Estudiante *crear_estudiante(const char *nombre, const char *apellido,
                             unsigned int edad, unsigned int id,
                             float *notas, int num_materias) {
    Estudiante *e = (Estudiante *) malloc(sizeof(Estudiante));
    if (!e) return NULL;

    // Guardar nombre
    e->nombre = (char *) malloc(strlen(nombre) + 1);
    strcpy(e->nombre, nombre);

    // Guardar apellido
    e->apellido = (char *) malloc(strlen(apellido) + 1);
    strcpy(e->apellido, apellido);

    // Guardar edad e ID
    e->edad = edad;
    e->id = id;

    // Guardar notas
    e->num_materias = num_materias;
    e->calificaciones = (float *) malloc(num_materias * sizeof(float));
    for (int i = 0; i < num_materias; i++) {
        e->calificaciones[i] = notas[i];
    }

    return e;
}

// Liberar memoria del estudiante
void liberar_estudiante(Estudiante *e) {
    if (!e) return;
    free(e->nombre);
    free(e->apellido);
    free(e->calificaciones);
    free(e);
}

// Mostrar información de un estudiante
void mostrar_estudiante(Estudiante *e) {
    printf("Nombre: %s %s\n", e->nombre, e->apellido);
    printf("Edad: %u\n", e->edad);
    printf("ID: %u\n", e->id);
    printf("Notas: ");
    for (int i = 0; i < e->num_materias; i++) {
        printf("%.1f ", e->calificaciones[i]);
    }
    printf("\n\n");
}

int main() {
    float notas1[] = {4.5, 3.8, 5.0};
    float notas2[] = {3.0, 3.5};

    Estudiante *e1 = crear_estudiante("Ana", "Gomez", 20, 12345, notas1, 3);
    Estudiante *e2 = crear_estudiante("Carlos", "Perez", 22, 67890, notas2, 2);

    mostrar_estudiante(e1);
    mostrar_estudiante(e2);

    // Liberar memoria (muy importante!)
    liberar_estudiante(e1);
    liberar_estudiante(e2);

    return 0;
}