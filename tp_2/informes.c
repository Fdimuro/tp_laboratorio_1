#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "validaciones.h"



/** \brief Ordena el vector por sector ascendente o descendente segun parametro
 *
 * \param vec[] es Employee, es vector de empleados
 * \param len es int, tamnaño del vector a recorrer
 * \param orden es int, 0 orden ascendente, 1 orden descendente
 *
 */
//informes.c
void sortEmployees (Employee list[], int len, int orden )
{

    Employee aux;

    for (int i=0; i<len-1; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (orden == 0)
            {
                if (list[i].sector > list[j].sector)
                {
                    aux = list[j];
                    list[j] = list[i];
                    list[i] = aux;
                } else if (list[i].sector == list[j].sector && strcmp(list[i].lastname,list[j].lastname)>0) {
                    aux = list[j];
                    list[j] = list[i];
                    list[i] = aux;
                }
            }
            if (orden == 1)
            {

                if (list[i].sector<list[j].sector)
                {
                    aux = list[j];
                    list[j] = list[i];
                    list[i] = aux;

                } else if (list[i].sector == list[j].sector && strcmp(list[i].lastname,list[j].lastname)>0) {
                    aux = list[j];
                    list[j] = list[i];
                    list[i] = aux;
                }
            }

        }

    }
    printEmployees(list, len);
}


/** \brief Muestra opciones de informes
 *
 * \return opcion es int, valor seleccionado por el usuario
 *
 */
int menuInformes ()
{
    int option;
    do
    {
        system("cls");
        printf("- - - - - INFORMES - - - - -\n");
        printf("Menu de optiones:\n");
        printf("1. Listar empleados por sector y apellido (ascendente)\n");
        printf("2. Listar empleados por sector y apellido (descendente)\n");
        printf("3. Listar toal y promedio de los salarios y empleados que superan el promedio\n");
        printf("4. exit\n\n");
        printf("Elija option: ");
        fflush(stdin);
        scanf("%d",&option);
    }
    while (option > 4);

    return option;

}

/** \brief muestra informes seleccionados por el usuario a traves del menu
 *
 * \param list[] es Employee, es vector de empleados
 * \param len es int, tamaño del vector a recorrer
 *
 */
void informes (Employee list[], int len)
{
    char exit = 'n';
    int promedio;

    do {

    switch (menuInformes())
    {
    case 1:
        sortEmployees(list,len,0);
        break;
    case 2:
        sortEmployees(list,len,1);
        break;
    case 3:

        promedio = PrintSalarysAverages(list, len);
        printEmployeesAboveAverages(list, len, average;

        break;
    case 4:
        exit = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N ", 's', 'n');
        break;
    }
    } while (exit != 's');

}


/** \brief Calcula total de sueldos y el promedio de los mismos
 *
 * \param list[] es Employee, es vector de empleados
 * \param len es int, tamaño del vector a recorrer
 * \return averageSalarys es float, se utilizara para la funcion printEmployeesAboveAverages;
 *
 */
float PrintSalarysAverages (Employee list[], int len) {

    float totalSalarys = 0;
    int contEmployees = 0;
    float averageSalarys;

    for (int i=0; i<len; i++) {
        if (list[i].isEmpty == 0) {
            totalSalarys += list[i].salary;
            contEmployees ++;
        }
    }
    averageSalarys = totalSalarys/contEmployees;


    printf("\nEl total de los sueldos de la list es: %.2f\n", totalSalarys);
    printf("El promedio de los sueldos es: %.2f\n",averageSalarys);

    return averageSalarys;

 }

 /** \brief Muestra los empleados de la lista que superen un valor
  *
  * \param list[] es Employee, es vector de empleados
  * \param len es int, tamaño del vector a recorrer
  * \param average es int, es el sueldo que debe ser superado para que se muestre el empleado
  *
  */
 void printEmployeesAboveAverages (Employee list[i]], int len, int average)
  {

    printf("\nLos siguientes empleados superan el sueldo promedio: \n");
    printf("  ID\t    name\t\t  Apellido\t\tSueldo\t\tSector\n");
    printf("------------------------------------------------------------------------------\n");

    sortEmployeesbyId(list, len);

    for (int i=0; i<len; i++) {
        if (list[i].salary > promedio && list[i].isEmpty == 0) {
           printEmployee(list[i]);
        }
    }
    printf("\n\n");
    system("pause");
 }

