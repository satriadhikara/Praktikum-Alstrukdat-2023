#include <stdio.h>
#include <math.h>

#include "point.h"

void CreatePoint(POINT *P, float x, float y)
{
    Absis(*P) = x;
    Ordinat(*P) = y;
}

void BacaPOINT(POINT *P)
{
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT(POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2)
{
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2)
{
    return !EQ(P1, P2);
}

boolean IsOrigin(POINT P)
{
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P)
{
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P)
{
    return Absis(P) == 0;
}

int Kuadran(POINT P)
{
    if (Absis(P) > 0 && Ordinat(P) > 0)
    {
        return 1;
    }
    else if (Absis(P) < 0 && Ordinat(P) > 0)
    {
        return 2;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

POINT NextX(POINT P)
{
    Absis(P) += 1;
    return P;
}

POINT NextY(POINT P)
{
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf(POINT P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(P) *= -1;
    }
    else
    {
        Absis(P) *= -1;
    }
    return P;
}

float Jarak0(POINT P)
{
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}

float Panjang(POINT P1, POINT P2)
{
    if (EQ(P1, P2))
    {
        return 0;
    }
    else
    {
        return sqrt(pow(fabs(Absis(P1)) + fabs(Absis(P2)), 2) + pow(fabs(Ordinat(P1)) + fabs(Ordinat(P2)), 2));
    }
}

void Geser(POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P)
{
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(*P) *= -1;
    }
    else
    {
        Absis(*P) *= -1;
    }
}

void Putar(POINT *P, float Sudut)
{
    float x, y;
    x = Absis(*P);
    y = Ordinat(*P);
    Sudut *= (3.1415 / 180);
    Absis(*P) = x * cos(Sudut) + y * sin(Sudut);
    Ordinat(*P) = (-x * sin(Sudut)) + y * cos(Sudut);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2)
{
    int a, b;
    a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    b = Ordinat(P1) - (a * Absis(P1));
    printf("(%d,%d)", a, b);
}
