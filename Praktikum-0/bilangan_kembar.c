#include <stdio.h>

int main()
{
    int n, m, digit, flag, total = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = n; i <= m; i++)
    {
        flag = 1;
        digit = i % 10;
        int temp = i;
        while (temp >= 10 && flag == 1)
        {
            if (digit != (temp % 10))
            {
                flag = 0;
                break;
            }
            temp /= 10;
        }
        if (digit != (temp % 10))
        {
            flag = 0;
        }
        if (flag == 1)
        {
            total += 1;
        }
    }
    printf("%d\n", total);
    return 0;
}