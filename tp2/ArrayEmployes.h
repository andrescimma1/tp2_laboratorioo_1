#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define ELEMENTS 1000 //Nómina
#define ELEMENTSSEC 5


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

typedef struct
{
    int id;
    char description[20];
}Sectors;

int initEmployees(Employee* list, int len);
int menu();
int showSectors(Sectors* listsec, int lensec);
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector, Sectors* listsec, int lensec);
int findEmployeeById(Employee* list, int len, int id);
int printEmployees(Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int salarios(Employee* list, int len);
int noHayEmpleados(Employee* list, int len);

