
/*
    El número de estudiantes será 5 y de asignaturas 3.
    El programa debe ser capaz de realizar las siguientes tareas:
        Calcular el promedio de calificaciones para cada estudiante.
        Calcular el promedio por asignatura.
        Encontrar la calificación más alta y baja por estudiante y por asignatura.
        Determinar cuántos estudiantes aprobaron o reprobaron cada asignatura. (Nota aprobatoria ≥ 6).

Requisitos:

    El programa debe pedir las calificaciones de cada estudiante en cada asignatura.
    Validar que las calificaciones ingresadas estén en el rango de 0 a 10.

Entrada:

    Un conjunto de calificaciones para cada estudiante y cada asignatura.

Salida:

El programa debe mostrar:

    El promedio de calificaciones por estudiante.
    El promedio de calificaciones por asignatura.
    La calificación más alta y baja por estudiante y por asignatura.
    El número de estudiantes aprobados y reprobados por asignatura.

EXTRA: AGREGAR COMO INPUT AGREGAR NOMBRE DE MATERIA CON OTRO ARRAY
*/
#include <stdio.h>
#include <string.h> //lib para strcspn

#define NUM_ESTUDIANTES 5  //numero de estudiantes
#define NUM_ASIGNATURAS 3  //numero de asignaturas

//funcion validarnota sirve para asegurarse el ragno, se llama en la funcion manin
float validarNota(float nota) {
    if (nota < 0 || nota > 10) {
        printf("Error, el rango de notas es entre 0 y 10.\n");
        return -1;
    }
    return nota;
}

int main() {
    char estudiantes[NUM_ESTUDIANTES][50];
    char asignaturas[NUM_ASIGNATURAS][50];
    float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS];

    // Solicitar nombres de las asignaturas
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        fgets(asignaturas[j], 50, stdin);
        asignaturas[j][strcspn(asignaturas[j], "\n")] = 0;
    }

    // Solicitar nombres de los estudiantes
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i], 50, stdin);
        estudiantes[i][strcspn(estudiantes[i], "\n")] = 0;
    }

    // Solicitar calificaciones
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            do {
                printf("Ingrese la calificación de %s en %s: ", estudiantes[i], asignaturas[j]);
                scanf("%f", &calificaciones[i][j]);
            } while (validarNota(calificaciones[i][j]) == -1); //funcionvalidarnota, si es -1 se "borra"
        }
    }

    // calculo de promedio, nota max y min por estudiante
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        float sumaEstudiante = 0, maxEstudiante = 0, minEstudiante = 10;

        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            float nota = calificaciones[i][j];
            sumaEstudiante += nota;
            if (nota > maxEstudiante) maxEstudiante = nota;
            if (nota < minEstudiante) minEstudiante = nota;
        }

        printf("\nEstudiante: %s\n", estudiantes[i]);
        printf("Promedio: %.2f\n", sumaEstudiante / NUM_ASIGNATURAS);
        printf("Nota más alta: %.2f\n", maxEstudiante);
        printf("Nota más baja: %.2f\n", minEstudiante);
    }

    // calculo de promedio, nota max y min por asignatura y número de aprobados y reprobados
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        float sumaAsignatura = 0, maxAsignatura = 0, minAsignatura = 10;
        int aprobados = 0, reprobados = 0;

        for (int i = 0; i < NUM_ESTUDIANTES; i++) {
            float nota = calificaciones[i][j];
            sumaAsignatura += nota;
            if (nota > maxAsignatura) maxAsignatura = nota;
            if (nota < minAsignatura) minAsignatura = nota;
            if (nota >= 6) aprobados++;
            else reprobados++;
        }

        printf("\nAsignatura: %s\n", asignaturas[j]);
        printf("Promedio de la asignatura: %.2f\n", sumaAsignatura / NUM_ESTUDIANTES);
        printf("Nota más alta de la asignatura: %.2f\n", maxAsignatura);
        printf("Nota más baja de la asignatura: %.2f\n", minAsignatura);
        printf("Estudiantes aprobados: %d\n", aprobados);
        printf("Estudiantes reprobados: %d\n", reprobados);
    }

    return 0;
}
