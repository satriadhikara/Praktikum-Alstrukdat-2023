#include <stdio.h>

int main()
{
    int digit, total = 0;
    scanf("%d", &digit);
    while (digit >= 10)
    {
        total += digit % 10;
        digit /= 10;
    }
    total += digit;
    printf("%d\n", total);
    return 0;
}