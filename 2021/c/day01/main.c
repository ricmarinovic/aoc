#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 10
#define ITEMS_SIZE 2000

int part1()
{
    FILE *file = fopen("input.txt", "r");
    char line[LINE_SIZE];
    int count = 0;
    int prev = atoi(fgets(line, LINE_SIZE, file));
    int curr = 0;

    while (fgets(line, LINE_SIZE, file) != NULL)
    {
        curr = atoi(line);
        count += curr > prev;
        prev = curr;
    }

    fclose(file);

    return count;
}

void arr_from_file(FILE *file, char line[], int arr[])
{
    int i = 0;

    while (fgets(line, LINE_SIZE, file) != NULL)
    {
        arr[i] = atoi(line);
        i++;
    }
}

int part2()
{
    FILE *file = fopen("input.txt", "r");
    char line[LINE_SIZE];
    int arr[ITEMS_SIZE];
    arr_from_file(file, line, arr);

    int count = 0;
    int prev = arr[0] + arr[1] + arr[2];
    int curr = 0;

    for (int i = 4; i < ITEMS_SIZE; i++)
    {
        curr = arr[i - 2] + arr[i - 1] + arr[i];
        count += curr > prev;
        prev = curr;
        curr = 0;
    }

    return count;
}

int main()
{
    printf("part 1 = %d\n", part1());
    printf("part 2 = %d\n", part2());

    return 0;
}
