#include <stdio.h>
#include <math.h>

#include "time.h"

boolean IsTIMEValid(int H, int M, int S)
{
    return (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)));
}

void CreateTime(TIME *T, int HH, int MM, int SS)
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME(TIME *T)
{
    int H, M, S;
    scanf("%d %d %d", &H, &M, &S);
    while (!IsTIMEValid(H, M, S))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }
    CreateTime(T, H, M, S);
}

void TulisTIME(TIME T)
{
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik(TIME T)
{
    return (3600 * Hour(T)) + (60 * Minute(T)) + Second(T);
}

TIME DetikToTIME(long N)
{
    TIME T;
    N = N % 86400;
    if (N < 0)
    {
        N += 86400;
    }
    Hour(T) = N / 3600;
    N = N % 3600;
    Minute(T) = N / 60;
    Second(T) = N % 60;
    return T;
}

boolean TEQ(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}

boolean TNEQ(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
}

boolean TLT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

TIME NextDetik(TIME T)
{
    long detik = TIMEToDetik(T);
    detik += 1;
    return DetikToTIME(detik);
}

TIME NextNDetik(TIME T, int N)
{
    long detik = TIMEToDetik(T);
    detik += N;
    return DetikToTIME(detik);
}

TIME PrevDetik(TIME T)
{
    long detik = TIMEToDetik(T);
    detik -= 1;
    return DetikToTIME(detik);
}

TIME PrevNDetik(TIME T, int N)
{
    long detik = TIMEToDetik(T);
    detik -= N;
    return DetikToTIME(detik);
}

long Durasi(TIME TAw, TIME TAkh)
{
    if (TGT(TAw, TAkh))
    {
        return ((TIMEToDetik(TAkh) + 86400) - TIMEToDetik(TAw));
    }
    else
    {
        return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    }
}