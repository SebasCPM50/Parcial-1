# Lista de estudiantes con (nombre, nota)
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