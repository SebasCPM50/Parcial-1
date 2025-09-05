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
