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

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
         list[i].isEmpty = 0;
    }
    return 0;
}

/** \brief Crea un menu de opciones, pregunta sobre una opcion a elegir e interactua con la opcion digitada
 * \param int option;
 * \return return option;
 */
int menu()
{
    int option;

    printf("*** MENU DE OPCIONES ***\n");
    printf("___________________\n\n");
    printf("1. ALTAS.\n");
    printf("2. MODIFICAR.\n");
    printf("3. BAJA.\n");
    printf("4. INFORMAR.\n");
    printf("5. SALIR.\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &option);

    return option;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{
    int i;
    int cont = 0;
    system("cls");

    printf("*** EMPLEADOS ***\n");
    printf("________________________________________________\n\n");
    printf("ID    NOMBRE    APELLIDO    SALARIO    ID SECTOR\n");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printf("%d %10s %10s    %.2f     %d\n", list[i].id, list[i].name, list[i].lastName,
                                                       list[i].salary, list[i].sector);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("\nNO HAY EMPLEADOS QUE MOSTRAR\n\n");
    }

    return 0;
}

/** \brief Muestra todos los sectores.
 * \param int i;
 * \return No retorna nada.
 */
int showSectors(Sectors* listsec, int lensec)
{
    int i;

    system("cls");

    printf("*** SECTORES ***\n");
    printf("________________\n");
    printf("ID        SECTOR\n");

    for(i=0; i<lensec; i++)
    {
        printf("%d        %10s\n", listsec[i].id, listsec[i].description);
    }

    return 0;
}


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *  free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector, Sectors* listsec, int lensec)
{
    int indice;
    int i;

    system("cls");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            indice = i;
            list[indice].id = i;
            break;
        }
    }

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(name);
    strcpy(list[indice].name, name);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(lastName);
    strcpy(list[indice].lastName, lastName);

    printf("Ingrese salario: ");
    fflush(stdin);
    scanf("%f", &salary);
    list[indice].salary = salary;

    showSectors(listsec, lensec);

    printf("Ingrese ID del sector: ");
    fflush(stdin);
    scanf("%d", &sector);
    list[indice].sector = sector;

    list[indice].isEmpty = 1;

    return 0;
}



/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id)
{
    int i;
    int index = -1;
    int respuesta;
    system("cls");

    printEmployees(list, len);

    printf("\n\nIngrese ID del empleado: ");
    scanf("%d", &id);

    for(i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 1)
        {
            index = 0;
            printf("\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector");
            printf("\n\nQue desea modificar?");

            scanf("%d", &respuesta);
            if(respuesta == 1)
            {
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(list[i].name);
            }
            else if(respuesta == 2)
            {
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(list[i].lastName);
            }
            else if(respuesta == 3)
            {
                printf("Ingrese nuevo salario: ");
                fflush(stdin);
                scanf("%f", &list[i].salary);
            }
            else if(respuesta == 4)
            {
                printf("Ingrese ID del nuevo sector: ");
                fflush(stdin);
                scanf("%d", &list[i].sector);
            }
            else
            {
                printf("Error, opcion incorrecta\n\n");
            }
            break;
        }
    }

    if(index == -1)
    {
        printf("\nError, no se ha encontrado al empleado con esa ID\n\n");
    }


    return index;
}



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int i;
    int r = -1;
    char respuesta;

    printEmployees(list, len);
    printf("\n\nIngrese ID del empleado: ");
    scanf("%d", &id);

    for(i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 1)
        {
            r = 0;
            printf("%d %10s %10s    %.2f     %d\n", list[i].id, list[i].name, list[i].lastName,
                                                       list[i].salary, list[i].sector);
            printf("Seguro que desea eliminar a este usuario(s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
            {
                list[i].isEmpty = 0;
                printf("\nEmpleado eliminado con exito!!\n\n");
            }
            else
            {
                printf("\nNo se ha eliminado al usuario\n\n");
            }

        }
    }
    return r;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int i, j;
    int auxInt;
    char auxChar[20];
    float auxFloat;
    system("cls");
    printf("1. Para ordenar de forma ascendente\n0. Para ordenar de forma descendente\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &order);

    if(order == 1)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) != -1 && list[i].sector > list[j].sector)
                    {
                    auxInt = list[j].id;
                    list[j].id = list[i].id;
                    list[i].id = auxInt;

                    strcpy(auxChar,list[j].name);
                    strcpy(list[j].name, list[i].name);
                    strcpy(list[i].name, auxChar);

                    strcpy(auxChar,list[j].lastName);
                    strcpy(list[j].lastName, list[i].lastName);
                    strcpy(list[i].lastName, auxChar);

                    auxFloat = list[j].salary;
                    list[j].salary = list[i].salary;
                    list[i].salary = auxFloat;

                    auxInt = list[j].sector;
                    list[j].sector = list[i].sector;
                    list[i].sector = auxInt;
                    }
                }

            }
        }
    }
    else if(order == 0)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) != 1 && list[i].sector < list[j].sector)
                    {
                    auxInt = list[j].id;
                    list[j].id = list[i].id;
                    list[i].id = auxInt;

                    strcpy(auxChar,list[j].name);
                    strcpy(list[j].name, list[i].name);
                    strcpy(list[i].name, auxChar);

                    strcpy(auxChar,list[j].lastName);
                    strcpy(list[j].lastName, list[i].lastName);
                    strcpy(list[i].lastName, auxChar);

                    auxFloat = list[j].salary;
                    list[j].salary = list[i].salary;
                    list[i].salary = auxFloat;

                    auxInt = list[j].sector;
                    list[j].sector = list[i].sector;
                    list[i].sector = auxInt;
                    }
                }

            }
        }
    }
    else
    {
        printf("Error, opcion incorrecta\n\n");
    }

    return 0;
}

/** \brief Calcula el total del salario de los empleados, el promedio de todos los empleados, y
 *           cuantos empleados superan el promedio.
 * \param list Employee*
 * \param len int
 * \param i, cont, contEmpleados int;
 * \param promedio, total float;
 * \return int return 0;
 *
 */
int salarios(Employee* list, int len)
{
    int i;
    int cont = 0;
    int contEmpleados = 0;
    float promedio;
    float total = 0;

    system("cls");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
          total = total + list[i].salary;
          cont++;
        }
    }
    promedio = total / cont;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].salary > promedio)
        {
            contEmpleados++;
        }
    }
    printf("El total de los salarios es: %.2f\n\n", total);
    printf("El promedio de los salarios es: %.2f\n\n", promedio);
    printf("%d empleado/s supera/n el promedio.\n\n", contEmpleados);

    return 0;
}


/** \brief Busca si hay empleados.. si no los hay entonces no se pueden ejecutar las opciones 2, 3, 4.
 * \param list Employee*
 * \param len int
 * \param i, indice, int;
 * \return int retorna -1 si no hay empleados, y si los hay retorna algo distinto de -1;
 *
 */
int noHayEmpleados(Employee* list, int len)
{
    int i;
    int indice = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

