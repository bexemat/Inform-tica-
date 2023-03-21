/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Funciones usadas en el proyecto final
 */


#include "funciones.h"
int cant_lectura(int cont,char aux[],FILE *archivo){
    str_nulo(aux);
    while(!feof(archivo)){
    fgets(aux,50,archivo);
    cont++;
    }
    return cont;
}
float fvarianza(int cont,float med){
    int i;
    float sum=0;
    for(i=0;i<cont;i++){
        sum+=((CT[i].Temperatura-med)*(CT[i].Temperatura-med));
    }
    return (sum/cont);
}
void ordenar_estructura(int cont){
    int i,j;
    float aux;
    for(i=0;i<cont-1;i++){
        for(j=i+1;j<cont;j++){
            if(CT[i].Temperatura>CT[j].Temperatura){
              aux=CT[i].Temperatura;
              CT[i].Temperatura=CT[j].Temperatura;
              CT[j].Temperatura=aux;
            }
        }
        
    }
}
float Mediana(int cont){
    int pos;
    pos=cont/2;    
    float mediana;
    mediana=0;
    if (cont%2==0){
        mediana=(CT[pos-1].Temperatura+CT[pos].Temperatura)/2;
    }else{
        mediana=CT[pos].Temperatura;
    }
    return mediana;
}
float raiz(float v) {
	float res;
	float i=0;
	do {
		i= i+0.00001;
		res= i*i;
	}while (v>=res);
        
        return(i);
}
void intro_val_de_arch_a_estr(FILE *archivo,char aux[],int cont){
    int i,n;
    for(i=0;i<cont;i++){ 
            str_nulo(aux);
            fscanf(archivo," %[^ ]",aux);
            n=strlen(aux)+1;
            CT[i].Tendencia=(char*)malloc(n*sizeof(char));
            strcpy(CT[i].Tendencia,aux);
            str_nulo(aux);
            fscanf(archivo," %[^ ]",aux);
            n=strlen(aux)+1;
            CT[i].Fecha=(char*)malloc(n*sizeof(char));
            strcpy(CT[i].Fecha,aux);
            str_nulo(aux);
            fscanf(archivo," %[^ ]",aux);
            n=strlen(aux)+1;
            CT[i].Hora=(char*)malloc(n*sizeof(char));
            strcpy(CT[i].Hora,aux);
            str_nulo(aux);
            if(i<cont-1){
            fscanf(archivo," %[^\n]",aux);
            CT[i].Temperatura=atof(aux);
            str_nulo(aux);
    }else{
            fscanf(archivo," %s",aux);
            CT[i].Temperatura=atof(aux);
            str_nulo(aux);    
    }
    }
    
}

float media(int cont){
    int i;
    float sum=0;
    float prom=0;
    for(i=0;i<cont;i++){
        sum+=CT[i].Temperatura;
    }
    prom=sum/cont;
    return prom;
}
void mostrar_estructura(int cont){
    int i;
     for(i=0;i<cont;i++){
    printf("%s\t%s\t%s\t\t%.3f\n",CT[i].Tendencia,CT[i].Fecha,CT[i].Hora,CT[i].Temperatura);
    }
}
void str_nulo(char a[]){
    int i;
    for(i=0;i<50;i++){
        a[i]='\0';
    }
}
void liberar_mem(int cont){
   int i;
   for(i=0;i<cont;i++){
        free(CT[i].Fecha);
        free(CT[i].Hora);
    }
    free(CT); 
}
float minimo(int cont,float min){
    int i;
    for(i=0;i<cont;i++){
        if(CT[i].Temperatura<min){
            min=CT[i].Temperatura;
        }
    }
    return min;
}
float maximo(int cont, float max){
    int i;
    for(i=0;i<cont;i++){
        if(CT[i].Temperatura>max){
            max=CT[i].Temperatura;
        }
    }
    return max;
}
int minimo_indice(int cont,float min,int min_ind){
    int i;
    for(i=0;i<cont;i++){
        if(CT[i].Temperatura<min){
            min=CT[i].Temperatura;
            min_ind=i;
        }        
    }
    
    return min_ind;
}
int maximo_indice(int cont,float max,int max_ind){
    int i;
    for(i=0;i<cont;i++){
        if(CT[i].Temperatura>max){
            max=CT[i].Temperatura;
            max_ind=i;
        }        
    }
    return max_ind;
}

