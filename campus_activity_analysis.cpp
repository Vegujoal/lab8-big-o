/*
 * Course: COEN 2220 - Programming 2
 * Name: [Jose Alejandro Vera Guagua]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: [10/12/2026]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer:
 *N representa un punto exacto del arreglo en activityIds[activityIndex], por lo tanto, la funcion getActivityIdAt es una O(1) operación.
 * C2 — Count active activities
 * Answer:
 *N represetna el numero de elementos total del array isActive ((isActive[index])), siendo la funcin countActiveActivities una O(n) operación.
 * C3 — Binary search
 * Answer:
 *N representa el numero de elementos total del array, (activityIds[middle] == targetId), como la funcion countBinaryComparisons es una O(log n) operación.
 *Y como es una binary search, el requisito que debe cumplir es que el arreglo activityIds debe estar ordenado de manera ascendente porque asi descarta el numero menor.
 * C4 — Halving steps
 * Answer:
 *La operacion que se repite es (itemCount = itemCount / 2), Para 16 toma 4 pasos; para 32 toma 5 pasos. Al duplicar el tamaño de la entrada, el número de pasos solo aumenta en 1.
 *La clasificacion es un O(log n).
 * C5 — Distinct pairs
 * Answer:
 *Empieza por +1 par asegurar  que no se cuente el mismo dos veces, si empieza en 0 se incluirían comparaciones de un elemento consigo mismo y se duplicarían todas las combinaciones.
 *Clasificacion, O(n^2) ya que el primer bucle recorre todos los elementos y el segundo bucle recorre todos los elementos menos los que ya se han comparado.
 * C6 — Compare the observed patterns
 * Answer:
 *El primero mantiene un rendimiento constante e instantáneo sin importar los datos.
 *El segundo crece de manera lineal respecto a n.
 *EL tercero crece de manera logaritimica.
 *El cuarto crece de manera cuadratica.
 * C7 — Sorting decision
 * Answer:
 *Es mucho mas practico cuando usar linear search para arreglos pequeños.
 *Pero cuando el arreglo es grande y se necesita hacer muchas busquedas, es mejor ordenar el arreglo y usar binary search.
 */