#include <math.h>
#include <stdio.h>
double y(double x){ double result=
    3*pow(x,3)-5*pow(x,2)+4
    ;
    return result;
}
void solve()
{
    printf("Hello world");
    double fx;
    double h=0.00000000000001;
    for (double x=-10;x<=10;x+=0.5)
    {
        fx=(y(x+h)-y(x))/h;
        printf("\n\tf(%2.1lf) =%5g",x,fx);
    }
    printf("\n\tCOMPLETE..............");
}
