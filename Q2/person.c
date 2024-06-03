#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "person.h"

Node *createNode(Person p)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Failed to create node");
        exit(EXIT_FAILURE);
    }
    newNode->person = p;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node **head, Person p)
{
    Node *newNode = createNode(p);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->person.sName);
        printf("Surname: %s\n", temp->person.sSurname);
        printf("Pnr: %s\n", temp->person.sPnr);
        printf("Address: %s\n", temp->person.sAddress);
        printf("Age: %d\n\n", calculateAge(temp->person.sPnr));
        temp = temp->next;
    }
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void serializePerson(Person p, char *buffer)
{
    memcpy(buffer, &p, sizeof(Person));
}

void deserializePerson(char *buffer, Person *p)
{
    memcpy(p, buffer, sizeof(Person));
}

int calculateAge(const char *sPnr)
{
    int year, month, day;
    sscanf(sPnr, "%2d%2d%2d", &year, &month, &day);

    // Assuming the century is 1900-1999. Adjust accordingly if necessary.
    if (year <= 99 && year >= 0)
    {
        year += 1900;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int current_year = tm.tm_year + 1900;
    int current_month = tm.tm_mon + 1;
    int current_day = tm.tm_mday;

    int age = current_year - year;
    if (current_month < month || (current_month == month && current_day < day))
    {
        age--;
    }

    return age;
}
