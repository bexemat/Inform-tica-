/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: matias
 * Created on 17 de agosto de 2020, 09:27
 */


#include "funciones.h"


int main(int argc, char** argv) {
    FILE *archivo;
    int cont;
    char dir[]="/home/matias/Escritorio/Archivos_de_prueba/Proyecto_final.txt";
    char aux[50];
    float med,mediana;
    float min;
    float max,varianza,desv_estandar;
    int min_ind=0;
    int max_ind=0;
    min=99999;
    max=0;
    med=0;
    cont=0;
    str_nulo(aux);
    archivo=fopen(dir,"r");
    if(archivo==NULL){
        printf("Error al abrir el archivo\n");        
    }
    cont=cant_lectura(cont,aux,archivo);    
    cont-=1;
    CT=(Control_Temp*)malloc(cont*sizeof(Control_Temp));
    if(CT==NULL){
        printf("Error en asignacion de memoria\n");
    }
    
    printf("La cantidad de variables leidas es de:%d\n",cont);
    rewind(archivo);
    intro_val_de_arch_a_estr(archivo,aux,cont);  
    printf("Tendencia\tFecha\t\t\tHora\t\tTemperatura\n");
    mostrar_estructura(cont);
    med=media(cont);
    min_ind=minimo_indice(cont,min,min_ind);
    min=minimo(cont,min);
    max_ind=maximo_indice(cont,max,max_ind);
    max=maximo(cont,max);  
    printf("El valor minimo es %.3f y se registro el dia %s a las %s\n",min,CT[min_ind].Fecha,CT[min_ind].Hora);
    printf("El valor maximo es %.3f y se registro el dia %s a las %s\n",max,CT[max_ind].Fecha,CT[max_ind].Hora);
    printf("Analisis Estadistico de los Datos leidos \n");
    printf("La media de las Temperaturas es :%.3f\n",med);
    ordenar_estructura(cont);    
    mediana=Mediana(cont);
    printf("La mediana de las Temperaturas es :%.3f\n",mediana);
    varianza=fvarianza(cont,med);
    desv_estandar=raiz(varianza);
    printf("La Varianza de las Temperaturas es :%.3f\n",varianza);
    printf("La Desviacion Estandar de las Temperaturas es:%.3f\n",desv_estandar);
    fclose(archivo);
    liberar_mem(cont);
    return (EXIT_SUCCESS);
}
