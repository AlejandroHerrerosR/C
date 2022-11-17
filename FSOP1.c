#include<stdlib.h>
#include<stdio.h>
#include <dirent.h> //para poder ejecutar los comandos
#include<string.h> //Para usar el strtok
#include<stdbool.h>
#include <ctype.h>
void extraercadena(int puntero,char cadena[], char subcadena[]);
bool salir(char cadena[]);
bool verificador(char cadena[]);
int main ()
{
  //Inicializamos los parámetros, que serán punteros
  bool comandovalido,salida;
  int contador, temp;
  contador=0;
  temp=0;
  char *parametros=malloc(256*sizeof(char)); //Cargamos memoria para almacenar el input del usuario
  char *comando=malloc(5*sizeof(char)); //el array donde meter el comando
  char *ruta=malloc(20*sizeof(char)) ; //El array donde meter la ruta
  char *resto=malloc(75*sizeof(char)); //El resto de lo que escriba el usuario
  //Reservamos la memoria de manera dinámica con Malloc
  printf("APPI SHELL>>");
  fflush(stdin); //limpiamos el buffer para evitar que haya algo en el teclado que nos estropee lo que ha metido el usuario
  fgets(parametros, 256*sizeof(char), stdin); //Con esto lo que hacemos es recoger por teclado el string del usuario pero con los espacios
  fflush(stdin); //limpiamos el buffer para evitar que si necesitamos el scanner en otro momento tenga datos residuales.
 // puts(parametros); //imprimimos el comando 
  parametros=realloc(parametros, strlen(parametros));
 // printf("%lu\n",sizeof(parametros));
  extraercadena(contador, parametros, comando);
  comando= realloc(comando, strlen(comando));
 // printf("%lu\n", strlen(comando));
 // puts(comando);
  salida=salir(comando);
  if(salida==true)
  {
    return 0;
  }
  comandovalido=verificador(comando);
  if(comandovalido!=true)
  {
    printf("No ha introducido un comando válido\n");
    return 0;
  }
  contador=strlen(comando);
  contador+=1; //Ya que así accedemos a la siguiente posicción del espacio
  extraercadena(contador, parametros, ruta);
  ruta= realloc(ruta, strlen(ruta));
 // printf("%lu\n", strlen(ruta));
 // puts(ruta);
  temp= strlen(ruta);
  temp+=1;
  contador= temp+contador;
  extraercadena(contador,parametros,resto);
  printf("%s, va a ser ignorado puesto que no admitimos más de un parámetro\n", resto);

  return 0;

}
void  extraercadena(int puntero, char cadena[], char subcadena[])
{
    int i=puntero;
    int j=0;
    while(cadena[i] != ' ' && cadena[i]!='\n')
    {
        if(cadena[i]!= '0')
        {
            subcadena[j]=cadena[i];
            i++;
            j++;
        }
    }
    subcadena[j]='\0';
}
bool salir(char cadena[])
{
    bool r=false;
    char salir[5]="salir";
    if(strcmp(cadena,salir)==0)
    {
        r=true;
    }
    return r;
    
}
bool verificador(char cadena[])
{   
    bool result=false;
     char ls[2]="ls";
     char cat[3]="cat";
     if(strcmp(cadena, ls)==0||strcmp(cadena,cat)==0) 
     {
        result=true;
     }
    return result;
    
}
