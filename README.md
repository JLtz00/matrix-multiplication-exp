# Matrix Multiplication: Standard vs Strassen

## Descripción

Este proyecto tiene como objetivo comparar empíricamente el rendimiento del algoritmo clásico de multiplicación de matrices (Θ(n³)) con el algoritmo de Strassen (Θ(n^2.81)), siguiendo el enfoque de Divide and Conquer.

El propósito principal es determinar el tamaño de entrada ( n_0 ) a partir del cual Strassen supera al algoritmo estándar en tiempo de ejecución.

---

## Objetivos

* Implementar ambos algoritmos de multiplicación de matrices.
* Diseñar un experimento controlado y reproducible.
* Medir tiempos de ejecución para distintos tamaños de matrices.
* Identificar empíricamente el punto de cruce ( n_0 ).

---

## Enfoque experimental (plan inicial)

El experimento se desarrollará considerando:

* Evaluación en múltiples tamaños de entrada ( n )
* Generación controlada de matrices (mismos datos para ambos algoritmos)
* Repetición de mediciones para reducir ruido
* Uso de medidas estadísticas (media o mediana)
* Comparación directa de tiempos de ejecución

---

## Tecnologías

* Lenguaje: C++
* Compilador: g++
* Medición de tiempo: `chrono`
* Control de versiones: Git + GitHub

---

## Estructura del proyecto

```
matrix-multiplication-exp/
│── src/          # Implementaciones
│── include/      # Headers
│── experiments/  # Scripts de ejecución
│── results/      # Datos obtenidos
│── plots/        # Gráficos
│── report/       # Informe final
```

---

## Estado del proyecto

🔄 En desarrollo (Día 1)

Actualmente se está definiendo el diseño experimental y la estructura del repositorio. Las implementaciones de los algoritmos se añadirán progresivamente.

---

## Notas

Este proyecto forma parte de una actividad académica sobre análisis de algoritmos.
El contenido será actualizado conforme avance el desarrollo del experimento.
