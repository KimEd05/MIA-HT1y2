#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct Alumno
{
    int tipo;
    char apellido1[21];
    char apellido2[21];
    char nombre[21];
    char codigo[11];
    int nota;
};

typedef struct Profesor
{
    int tipo;
    char apellido1[21];
    char apellido2[21];
    char nombre[21];
    char codigo[11];
    int seccion;
};

int main( )
{
    FILE *file;
    file = fopen("alumnos_201700507.disk","wb+");
    if( file == NULL )
    {
        return 0;

    }
    fclose(file);

    int menu = 0;

    while (menu >= 0 && menu < 4)
    {
        switch (menu)
        {
            case 0:
                {
                    cout << "********** Menú ********** " << endl;
                    cout << "1. Crear Usuario" << endl;
                    cout << "2. Editar Usuario" << endl;
                    cout << "3. Reporte" << endl;
                    cout << endl;
                    scanf("%i", &menu);
                }

                break;

            case 1:
                {
                    system("clear");
                    Alumno alum;
                    cout << "********* Crear Usuario ********** " << endl;
                    cout << "Tipo de usuario: 0. Alumno, 1. Profesor" << endl;
                    scanf("%i", &alum.tipo);
                    if( alum.tipo == 0)
                    {

                        cout << "Apellido 1:" << endl;
                        scanf("%s", &alum.apellido1);
                        cout << "Apellido 2:" << endl;
                        scanf("%s", &alum.apellido2);
                        cout << "Nombre:" << endl;
                        scanf("%s", &alum.nombre);
                        cout << "Codigo:" << endl;
                        scanf("%s", &alum.codigo);
                        cout << "Nota:" << endl;
                        scanf("%i", &alum.nota);
                    } else if( alum.tipo == 1)
                    {

                        cout << "Apellido 1:" << endl;
                        scanf("%s", &alum.apellido1);
                        cout << "Apellido 2:" << endl;
                        scanf("%s", &alum.apellido2);
                        cout << "Nombre:" << endl;
                        scanf("%s", &alum.nombre);
                        cout << "Codigo:" << endl;
                        scanf("%s", &alum.codigo);
                        cout << "Sección:" << endl;
                        scanf("%i", &alum.nota);
                    }


                    FILE *file;
                    file = fopen("alumnos_201700507.disk", "ab");
                    if( file == NULL )
                    {
                        cout << "No accedí al archivo" << endl;
                    } else
                    {
                        fwrite(&alum, sizeof(alum), 1, file);
                        fclose(file);
                        cout << "Se ha creado el usuario correctamente." << endl;
                    }
                    menu = 0;
                }

                break;

            case 2:
                {
                    system("clear");
                    char codigo[11];
                    cout << "********* Editar Usuario ********** " << endl;
                    cout << "Código de usuario:" << endl;
                    scanf("%s", &codigo);

                    FILE* file;
                    file = fopen("alumnos_201700507.disk","r+b");
                    if( file == NULL )
                    {
                        cout << "No accedí al archivo" << endl;
                    }
                    else
                    {

                        Alumno nuevo;
                        Alumno leer;
                        fread (&leer, sizeof(leer), 1, file);
                        while ( ! feof(file) )
                        {
                            if( strcasecmp(leer.codigo, codigo) == 0 )
                            {
                                cout << "Nombre (nuevo):" << endl;
                                scanf("%s", &nuevo.nombre);
                                cout << "Apellido 1 (nuevo):" << endl;
                                scanf("%s", &nuevo.apellido1);
                                cout << "Apellido 2 (nuevo):" << endl;
                                scanf("%s", &nuevo.apellido2);
                                cout << "Codigo (nuevo):" << endl;
                                scanf("%s", &nuevo.codigo);
                                if( leer.tipo == 0)
                                {
                                    cout << "Nota (nueva):" << endl;
                                    scanf("%i", &nuevo.nota);
                                }
                                else
                                {
                                    cout << "Sección (nueva):" << endl;
                                    scanf("%i", &nuevo.nota);
                                }

                                nuevo.tipo = leer.tipo;

                                int posicion = ftell(file) - sizeof(leer);
                                fseek(file, posicion, SEEK_SET);
                                fwrite(&nuevo, sizeof(nuevo), 1, file);
                                break;
                                cout << "El usuario se ha modificado correctamente" << endl;
                            }

                            fread (&leer, sizeof(leer), 1, file);
                        }
                        fclose (file);
                    }
                    menu = 0;
                }

                break;

            case 3:
                {
                    system("clear");
                    FILE *file;
                    Alumno leer;
                    file = fopen("alumnos_201700507.disk","rb");
                    if( file == NULL )
                    {
                        cout << "No accedí al archivo" << endl;
                    }
                    else
                    {
                        system("clear");
                        fread (&leer, sizeof(leer), 1, file);
                        cout << "********** Reporte ********** " << endl;

                        while ( ! feof(file) )
                        {

                            if(leer.tipo == 0)
                            {
                                cout << "********** Alumno *********** " << endl;
                            }
                            else
                            {
                                cout << "********** Profesor *********** " << endl;
                            }

                            cout << "Apellido 1: " << leer.apellido1 << endl;
                            cout << "Apellido 2: " << leer.apellido2 << endl;
                            cout << "Nombre: " << leer.nombre << endl;
                            cout << "Código: " << leer.codigo << endl;
                            if( leer.tipo == 0 )
                            {
                                cout << "Nota: " << leer.nota << endl;
                            }
                            else
                            {
                                cout << "Sección: " << leer.nota << endl;
                            }
                            cout << "*********************** " << endl;
                            fread (&leer, sizeof(Alumno), 1, file);
                        }
                        fclose (file);
                    }
                    menu = 0;
                }

                break;
        }

    }

    return 0;
}
