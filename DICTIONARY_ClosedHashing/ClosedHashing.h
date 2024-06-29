#ifndef CLOSED_HASHING
#define CLOSED_HASHING

#include <stdbool.h>

#define STRING_SIZE 20
#define INITIAL_SIZE 10
#define LOAD_FACTOR 0.75
#define EMPTY '\0'

typedef char String[STRING_SIZE];

typedef String *Dictionary;

void initializeDictionary(Dictionary D, int size);
void insertData(Dictionary *D, String champion, int *size, int *count);
void deleteData(Dictionary *D, String champion, int *size, int *count);

int hash(String champion, int size);
void reHash(Dictionary *D, int *size, int *count);
bool isMember(Dictionary D, String champion, int size);

void displayDictionary(Dictionary D, int size);

#endif
