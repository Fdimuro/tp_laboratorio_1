#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee ;

#endif // ARRAYEMPLOYEES_H_INCLUDED

//ABM empleado
int FirstMenu();
//int harcodEmployees (Employee list[i]], int len, int cant);
void initEmployees( Employee list[], int );
int addEmployee ( Employee list[], int , int ;
void printEmployees(  Employee list[], int );
void printEmployee(Employee list);
int searchFree ( Employee list[], int ;
int menumodificationEmployee();
int modificationEmployee (Employee list[], int );
int chooseEmployee (Employee list[], int , int , char* );
int removeEmployee( Employee list[], int) ;
void sortEmployeesbyId( Employee list[], int );

