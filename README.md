# 🔀 push_swap – Algoritmo de ordenación con restricciones

`push_swap` es un proyecto en C que implementa un algoritmo de ordenación eficiente utilizando un conjunto limitado de operaciones sobre pilas.
El objetivo es ordenar una pila de números en la menor cantidad de movimientos posibles.

## 🚀 Características
- Implementación de un algoritmo óptimo para ordenar números con reglas específicas.
- Uso de dos pilas (`stack A` y `stack B`) y un conjunto de operaciones predefinidas.
- Optimización basada en la cantidad mínima de movimientos.
- Manejo de errores para entradas inválidas.
- El algoritmo utilizado consiste en calcular cual es el elemento con menos costo de pasar al stack B ordenado para pasarlo y después llevarlos de vuelta al stack A.

## 🎯 Operaciones disponibles
- `sa`, `sb`, `ss` → Intercambia los dos primeros elementos de la pila.
- `pa`, `pb` → Mueve el primer elemento de una pila a la otra.
- `ra`, `rb`, `rr` → Rota la pila hacia arriba.
- `rra`, `rrb`, `rrr` → Rota la pila hacia abajo.

## 🛠️ Compilación e instalación
Para compilar `push_swap`, usa:
```bash
make
```
Esto generará el ejecutable push_swap, que puedes ejecutar con:
```bash
./push_swap "4 67 3 87 23"
```
