def racine_carree(nombre: float, n: int = 100) -> float:
    if nombre < 0:
        return -1.0
    if n == 0:
        return float(nombre)
    x_prev = racine_carree(nombre, n - 1)
    result = (x_prev + nombre / x_prev) / 2
    return result
print(racine_carree(2))
print(racine_carree(2,2))
print(racine_carree(4))
print(racine_carree(-3.14))
