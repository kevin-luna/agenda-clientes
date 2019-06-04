#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nombre[50];
  char direccion[100];
  unsigned int telefono;
  char sexo;
  float estado_pagos;
}cliente;

int main(int argc, char const *argv[]) {
  char cont; //BANDERA DE CONTINUACIÓN DEL PROGRAMA
  int opcion1,opcion2;//BANDERA DE OPCIONES
  int Nclientes=0;
  cliente agenda_guardar[Nclientes];
  cliente agenda_leer[Nclientes];
  FILE *agenda;
  char nombre_archivo[255];
  int tArchivo;
  int nRegistros;
  //printf("%d",sizeof(cliente));
  printf("Que desear hacer?\n");
  printf("1) Crear una nueva agenda\n");
  printf("2) Trabajar con una agenda existente\n");
  printf("OPCION>");
  scanf("%d", &opcion1);
    system("cls");
switch (opcion1) {
  //CREAR AGENDA NUEVA
  case 1:
    printf("INGRESE UN NOMBRE PARA EL ARCHIVO:");
    scanf("%s",nombre_archivo);
    strcat(nombre_archivo,".bin");
    agenda=fopen(nombre_archivo,"wb");
    strcpy(nombre_archivo,"");
    break;
  //TRABAJAR CON AGENDA
  case 2:
  printf("Con que archivo desea trabajar?\n");
  system("ls *.bin");
  printf("\nNOMBRE DEL ARCHIVO>");
  scanf("%s",nombre_archivo);
  agenda=fopen(nombre_archivo,"rb");
  if(agenda==NULL){
    printf("EL ARCHIVO NO EXISTE");
    exit(1);
  }else{
    fclose(agenda);
//MENÚ DE OPCIONES
system("cls");
  printf("-----INGRESE UNA OPCION-----\n");
  printf("1) Agregar clientes\n");
  printf("2) Ver datos de los clientes\n");
  printf("3) Buscar un cliente\n");
  printf("4) Modificar un registro\n");
  printf("5) Borrar un cliente\n");
  printf("6) Listar clientes con deudas\n");

  scanf("%d",&opcion2);

  switch (opcion2){
      //RELLENO DE REGISTROS
    case 1:
        printf("Cuantos clientes desea agregar?:");
        scanf("%d",&Nclientes);
        freopen(nombre_archivo,"a+b",agenda);
        for(int i=0;i<Nclientes;i++){
            system("cls");
            fflush(stdin);
            printf("NOMBRE>");
            gets(agenda_guardar[i].nombre);
            printf("DIRECCION>");
            gets(agenda_guardar[i].direccion);
            printf("TELEFONO>");
            scanf("%d",&agenda_guardar[i].telefono);
            fflush(stdin);
            printf("SEXO (M/F)>");
            scanf("%c",&agenda_guardar[i].sexo);
            printf("ESTADO DE DE PAGO>");
            scanf("%f",&agenda_guardar[i].estado_pagos);
            fwrite(&agenda_guardar[i],sizeof(agenda_guardar[i]),1,agenda);
            fclose(agenda);
        }
      break;
    //VISUALIZACIÓN DE REGISTROS
    case 2:
        agenda=fopen(nombre_archivo,"r+b");
        fseek(agenda,0L,SEEK_END);
        tArchivo=ftell(agenda);
        nRegistros=tArchivo/sizeof(cliente);    //calcula el numero de registros que contiene el archivo
        //printf("EL TAMANO DEL ARCHIVO ES: %d",tArchivo);
        for(int i=0;i<nRegistros;i++){
            rewind(agenda);
            fread(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
            printf("Nombre: %s\n",agenda_leer[i].nombre);
            printf("Direccion: %s\n",agenda_leer[i].direccion);
            printf("Telefono: %u\n",agenda_leer[i].telefono);
            printf("Sexo: %c\n",agenda_leer[i].sexo);
            printf("Deuda: %2.f\n",agenda_leer[i].estado_pagos);
            puts("-------------------------------------------");
        }
        fclose(agenda);

      break;

    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
        break;
  }
  }
  break;

}


  return 0;
}
