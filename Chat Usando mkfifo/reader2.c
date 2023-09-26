#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void main(){
    int fd,fd2;
    int i;
    
    char salir;

    

    do
    {
        char cadena[100];
        char cadena2[100];
        //proceso de mensaje recibido
    fd = open("MIFIFO",O_RDONLY);
    read(fd,cadena,sizeof(cadena));
    if (strcmp(cadena,"desconectado")==0)
    {
        puts("\n\n\nUsuario 1 --desconectado--");
        exit(-1);
    }
    printf("\n(*User1*) dice: %s ",cadena);
    close(fd);
    
        //proceso de mensaje enviado
    fd2 = open("MIFIFO2",O_WRONLY);
    printf("\nUser2 (escriba...): ");
    gets(cadena2);
    if(strcmp(cadena2,"salir")==0){
            printf("\n\nRealmente deseas salir [s/n]:  ");
            scanf("%c",&salir);
            if(salir=='s' || salir=='S'){
                write(fd2,"desconectado",13);
                puts("\n\n\n--desconectado--");
                exit(-1);
            }else if(salir=='n' || salir=='N'){
                fflush(stdin);
            }else{
                fflush(stdin);
                puts("\n\n\n\t-INVALIDO-");
            }
        }
    puts("...esperando...");
    write(fd2,cadena2,sizeof(cadena2));
    close(fd2);
    
    for(i=0; i<100;i++){
            cadena[i]='\0';
            cadena2[i]='\0';
        }
    } while (1);
    


    

}