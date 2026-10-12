# Lab 8 — Part D Pseudocode Analysis
PROCEDURE FindAndCountActive(sortedIds, isActive, count, targetId)
    first = 0
    last = count - 1
    found = false

    WHILE first <= last AND found is false
        middle = (first + last) / 2

        IF sortedIds[middle] = targetId
            found = true
        ELSE IF sortedIds[middle] < targetId
            first = middle + 1
        ELSE
            last = middle - 1
        END IF
    END WHILE

    activeCount = 0
    FOR index = 0 TO count - 1
        IF isActive[index] is true
            activeCount = activeCount + 1
        END IF
    END FOR

    RETURN found, activeCount
END PROCEDURE

## D1 — Search and scan pseudocode
**Answer:La primera sección implementa una búsqueda binaria (WHILE first <= last), por lo que su crecimiento es logarítmico y se clasifica como O(log n). Porque el espacio de búsqueda se divide a la mitad en cada iteración del ciclo. La segunda sección es un bucle (FOR index = 0 TO count - 1) que recorre todo el arreglo de manera secuencial para evaluar el estado de cada actividad. Su crecimiento es lineal, clasificado como O(n). Al final son un O(n) y no se multiplican los costos de ambas acciones porque primero finaliza uno y luego inicia otro haciendo una suma de ambas acciones.**

PROCEDURE CountPotentialConflicts(startTimes, count)
    conflictCount = 0

    FOR first = 0 TO count - 1
        second = first + 1

        WHILE second < count
            IF startTimes[first] = startTimes[second]
                conflictCount = conflictCount + 1
            END IF

            second = second + 1
        END WHILE
    END FOR

    RETURN conflictCount
END PROCEDURE

## D2 — Potential-conflict pseudocode
**Answer: Second empieza con first + 1 para asegurar que se comparen únicamente pares distintos de actividades una sola vez. Esto evita que una actividad se compare consigo misma (first == second) y previene el procesamiento redundante de combinaciones inversas (por ejemplo, comparar el elemento 0 con el 1 y luego el 1 con el 0). La operacion representativa para ese codigo seria IF startTimes[first] = startTimes[second] el orden de crecimiento seria cuadratico y en el caso de que dupliquemos count, el numero de operaciones se cuatriplicarian como ejemplo tenemos: 2^2**


