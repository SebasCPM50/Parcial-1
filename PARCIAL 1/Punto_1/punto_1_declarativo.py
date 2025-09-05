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