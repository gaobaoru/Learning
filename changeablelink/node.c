#include "node.h"
// input number
void add(List *pList,int number)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;

    Node *last = pList->head;
    if(last)
    {
        while(last->next)
        {
            last = last->next;
        }
        last->next = p;
    }
    else
    {
        pList->head = p;
    }
}
// print link
void print(List *pList)
{
    Node *p;
    for(p=pList->head;p;p = p->next)
    {
        printf("%d\t",p->value);
    }
    printf("\n");
}
// search the special number
void searchnumber(List *pList,int number)
{
    Node *p;
    int isFound = 0;
    for(p=pList->head;p;p=p->next)
    {
        if(p->value == number)
        {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if(!isFound)
    {
        printf("没找到\n");
    }
}
// after searching and delete the number
void deletenumber(List *pList,int number)
{
    Node *p,*q;
    for(q = NULL,p=pList->head;p;q=p,p=p->next)
    {
        if(p->value == number)
        {
            if( q )
                q->next = p->next;
            else
                pList->head = p->next;
            free(p);
            break;
        }
    }
}
// clear the link before the quit
void clearlist(List *pList)
{
    Node *p,*q;
    for(p=pList->head;p;p=q)
    {
        q = p->next;
        free(p);
    }
}
