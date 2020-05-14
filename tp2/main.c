#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployes.h"

#define ELEMENTS 1000 //Nómina
#define ELEMENTSSEC 5



int main()
{
    int id = 0;
    char name[51];
    char lastName[51];
    float salary = 0;
    int sector = 0;
    int r; //esta variable sirve para el retorno
    char follow = 's';
    int order = 0;
    int option;
    int indice;

    Employee arrayEmployees[ELEMENTS];
    Sectors arraySectors[ELEMENTSSEC] = {
                                        {1, "Perfumery"},
                                        {2, "Human rights"},
                                        {3, "Economy"},
                                        {4, "Systems"},
                                        {5, "Transport"}
                                        };
    r = initEmployees(arrayEmployees, ELEMENTS);

    do
    {
        switch(menu())
        {
        case 1:
            r = addEmployee(arrayEmployees, ELEMENTS, id, name, lastName, salary, sector, arraySectors, ELEMENTSSEC);
            system("pause");
            break;
        case 2:
            indice = noHayEmpleados(arrayEmployees, ELEMENTS);
            if(indice != -1)
            {
                r = findEmployeeById(arrayEmployees, ELEMENTS, id);
            }
            else
            {
                printf("\nNo se puede acceder a la opcion porque no hay empleados registrados.\n\n");
            }
            system("pause");
            break;
        case 3:
            indice = noHayEmpleados(arrayEmployees, ELEMENTS);
            if(indice != -1)
            {
            r = removeEmployee(arrayEmployees, ELEMENTS, id);
            }
            else
            {
                printf("\nNo se puede acceder a la opcion porque no hay empleados registrados.\n\n");
            }
            system("pause");
            break;
        case 4:
            indice = noHayEmpleados(arrayEmployees, ELEMENTS);
            if(indice != -1)
            {
                system("cls");
                printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
                printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n\n");
                printf("\n\nIngrese opcion: ");
                scanf("%d", &option);
                if(option == 1)
                {
                    r = sortEmployees(arrayEmployees, ELEMENTS, order);
                }
                else if(option == 2)
                {
                    r = salarios(arrayEmployees, ELEMENTS);
                }
                else
                {
                    printf("Opcion incorrecta\n\n");
                }
            }
            else
            {
                printf("\nNo se puede acceder a la opcion porque no hay empleados registrados.\n\n");
            }
            system("pause");
            break;
        case 5:
            printf("\nDesea seguir? (s/n): ");
            fflush(stdin);
            scanf("%c", &follow);
            system("pause");
            break;
        default:
            printf("\nOpcion incorrecta\n\n");
            system("pause");
            break;
        }
    }while(follow == 's');

    return r;
}

