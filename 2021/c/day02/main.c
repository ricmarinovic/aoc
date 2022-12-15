#include <stdio.h>

int main()
{
    char arr[10];
    int n = 0;
    int h = 0;
    int d1 = 0;
    int d2 = 0;
    int aim = 0;

    FILE *file = fopen("input.txt", "r");
    while (fscanf(file, "%s %d", arr, &n) == 2)
    {
        switch (arr[0])
        {
        case 'f':
            h += n;
            d2 += aim * n;
            break;

        case 'u':
            d1 -= n;
            aim -= n;
            break;

        case 'd':
            d1 += n;
            aim += n;
            break;

        default:
            break;
        }
    }

    fclose(file);

    printf("part 1 = %d\n", h * d1);
    printf("part 2 = %d\n", h * d2);

    return 0;
}
