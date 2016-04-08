double suma(double x,double y)
{
    double suma;
    suma=x+y;
    return suma;
}

double resta(double x,double y)
{
    double resta;
    resta=x-y;
    return resta;
}
double division(double x,double y)
{
    double division;
    division=x/y;
    return division;
}
double multiplicacion(double x, double y)
{
    double multiplicacion;
    multiplicacion=x*y;
    return multiplicacion;
}
double factorial(double x)
{
    double resp;
    if(x==1)
    return 1;
    resp=x*factorial(x-1);
    return resp;
}
