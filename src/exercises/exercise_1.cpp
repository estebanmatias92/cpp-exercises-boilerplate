#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Dado una grilla de "m" x "n" llena con numeros enteros, encontrar el camino desde la esquina superior izquierda hasta la esquina inferior derecha,
    el cual minimize la suma de todos los numeros en su camino.

    Retornar como entero la suma resultante.

    Nota: Solo se puede mover hacia la derecha y hacia abajo
*/
int minPathSum(int **grid, int m, int n);
int minPathSum(int **grid, int m, int n)
{
    int rows = m, cols = n;

    if (rows == 0)
        return 0;

    int **table = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        table[i] = (int *)malloc(cols * sizeof(int));

    table[0][0] = grid[0][0];

    for (int i = 1; i < rows; i++)
        table[i][0] = grid[i][0] + table[i - 1][0];

    for (int j = 1; j < cols; j++)
        table[0][j] = grid[0][j] + table[0][j - 1];

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            int left_cell = table[i][j - 1];
            int top_cell = table[i - 1][j];
            int min_value = (left_cell > top_cell) ? top_cell : left_cell;
            table[i][j] = grid[i][j] + min_value;
        }
    }

    int result = table[rows - 1][cols - 1];

    for (int i = 0; i < rows; i++)
        free(table[i]);

    free(table);

    return result;
}

void exercise_1()
{
    int rows = 5;
    int cols = 4;

    // Create matrix and fill it
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = (int)((rand() * time(NULL)) % 10); // fill grid with random numbers from 0 to 9
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Find min sum path
    int result = minPathSum(grid, rows, cols);
    printf("Suma minima: %d\n", result);

    // Free memory
    for (int i = 0; i < rows; i++)
        free(grid[i]);

    free(grid);
}