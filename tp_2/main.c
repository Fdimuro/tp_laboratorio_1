#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "informes.h"
#include "ArrayEmployees.h"

#define TAM 1000



int main()
{
    char exit = 'n';
    int id = 1;
    int flag = 0;


    Employee list[TAM];    //inicializa array de empleados con len posiciones


    initEmployees(list,TAM);   //pone el flag isEmpty en true para todas las posiciones



    do
    {
        switch (FirstMenu())
        {
        case 1:
            //alta empleado
            addEmployee(list, TAM, id);
            id ++;
            break;
        case 2:
            //modificacion empleado
            for (int i=0; i<TAM; i++)
            {
                if (list[i].isEmpty == 0)
                {
                    modificationEmployee(list, TAM);
                    flag = 1;
                    break;
                }

            }
            if (flag == 0)
            {
                printf("No hay empleados activos para modificar\n");
                system("pause");
                break;
            }
            flag = 0;
            break;
        case 3:
            //Baja de empleado
            for (int i=0; i<TAM; i++)
            {
                if (list[i].isEmpty == 0)
                {
                    removeEmployee(list, TAM);
                    flag = 1;

                    break;
                }

            }

            if (flag == 0)
            {
                printf("No hay empleados activos para modificar\n");
                system("pause");
                break;
            }

            flag = 0;
            break;

        case 4:
            //INFORMES
            for (int i=0; i<TAM; i++)
            {
                if (list[i].isEmpty == 0)
                {
                    informes(list,TAM);
                    flag = 1;

                    break;
                }

            }
            if (flag == 0)
            {

                printf("No hay empleados activos para mostrar\n");
                system("pause");
                break;
            }

            flag = 0;

            break;

        case 5:
            exit = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N ", 's', 'n');

        }

    }
    while (exit !='s');


    return 0;
}
