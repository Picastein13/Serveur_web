#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
//#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>



/*********************************************************************************************************
*   Definire  le type de la socket dans ce cas 8080                                                      *
*    pour ne pas avoir des problemes adminstratif sinon on pourra utiliser 80 pour un serveur web http   *
**********************************************************************************************************/
#define PORT 8080


int main() {
    int server_fd = -1;

    /******************************************************************************************
    * https://www.linuxhowtos.org/manpages/2/socket.htm
    * Si tu passes 0, le système choisit automatiquement le protocole par défaut correspondant au type :
    * Pour SOCK_STREAM : Le protocole TCP sera sélectionné.
    * Pour SOCK_DGRAM : Le protocole UDP sera sélectionné.   
    ****************************************************************************************** */
    
    if ((server_fd = socket(AF_INET6, SOCK_STREAM, 0)) == -1) {
        perror("Erreur lors de la création du socket");
        exit(EXIT_FAILURE);
    }
    
    
    printf("Webserver initialisé !\n");
    return 0;
}
