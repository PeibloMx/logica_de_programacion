#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void main(){
    printf("\n.--------------------------.");
    printf("\n| Esperando inicializacion |");
    printf("\n'--------------------------'\n");
    //declaracion de fds quienes llevan el mensaje cadena
    int fd,fd2;
    //variables
    int i;
    
    char salir;
    //creacion fichero que envia y recibe mensajes
    mkfifo("MIFIFO",0666);
    mkfifo("MIFIFO2",0666);
    
    do
    {
        char cadena[100];
        char cadena2[100];
        
            //proceso de mensaje enviado
    fd = open("MIFIFO",O_WRONLY);
    printf("\nUser1 (escriba...): ");
    gets(cadena);
    if(strcmp(cadena,"salir")==0){
            printf("\n\nRealmente deseas salir [s/n]:  ");
            scanf("%c",&salir);
            if(salir=='s' || salir=='S'){
                write(fd,"desconectado",13);
                puts("\n\n\n--desconectado--");
                exit(-1);
            }else if(salir=='n' || salir=='N'){
                fflush(stdin);
            }else{
                puts("\n\n\n\t-INVALIDO-");
                fflush(stdin);
            }
        } 
        puts("...esperando...");
        write(fd,cadena,sizeof(cadena));
        close(fd);
    
    
            //proceso de mensaje recibido
    fd2 = open("MIFIFO2",O_RDONLY);
    read(fd2,cadena2,sizeof(cadena2));
    if (strcmp(cadena2,"desconectado")==0)
    {
        puts("\n\n\nUsuario 2 --desconectado--");
        exit(-1);
    }
    printf("\n(*User2*) dice: %s ",cadena2);
    close(fd2);

    for(i=0; i<100;i++){
        cadena[i]='\0';
        cadena2[i]='\0';
    }
    } while (1);
    
    
    

}
