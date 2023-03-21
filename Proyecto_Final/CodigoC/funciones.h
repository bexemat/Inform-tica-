/*
 * Prototipos de funciones usadas en el proyecto final
 */

/* 
 * File:   funciones.h
 * Author: matias 
 * Created on 17 de agosto de 2020, 20:59
 */

/*
 Estructura de Control de Estacion de Medicion 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *Fecha;
    char *Hora;  
    char *Tendencia;
    float Temperatura;
    
}Control_Temp;

Control_Temp *CT;

float raiz(float v);
void ordenar_estructura(int cont);
float Mediana(int cont);
float fvarianza(int cont,float med);
int cant_lectura(int cont,char aux[],FILE *archivo);
void intro_val_de_arch_a_estr(FILE *archivo,char aux[],int cont);
void str_nulo(char a[]);
void liberar_mem(int cont);
float media(int cont);
void mostrar_estructura(int cont);
float minimo(int cont,float min);
int minimo_indice(int cont,float min,int min_ind);
float maximo(int cont,float max);
int maximo_indice(int cont,float max,int max_ind);