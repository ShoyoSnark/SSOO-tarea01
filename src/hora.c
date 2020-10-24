//Roberto Vivar Chain - 19.975.349-5
#include <global.hh>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
//librerias para el ejecutamiento correcto del algoritmo.
void signal_handler(int signal)//funcion para obtener el tiempo local del sistema
{
    static uint32_t chances = 0;//variable contador de signals que no corresponden a SIGUSR1
    time_t rawtime; 
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

   if (signal == SIGUSR1) {//identifica si la señal es efectivamente "SIGUSR1"
       printf("Señal SIGUSR1 recibida: %s", asctime(timeinfo));//Se recibe la señal y se muestra la fecha y hora actual del sistema
       printf("Listo para recibir la señal SIGUSR1.\n");

   }else if(signal == SIGINT){ chances++;//si la signal es SIGNIT(ctrl+c) el contador aumenta en 1
	}
   if (chances == 2){//si el contador es igual a 2, se finaliza la ejecucion del programa
	exit(signal);
}
}
int main(int argc, char *argv[]){//funcion main del codigo
    signal(SIGINT, signal_handler);
    //ciclo que se ejecuta hasta que se interrumpa el proceso
	    printf("Programa hora ejecutandose. PID=%d.\n", getpid());//se muestra en pantalla que el programa esta en ejecucion y muestra la pid
        printf("Listo para recibir la señal SIGUSR1.\n");//se muestra en pantalla que el programa esta listo para recibir la señal SIGUSR1
        signal(SIGUSR1, signal_handler);//señal captada
        pause();//se pausa la ejecucuon hasta recibir una señal
	    sleep(1);//se realiza un delay 
    	while(1){} 
    return(EXIT_SUCCESS);//ejecucion correcta
}
