#include "node.h"

int main(int argc,char const *argv[])
{
    List list;
    list.head = NULL;
    int number;
    do
    {
        scanf("%d",&number);
        if(number != -1)
        {
            add(&list,number);
        }

    }while(number != -1);
    print(&list);
    scanf("%d",&number);
    searchnumber(&list,number);
    deletenumber(&list,number);
    print(&list);
    clearlist(&list);
    return 0;
}

