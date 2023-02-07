//Aluno: Elivelton Botelho Pinheiro
//Visual Studio Code
//Windows 11 Home 22H2
#define TRUE 1
#define FALSE 0

typedef struct _dllist_ DLList;
typedef struct _dlnode_ DLNode;

DLList * dllCreate( void );
int dllDestroy(DLList *l );
int dllInsertFirst(DLList *l, void *data);
int dllInsertAsLast(DLList *l, void *data);
void * dllGetFirst(DLList *l);
void * dllRemoveFirst (DLList *l);
void * dllGetNext(DLList *l);
void * dllQuery(DLList *l, void *key, int (*cmp)(void *, void *));
void * dllRemove(DLList *l, void *key, int (*cmp)(void *, void *));