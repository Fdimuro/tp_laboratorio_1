#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


float sumarNumeros (float a, float b)
{
    float suma;

    suma = a + b;

    return suma;
}

float RestarNumeros (float a, float b )
{
    float resta;

    resta = a - b;

    return resta;
}

float MultiplicarNumeros (float a, float b )
{
    float multiplicacion;

    multiplicacion = a* b;

    return multiplicacion;
}

float DividirNumeros ( float a, float b )
{
    float dividir;

    dividir = a/b ;

    return dividir;
}

int CalcularFactorial(int a)
{
    int resultado;

    if(a == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = a * CalcularFactorial(a - 1);
    }

    return resultado;

}

int mostrarOperaciones(int flag1, int flag2, int flagOperaciones, float a, float b){

        if(flag1==1 && flag2==1){
            printf("\ta) Calcular la suma de: %.2f + %.2f \n",a,b);
            printf("\tb) Calcular la resta de: %.2f - %.2f \n",a,b);
            printf("\tc) Calcular la multiplicacion %.2f x %.2f \n",a,b);
            printf("\td) Calcular la division de %.2f / %.2f \n",a,b);
            printf("\te) Calcular el factorial de %d! y %d! \n",a,b);
            flagOperaciones=1;
        }
        else if(flag1==1){
            printf("\ta) Calcular la suma de: %.2f +B \n",a);
            printf("\tb) Calcular la resta de: %.2f - B \n",a);
            printf("\tc) Calcular la multiplicacion %.2f x B \n",a);
            printf("\td) Calcular la division de %.2f / B \n",a);
            printf("\te) Calcular el factorial de %d! y B! \n",a);
        }
        else if(flag2==1){
            printf("\ta) Calcular la suma de: A+%.2f \n",b);
            printf("\tb) Calcular la resta de: A - %.2f\n",b);
            printf("\tc) Calcular la multiplicacion A x %.2f \n",b);
            printf("\td) Calcular la division de A / %.2f \n",b);
            printf("\te) Calcular el factorial de A! y %d! \n",b);
        }
        else{
            printf("\ta) Calcular la suma de: A+B \n");
            printf("\tb) Calcular la resta de: A - B \n");
            printf("\tc) Calcular la multiplicacion A x B \n");
            printf("\td) Calcular la division de A / B \n");
            printf("\te) Calcular el factorial de A! y B! \n");
        }

        return flagOperaciones;

}

void IngresarOperandos (int flag1 ,int flag2 ,float a ,float b)
{

    if(flag1==1){
        printf(" 1. Primer operador A= %.2f \n", a);
    }
    else{
        printf(" 1. Primer operador (A=x) \n");
    }

      if(flag2==1){
        printf(" 2. Segundo operador B= %.2f \n", b);
    }
    else{
        printf(" 2. Segundo operador (B=y)\n");
    }

}

void mostrarResultados(float a, float b, float suma, float resta,float multiplicacion,int flagOperaciones, int factorialA,int factorialB,int flagResultado, float division){

         if(flagResultado==2){
            printf("\ta) El resultado de la suma es: %.2f \n",suma);
            printf("\tb) El resultado de la resta es: %.2f \n", resta);
            printf("\tc) El resultado de la multiplicacion es: %.2f \n",multiplicacion);

            if(b>0){
            printf("\td) El resultado de la division es: %.2f \n", division);
            }
            else{
                printf("\td) No se puede dividir por 0 ni por un numero menor al mismo\n");
            }

            if(a>=0 && b>=0){
            printf("\te) El factorial de A: %d ! y B: %d ! \n",factorialA,factorialB);
            }
            else if(a>=0 && b<0){
                printf("\te) El factorial de A: %d y B no se puede factorear porque es menor de 0\n",factorialA);
            }
             else if(a<0 && b>=0){
                printf("\te) El factorial de B: %d y A no se puede factorear porque es menor de 0\n",factorialB);
            }
            else{
                printf("\te) No se pueden mostrar los factoreales porque son numeros negativos!\n");
            }

         }
         else{
            printf("\ta) El resultado de la suma es: A+B \n");
            printf("\tb) El resultado de la resta es: A-B \n");
            printf("\tc) El resultado de la multiplicacion es: A*B \n");
            printf("\td) El resultado de la division es: A/B \n");
            printf("\te) El factorial de : A! y B! \n");
         }




}










