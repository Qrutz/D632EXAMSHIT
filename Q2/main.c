#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "person.h"

#define PORT 8080
#define BUFFER_SIZE sizeof(Person)

// Server functions
void *serverFunction(void *arg);
void handleClient(int client_socket);

// Client functions
void *clientFunction(void *arg);
void receivePersonList(int sock);

int main(int argc, char *argv[])
{
    pthread_t server_thread, client_thread;

    // Create and start the server thread
    pthread_create(&server_thread, NULL, serverFunction, NULL);

    // Wait a bit to ensure the server starts before the client tries to connect
    sleep(1);

    // Create and start the client thread
    pthread_create(&client_thread, NULL, clientFunction, NULL);

    // Wait for both threads to finish
    pthread_join(server_thread, NULL);
    pthread_join(client_thread, NULL);

    return 0;
}

void *serverFunction(void *arg)
{
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddgccr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    handleClient(client_socket);

    close(server_fd);
    return NULL;
}

void handleClient(int client_socket)
{
    Node *head = NULL;
    Person persons[5] = {
        {"John", "Doe", "9001011234", "City1"},
        {"Jane", "Smith", "8502022345", "City2"},
        {"Alice", "Brown", "9203033456", "City3"},
        {"Bob", "White", "9904044567", "City4"},
        {"Charlie", "Black", "8005055678", "City5"}};

    for (int i = 0; i < 5; ++i)
    {
        appendNode(&head, persons[i]);
    }

    printf("Created linked list on server:\n");
    printList(head);

    int num_persons = 5;
    send(client_socket, &num_persons, sizeof(num_persons), 0);

    Node *temp = head;
    while (temp != NULL)
    {
        char buffer[BUFFER_SIZE];
        serializePerson(temp->person, buffer);
        send(client_socket, buffer, BUFFER_SIZE, 0);
        temp = temp->next;
    }

    freeList(head);
    close(client_socket);
}

void *clientFunction(void *arg)
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return NULL;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return NULL;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return NULL;
    }

    receivePersonList(sock);

    close(sock);
    return NULL;
}

void receivePersonList(int sock)
{
    int num_persons;
    recv(sock, &num_persons, sizeof(num_persons), 0);

    Node *head = NULL;
    for (int i = 0; i < num_persons; ++i)
    {
        char buffer[BUFFER_SIZE];
        recv(sock, buffer, BUFFER_SIZE, 0);
        Person p;
        deserializePerson(buffer, &p);
        appendNode(&head, p);
    }

    printf("Received linked list on client:\n");
    printList(head);
    freeList(head);
}
