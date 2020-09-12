#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    int flag1=0;
    int flag2=0;
    int flagOper=0;
    int flagResultado=0;
    int opcion;
    int a;
    int b;
    int suma;
    int resta;
    int multiplicacion;
    int factorialA;
    int factorialB;
    float division;


  do{


    system("cls");

    printf("\n");
    printf("~~~~~~~~~~~~~~La Calculadora~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");



    IngresarOperandos(flag1,flag2,a,b);



    printf(" 3. Calcular todas las operaciones \n\n");

    flagOper = mostrarOperaciones(flag1,flag2,flagOper,a,b);

    printf("\n");


    printf("4. Informar resultados\n\n");
    mostrarResultados(a,b,suma,resta,multiplicacion,factorialA,factorialB,flagOper,flagResultado,division);


    printf("\n5. Desea Continuar en la calculadora? S/N: \n");


    printf("===Seleccione su opcion===: ");
    scanf("%d",&opcion);
    fflush(stdin);

        switch(opcion){
        case 1:
            printf("Ingrese el primer operador: ");
            fflush(stdin);
            scanf("%d" , &a);
            flag1=1;
            break;
        case 2:
            printf("Ingrese el segundo operador: ");
            fflush(stdin);
            scanf("%d", &b);
            flag2=1;
            break;
        case 3:
            if(flagOper==1){
                printf("Calculando las operaciones...\n");
                suma = sumarNumeros(a,b);
                resta = RestarNumeros(a , b);
                multiplicacion = MultiplicarNumeros(a,b);
                division = DividirNumeros(a,b);
                factorialA=CalcularFactorial(a);
                factorialB=CalcularFactorial(b);
                printf("Se realizaron todas las operaciones con exito\n");
                flagResultado=1;
                system("pause");
            }
            else{
                printf("Error falta ingresar un operador\n");
                system("pause");
            }
            break;
        case 4:
            if(flagResultado==1 && flagOper==1){
                flagResultado=2;
            }
          else{
                if(flag1==0 || flag2==0){
                   printf("Falta algun operador y que calcule las operaciones...\n");
                    system("pause");
                }
                else{
                    printf("Falta calcular las operaciones\n");
                    system("pause");
                }
            }
            break;
        case 5:
            printf("Gracias por utilizar la calculadora\n");
            break;
        default:
            printf("Error vuelva a ingresar una opcion");
            system("pause");
            break;
        }

          }while(opcion!=5);



}
