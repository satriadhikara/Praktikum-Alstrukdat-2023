#include <stdio.h>

int main()
{
    int n, m, satu, dua, i = 2;
    scanf("%d", &n);
    scanf("%d", &m);
    satu = m;
    scanf("%d", &m);
    if (satu < m)
    {
        dua = satu;
        satu = m;
    }
    else
    {
        dua = m;
    }
    for (i = 2; i < n; i++)
    {
        scanf("%d", &m);
        if (satu < m)
        {
            dua = satu;
            satu = m;
        }
        else if (dua < m)
        {
            dua = m;
        }
    }
    printf("%d\n", dua);
    return 0;
}