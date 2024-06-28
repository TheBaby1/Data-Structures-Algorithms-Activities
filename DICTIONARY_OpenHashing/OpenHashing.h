#ifndef OPEN_HASHING
#define OPEN_HASHING

#define INITIAL_SIZE 10
#define STRING_SIZE 20	
#define LOAD_FACTOR 0.65

typedef char String[STRING_SIZE];

typedef struct node {
	String champion;
	struct node *next;
} Node, *nodePtr;

typedef nodePtr *Dictionary;

void initializeDictionary(Dictionary *D, int size);
void visualizeDictionary(Dictionary D, int size);

int hash(String champion, int size);
void insertData(Dictionary *D, String champion, int *size, int *count);
void reHash(Dictionary *D, int *size, int *count);
void deleteMember(Dictionary D, String champion, int size);
char *isMember(Dictionary D, String champion, int size);


#endif 
