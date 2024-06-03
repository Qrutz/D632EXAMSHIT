#ifndef PERSON_H
#define PERSON_H

#define MAX 10

typedef struct
{
    char sName[MAX];    // Person’s given name
    char sSurname[MAX]; // Person’s surname
    char sPnr[MAX];     // Person’s social security number (in the format YYMMDDXXXX)
    char sAddress[MAX]; // Person’s city of residence
} Person;

typedef struct Node
{
    Person person;
    struct Node *next;
} Node;

// Function prototypes
Node *createNode(Person p);
void appendNode(Node **head, Person p);
void printList(Node *head);
void freeList(Node *head);
void serializePerson(Person p, char *buffer);
void deserializePerson(char *buffer, Person *p);
int calculateAge(const char *sPnr);

#endif // PERSON_H
