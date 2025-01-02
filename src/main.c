#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>



/*********************************************************************************************************
*   Definire  le type de la socket dans ce cas 8080                                                      *
*    pour ne pas avoir des problemes adminstratif sinon on pourra utiliser 80 pour un serveur web http   *
**********************************************************************************************************/
#define PORT 80


int main() {
    //Déclarations des Variables 
    int server_fd = -1;
    struct sockaddr_in6 address; 
    memset(&address, 0, sizeof(address));    // Initialiser la structure à 0

    //Initialisation des variables:
    address.sin6_family = AF_INET6;                 // Utilise IPv6
    address.sin6_addr = in6addr_any;               // Accepte les connexions sur toutes les adresses locales
    address.sin6_port = htons(PORT);   // Convertir le port en ordre réseau



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
    printf("Socket créé avec succès !\n");
    
    /******************************************************************************************
    * https://www.linuxhowtos.org/manpages/2/bind.htm
    * bind() lie le socket à l'adresse et au port spécifiés.  
    ****************************************************************************************** */

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        // Pour port 80 utililser sudo pour lancer le programme !!!!
        perror("Erreur lors du bind");
        close(server_fd);  // Libérer les ressources
        exit(EXIT_FAILURE);
    }
    printf("Socket lié à l'adresse et au port %d avec succès !\n", PORT);
    
    /******************************************************************************************
    * https://www.linuxhowtos.org/manpages/2/listen.htm
    * listen() permet au serveur d'accepter les connexions entrantes.  
    ****************************************************************************************** */
    if (listen(server_fd, 6) < 0) {
        perror("Erreur lors du listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Serveur en attente de connexions sur le port %d...\n", PORT);

    
    
    
    return 0;
}
