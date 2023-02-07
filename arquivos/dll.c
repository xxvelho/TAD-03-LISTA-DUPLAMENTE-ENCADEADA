//Aluno: Elivelton Botelho Pinheiro
//Visual Studio Code
//Windows 11 Home 22H2
#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct _dlnode_{
    struct _dlnode_ *next,
                    *prev;
    void * data;
};

struct _dllist_{
    DLNode *first;
    DLNode *cur; 
};

DLList * dllCreate( ) {
    DLList *l;
    l = (DLList* ) malloc(sizeof(DLList));
    if ( l != NULL ) {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}
int dllDestroy ( DLList *l ){
    if ( l != NULL ) {
        if ( l->first == NULL ) {
            free (l);
            return TRUE;
        }
    }
    return FALSE;
}
int dllInsertFirst(DLList *l, void *data){
    DLNode * newnode;
    if ( l != NULL) {
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if ( newnode != NULL) {
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = l->first;
            if(l->first != NULL){
                l->first->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}
int dllInsertAsLast ( DLList *l, void *data){
    DLNode *newnode, *last;
    if ( l != NULL ) {
        newnode = ( DLNode *) malloc(sizeof(DLNode));
        if ( newnode != NULL) {
            newnode->data = data;
            newnode->next = NULL;
            if( l->first == NULL) {
                l->first = newnode;
            } else {
                last = l->first;
                while (last->next != NULL) {
                    last = last->next;
                }
                newnode->prev = last;
                if(last != NULL){
                    last->next = newnode;
                }
            }
            return TRUE;
        }
    }
    return FALSE;
}
void * dllGetFirst( DLList *l){
    DLNode *aux;
    void *data;
    if ( l != NULL ) {
        if(l->first != NULL){
            l->cur = l->first;
            aux = l->cur;
            data = aux->data;
            return data;
        }
    }
    return NULL;
}
void * dllGetNext( DLList *l){
    void *data;
    if ( l != NULL ) {
        if ( l->cur->next != NULL ) {
            l->cur = l->cur->next;
            data = l->cur->data;
            return data;
        }
    }
    return NULL;
}
void * dllQuery( DLList *l, void *key, int (*cmp)(void *, void *)){
    DLNode *spec;
    if ( l != NULL ) {
        if ( l->first != NULL ) {
            spec = l->first;
            int stat = cmp(spec->data, key);
            while ( stat != TRUE && spec->next != NULL){
                spec= spec->next;
                stat = cmp(spec->data, key);
            }
            if ( stat == TRUE ) {
                return spec->data;
            }
        }
    }
    return NULL;
}
void * dllRemoveFirst (DLList *l ){
    DLNode *first; void *data;
    if ( l != NULL) {
        if ( l->first != NULL ) {
            first = l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}
void * dllRemove( DLList *l, void *key, int (*cmp)(void *, void *)){
    DLNode *spec, *prevnode, *nextnode;
    if ( l != NULL ) {
        if ( l->first != NULL ) {
            spec = l->first; 
            prevnode = NULL;
            int stat = cmp(spec->data, key);
            while ( stat != TRUE && spec->next != NULL) {
                spec= spec->next;
                stat = cmp(spec->data, key);
            }
            if ( stat == TRUE ) { // achar
                void * data;
                nextnode = spec->next;
                prevnode = spec->prev;
                data = spec->data;
                if(prevnode != NULL){
                    prevnode->next = nextnode;
                }else{
                    l->first = nextnode;
                }
                if(nextnode != NULL){
                    nextnode->prev = prevnode;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}