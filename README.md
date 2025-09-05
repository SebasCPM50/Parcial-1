# Parcial 1
**Paradigmas de Programación**

# Ejercicio 1 – Ordenamiento de Estudiantes  
Se pide resolver el problema con dos enfoques distintos:
1. **Programación imperativa**.  
2. **Programación declarativa/funcional**.  

Finalmente, realizar un análisis comparativo entre ambos enfoques.

# Solución Imperativa
Aquí se implementa un algoritmo de ordenamiento tipo **burbuja**, donde se van comparando e intercambiando los elementos hasta que quedan en el orden deseado.
```python
estudiantes = [
    ("Ana", 2.2),
    ("Robert", 1.1),
    ("Sebastian", 4.3),
    ("David", 2.2),
]

# Órden de manera imperativa (usando un algoritmo tipo burbuja)
for i in range(len(estudiantes)):
    for j in range(0, len(estudiantes)-i-1):
        # Comparar primero por nota (descendente)
        if estudiantes[j][1] < estudiantes[j+1][1]:
            estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]
        # Si tienen la misma nota, comparar alfabéticamente
        elif estudiantes[j][1] == estudiantes[j+1][1] and estudiantes[j][0] > estudiantes[j+1][0]:
            estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]

print("Orden imperativo:", estudiantes)
```
# Solución Declarativa / Funcional
En este enfoque se usa la función sorted de Python, indicando una clave de ordenamiento.
La regla es ordenar por nota descendente y, en caso de empate, por nombre en órden alfabético.
```python
estudiantes = [
    ("Ana", 2.2),
    ("Robert", 1.1),
    ("Sebastian", 4.3),
    ("David", 2.2),
]

# Declarativo: solo digo la regla
ordenados = sorted(
    estudiantes,
    key=lambda x: (-x[1], x[0])   # primero nota descendente, luego nombre ascendente
)

print("Orden declarativo:", ordenados)

```
# Comparaciones
## Claridad y legibilidad:
Imperativo: Es más largo y detallado, muestra paso a paso el proceso

Declarativo: Es más breve y directo, describe la regla de orden

## Expresividad y abstracción:
Imperativo: bajo nivel, explica cómo hacerlo

Declarativo: alto nivel, solo indica el qué hacer

## Estructuras de datos:
Imperativo: modifica la lista original (mutabilidad)

Declarativo: devuelve una nueva lista sin alterar la original (inmutabilidad)

## Manejo de estado:
Imperativo: el estado cambia en cada iteración

Declarativo: no se ven los cambios internos, más limpio

## Mantenimiento y extensión:
Imperativo: más difícil de modificar si se cambia la regla

Declarativo: basta con ajustar la clave de orden

## Eficiencia:
Imperativo (burbuja): complejidad O(n²), poco eficiente para listas grandes

Declarativo (sorted): usa Timsort (O(n log n)), mucho más rápido



-----------------------------------------------------------------------------------------------------

# En resumen:
El imperativo sirve para comprender el proceso interno del ordenamiento, aunque es menos eficiente.

El declarativo es más práctico, expresivo y eficiente, además de ser más fácil de mantener.

_____________________________________________________________________________________________________

# Ejercicio 2 – Gestión de Estudiantes en C con Memoria Dinámica
Struct optimizado: se usa bitfields para edad (7 bits) y id (25 bits). Así no gastamos 4 bytes enteros para cada uno

Nombre y apellido: en lugar de reservar 100 chars, usamos malloc(strlen+1). Solo ocupa lo necesario

Notas: cada estudiante tiene un array dinámico con solo las materias que cursa

Funciones:

crear_estudiante: reserva memoria y copia datos

mostrar_estudiante: imprime la info

liberar_estudiante: libera TODO (nombre, apellido, notas y el struct)

main: creamos 2 estudiantes, los mostramos y liberamos memoria

# Comparaciones

## Claridad y legibilidad:
El código tiene funciones separadas (crear, mostrar, liberar), lo cual facilita entender qué hace cada parte

## Uso de memoria:
Se reserva solo lo necesario para cadenas y calificaciones. Los bitfields reducen espacio en edad e ID

## Estructuras dinámicas:
Todo lo que puede variar (nombre largo, cantidad de materias) se maneja dinámicamente con malloc

## Manejo de estado:
El programa no guarda listas gigantes de estudiantes en memoria fija, cada registro se pide y se libera cuando se necesita

## Eficiencia:

Memoria: optimizada al máximo (solo lo necesario)

Tiempo: un poco más de trabajo al reservar memoria, pero es aceptable

## Mantenimiento y extensión:
Fácil de extender si luego queremos agregar más campos al struct (ej. dirección)

-----------------------------------------------------------------------------------------------------
# Conclusiones

El uso de memoria dinámica con malloc y free permite que cada estudiante ocupe solo el espacio estrictamente necesario, evitando desperdiciar

Con bitfields se optimizó aún más el tamaño de los registros en campos pequeños como edad e identificación

Separar las operaciones en funciones (crear, mostrar, liberar) hace que el programa sea más claro y fácil de mantener

Aunque la gestión dinámica requiere más cuidado (liberar memoria siempre), la eficiencia en uso de recursos es mucho mayor

Este enfoque combina optimización de memoria con legibilidad del código, cumpliendo el objetivo planteado

_____________________________________________________________________________________________________

# Ejercicio 3 - Cálculo del Promedio con Cálculo Lambda

El cálculo lambda es una herramienta matemática que posibilita que expliquemos el funcionamiento de la computación de forma declarativa
 
En esta situación, se solicita que la notación de este cálculo sea utilizada para representar el promedio de un conjunto de números

El promedio es un cálculo muy habitual, que se define como la suma total de los elementos de una lista dividida por el número de elementos en ella

# Definición matemática del promedio
Dada una lista de \(n\) números:  

\[
xs = [x_1, x_2, x_3, \dots, x_n]
\]

El promedio se define como:  

\[
\text{promedio}(xs) = \frac{x_1 + x_2 + x_3 + \dots + x_n}{n}
\]

# Implementación en cálculo lambda

1. **Suma de los elementos:**
\[
\text{sum} \equiv \lambda xs.\; \sum xs
\]

2. **Longitud de la lista:**
\[
\text{len} \equiv \lambda xs.\; n
\]

3. **Promedio:**
\[
\text{promedio} \equiv \lambda xs.\; \dfrac{(\text{sum}\; xs)}{(\text{len}\; xs)}
\]

---

## Ejemplo
Sea la lista:

\[
xs = [2, 4, 6]
\]

Aplicamos la función promedio:  

\[
\text{promedio}(xs) = \dfrac{2+4+6}{3} = 4
\]

# Conclusiones finales
El cálculo lambda posibilita expresar operaciones de manera **matemática** y **funcional**

Reducimos el promedio a las dos operaciones fundamentales: **contar** y **sumar**

Esta manera de escribirlo contribuye a entender el enfoque **declarativo** utilizado por lenguajes como **Haskell**
