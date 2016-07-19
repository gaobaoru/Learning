#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _list{
    Node *head;
}List;


void add(List *pList,int number);
void print(List *pList);
void searchnumber(List *pList,int number);
void deletenumber(List *pList,int number);
void clearlist(List *pList);
#endif // _NODE_H
