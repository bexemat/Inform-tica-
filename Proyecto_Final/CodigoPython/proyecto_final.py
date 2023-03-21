# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

import time  #libreria para usar time.sleep
import _thread #para usar hilos
import random #libreria para numero aleatorios
import datetime #libreria para fechas

def prom(k,suma,x,temp,archivo):    
    promedio=(suma/k)
    if k<=5:
        tendencia="Sin_tendencia!"
        archivo.write("%s "%tendencia)
        print(f"Tendencia:Amarillo,Verde,Rojo")
        
    if k>5:
        if ((1-x)*promedio)>temp:
            tendencia="Tendencia_baja"
            archivo.write("%s "%tendencia)
            print(f"Tendencia:Verde")
        elif ((1-x)*promedio)<=temp<=((1+x)*promedio):
            tendencia="Tendencia_Est!"
            archivo.write("%s "%tendencia)
            print(f"Tendencia:Amarillo")
        else:
            tendencia="Tendencia_alta"
            archivo.write("%s "%tendencia)
            print(f"Tendencia:Rojo")   
    return promedio  
        
def imprimir_mens(x):
    archivo=open("/home/matias/Escritorio/Archivos_de_prueba/Proyecto_final.txt","w")
    k=1   
    suma=0
    promedio=0
    t_predef=35    
    x
    while True:
        for i in range(0,t_predef):
            time.sleep(0.1)
        print(f'Lectura:{k}')
        temp=random.uniform(20,30)
        print(f"La temperatura es :{temp}")
        suma+=temp;
        promedio=prom(k,suma,x,temp,archivo)
        print(f"El promedio en {k} lecturas es {promedio}")
        fecha=datetime.datetime.now()
        form_fecha=fecha.strftime('%d/%m/%Y %H:%M:%S:%f')    
        archivo.write("%s "%form_fecha)
        archivo.write("%s\n"%"{0:,.3f}".format(temp))
        k+=1
    archivo.close()
def main():  
    x=float(input("Ingrese variacion porcentual: "))
    x=x/100
    _thread.start_new_thread(imprimir_mens,(x,))        
    m=input('Si pulsas enter finalizara el sensado de Temperatura\n')    
    print('Fin de programa')
    #archivo.close()
main()