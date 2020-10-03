#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "validaciones.h"


/** \brief Muestra menu de optiones
 *
 * \return int opcion elegida por el usuario
 *
 */

int FirstMenu()
{
    int option;
    do
    {
        system("cls");
        printf("Menu de opciones:\n");
        printf("1. Alta de empleado\n");
        printf("2. Modificacion de empleado\n");
        printf("3. Baja de empleado\n");
        printf("4. Informar\n");
        printf("5. salir\n\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&option);
    }
    while(option > 5);

    return option;
}


/** \brief Pone el flag isEmpty en true
 *
 * \param list[i]] Employee vector de empleados
 * \param len int temaño del vector de empleados
 * \return void
 *
 */
void initEmployees(Employee list[], int len)
{

    for (int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;

    }

}


int addEmployee (Employee list[], int len, int id)
{
    int isOk = 0;
    int index;
    char Aux[51];
    float auxSal;
    int auxSec;
    Employee auxEmployee;

    index = searchFree(list,len);

    system("cls");
    printf("- - - - - ALTA DE EMPLEADO - - - - -\n");
    if (index == -1)
    {

        printf("list llena, el maximo permitido es 1000 empleados") ;

    }
    else
    {

        //INGRESA name
        validaString("Ingrese nombre: ", "nombre muy largo, ingrese nombre: ", 51, Aux);
        strcpy(auxEmployee.name,Aux);

        //INGRESA APELLIDO
        validaString("Ingrese apellido: ", "Apelido muy largo, ingrese apellido: ",51, Aux);
        strcpy(auxEmployee.lastName,Aux);

        //INGRESA SUELDO
        validaFloat("Ingrese sueldo: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese sueldo ", 0, &auxSal);
       auxEmployee.salary = auxSal;

        //INGRESA SECTOR
        validaInt("Ingrese numero de sector: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese numero de sector: ", 0,&auxSec);
       auxEmployee.sector = auxSec;

        //ASIGNA ID AUTOMATICAMENTE
       auxEmployee.id = id;

        //CAMBIA BANDERA
       auxEmployee.isEmpty = 0;



        list[index] =auxEmployee;

        printf("\nNombre: %s \nApellido: %s \nSueldo :%.2f \nSector: %d \nId: %d",
               list[index].name, list[index].lastName, list[index].salary, list[index].sector, list[index].id);
        printf("\n\n");
        system("pause");

    }

    return isOk;
}

/** \brief recorre array y busca index libre
 *
 * \param list es vector de estructura Employee, es el array que se va a recorrer
 * \param len es int, es el tamaño del vector a recorrer
 * \return prier index libre (isEmpty = TRUE)
 *
 */
int searchFree (Employee list[], int len)
{
    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** \brief recorre vector completo y llama a funcion printEmployee en los indexs que tengan el flag isEmpty = true
 *
 * \param list es vector de estructura Employee, es el array que se va a recorrer
 * \param len es int, es el tamanaño del vector a recorrer
 *
 */
void printEmployees(Employee list[], int len)
{
    int flag = 0;

    system("cls");
    printf("******LISTA  DE  EMPLEADOS ******\n\n");

    printf("  ID\t    name\t\t  Apellido\t\tSueldo\t\tSector\n");
    printf("------------------------------------------------------------------------------\n");
    for(int i=0; i < len; i++)
    {
        if (list[i].isEmpty == 0)
        {
           printEmployee(list[i]);
            flag = 1;
        }

    }

    if (flag == 0)
    {
        //system("cls");
        printf("No hay empleados para mostar");


    }

    system("pause");

    printf("\n\n");
}

/** \brief muestra un solo index de vector de Employees
 *
 * \param index a mostrar
 */
void printEmployee(Employee list)
{
    printf("%3d\t%10s\t\t%10s\t\t%.2f\t%5d\n",list.id,list.name,list.lastName,list.salary,list.sector);

}




/*int harcodEmployees (Employee list[i]], int len, int cant)
{

    int cargados = 0;

    Employee listPrueba[10] =
    {
        {1,"Juan", "Diaz", 25000, 2, 0},
        {2,"Maria", "Perez", 12300, 4, 0},
        {3,"Laura", "Gomez", 33400, 3, 0},
        {4,"Manuel", "Fuentes", 65500, 1, 0},
        {5,"Pablo", "Garcia", 23400, 4, 0},
        {6,"Ema", "Rodriguez", 15600, 5, 0},
        {7,"Susana", "Valinotti", 44900, 1, 0},
        {8,"Gerardo", "Gutierrez", 55645, 3, 0},
        {9,"Javier", "Pelizza", 88900, 1, 0},
        {10,"Roxana", "Giraca", 33450, 2, 0}
    };

    if (cant<=len)
    {

        for (int i=0; i<cant; i++)
        {

            list[i] = listPrueba[i];
            cargados ++;
        }

    }
    else
    {
        printf("no hay suficientes empleados de prueba para cargar");

    }
    return cargados;
}
*/

/** \brief modifica una de las variables de un Employee, pide Id del empleado a modificar
 *
 * \param list es Employee, el vector de empleados
 * \param len es int, el tamaño del vector a recorrer
 * \return devuelve 1 si pudo realizar el cambio
 *
 */
int modificationEmployee (Employee list[], int len)
{
    int isOk = 0;
    int id;
    int index;
    char exit;
    char Aux[51];
    float auxSal;
    int auxSec;

    system("cls");
    printf("- - - - - MODIFICACION DE EMPLEADO - - - - -\n");
    validaInt("Ingrese ID del empleado a modificar o 0 para ver list completa: ",
              "Error, debe ingresar un numero positivo\nIngrese ID del empleado a modificar o 0 para ver list completa: ",0, &id);


    index = chooseEmployee(list, len, id, "modificar");

    if (index>=0)
    {
        do
        {
            switch (menumodificationEmployee())
            {
            case 1:
                //Modificar name
                if (validaString("Ingrese nuevo nombre: ", "nombre muy largo, ingrese nombre: ", 51, Aux))
                {
                    strcpy(list[index].name,Aux);
                    isOk = 1;
                }
                break;

            case 2:
                //modificar apellido
                if (validaString("Ingrese nuevo apellido: ", "Apelido muy largo, ingrese apellido: ",51, Aux))
                {
                    strcpy(list[index].lastName,Aux);
                    isOk = 1;
                }
                break;

            case 3:
                //modificar sueldo
                if (validaFloat("Ingrese sueldo: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese sueldo ", 0, &auxSal))
                {
                    list[index].salary = auxSal;
                    isOk = 1;
                }
                break;

            case 4:
                //modificar sector
                if (validaInt("Ingrese numero de sector: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese numero de sector: ", 0,&auxSec))
                {
                    list[index].sector = auxSec;
                    isOk = 1;
                }
                break;

            case 5:
                exit = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N: ", 's', 'n');

            }

        }
        while (exit !='s');
    }



    return isOk;
}

/** \brief Busca un ID en el vector
 *
 * \param list[] es Employee, es vector de empleados
 * \param len es int, tamaño del vector a recorrer
 * \param id a buscar en el vector
 * \return devuelve index int, el index del vector del ID recibido.
 *
 */
int searchEmployee (Employee list[], int len, int id)
{
    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (id == list[i].id && !list[i].isEmpty)
        {
            index = i;
            break;
        }


    }

    return index;
}

/** \brief valida el id del empleado ingresado por el usuario, o muestra vector completo
 *
 * \param list[] es Employee, es vector de empleados
 * \param len es int, tamaño del vector a recorrer
 * \param id es int, es el id que se buscara en list[]
 * \param  accion es puntero a char, es la accion que se realizara sobre el empleado
 * \return devuelve el index de list[] donde esta el empleado seleccionado
 *
 */
int chooseEmployee (Employee list[], int len, int id, char* accion)
{
    int index = -1;
    char option;

    if (id == 0)
    {
        sortEmployeesbyId(list, len);
        printEmployees(list, len);
        validaInt("Ingrese ID: ", "ERROR, el ID debe ser un numero positivo.\nIngrese ID: ", 0, &id);
    }

    index = searchEmployee(list, len, id);
    if (index == -1)
    {
        printf("NO HAY EMPLEADO REGISTRADO EN EL ID INFORMADO O FUE DADO DE BAJA\n\n");
        system("pause");
    }
    else
    {
        printf("\n");
        printf("ID\t    nombre\t\t  Apellido\t\tSueldo\t\tSector\n");
       printEmployee(list[index]);
        printf("\n");
        printf("Se va a %s a %s %s\n\n",accion, list[index].name, list[index].lastName);

        //system("pause");
        option = validaChar2("Es correcto (S/N)", "ERROR, debe ingresr S/N", 's', 'n');
    }

    if (option == 'n')
    {
        printf("\nSe cancela la accion\n");
        index = -1;
        system("pause");
    }
    return index;
}

/** \brief Menu para elegir que parametro del Employee modificar
 *
 * \return int opcion, la opcion elegida por el usuario
 *
 */
int menumodificationEmployee()
{

    int option;
    do
    {
        system("cls");
        printf("- - - - - MODIFICACION DE EMPLEADO - - - - -\n");
        printf("Menu de optiones:\n");
        printf("1. Modificar name\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar sueldo\n");
        printf("4. Modificar sector\n");
        printf("5. exit\n\n");
        printf("Elija option: ");
        fflush(stdin);
        scanf("%d",&option);
    }
    while (option > 5);

    return option;

}

/** \brief Pone el flag isEmpty en true de un elemento del vector seleccionado por ID
 *
 * \param list[] es Employee, es vector de empleados
 * \param len es int, tamaño del vector a recorrer
 * \return devuelve 1 si pudo hacer la baja
 *
 */
int removeEmployee(Employee list[], int len)
{
    int isOk = 0;
    int id;
    int index;

    system("cls");
    printf("- - - - - BAJA DE EMPLEADO - - - - -\n");
    validaInt("Ingrese ID del empleado a borrar o 0 para ver list completa: ",
              "Error, debe ingresar un numero positivo\nIngrese ID del empleado a borrar o 0 para ver list completa: ",0, &id);

    index = chooseEmployee(list, len, id, "dar de baja");

    if (index >= 0)
    {
        list[index].isEmpty = 1;
        printf("Se dio de baja el empleado\n");
        system("pause");
        isOk = 1;
    }

    return isOk;
}



/** \brief Ordena el vector de empleados segun su ID
 *
 * \param list[] es Employee, es vector de empleados
 * \param len es int, tamaño del vector a recorrer
 *
 */
void sortEmployeesbyId(Employee list[], int len)
{

    Employee aux;

    for (int i=0; i<len-1; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (list[i].id >list[j].id)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }
}











