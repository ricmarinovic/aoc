#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 20

int gamma(int arr[], size_t line_size)
{
    int gamma = 0;

    for (int i = 0; i < line_size; i++)
    {
        int value = arr[i] << (line_size - i - 1);
        gamma += value;
    }

    return gamma;
}

int epsilon(int arr[], int line_size)
{
    for (int i = 0; i < line_size; i++)
    {
        arr[i] = arr[i] == 0 ? 1 : 0;
    }

    return gamma(arr, line_size);
}

int part1()
{
    FILE *file = fopen("input.txt", "r");
    char line[MAX_LINE_SIZE];
    fscanf(file, "%s", line);
    size_t line_size = strlen(line);
    fseek(file, 0, SEEK_SET);

    signed int arr[line_size];
    memset(arr, 0, line_size * sizeof(int));

    while (fscanf(file, "%s", line) == 1)
    {
        for (int i = 0; i < line_size; i++)
        {
            line[i] == '0' ? arr[i]-- : arr[i]++;
        }
    }

    for (int i = 0; i < line_size; i++)
    {
        arr[i] = arr[i] >= 0 ? 1 : 0;
    }

    int g = gamma(arr, line_size);
    printf("gamma = %d\n", g);
    int e = epsilon(arr, line_size);
    printf("epsilon = %d\n", e);

    fclose(file);
    return g * e;
}

int main()
{
    printf("part 1 = %d\n", part1());
    return 0;
}
