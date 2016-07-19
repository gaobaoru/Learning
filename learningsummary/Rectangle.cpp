#include "Rectangle.h"

int main()
{
    Rectangle rec0;
    cout<<"rec0()"<<rec0<<endl;
    Rectangle rec1(3,4,0,0);
    Rectangle rec2(5,6,4,4);
    cout<<"rec1()"<<rec1<<endl;
    cout<<"rec2()"<<rec2<<endl;

    cout<<"----------Copy creator rec3(rec2)---------"<<endl;
    Rectangle rec3(rec2);
    cout<<"rec3()"<<rec3<<endl;

    cout<<"----------Copy operator rec3=rec1---------"<<endl;
    rec3=rec1;
    cout<<"rec3()"<<rec3<<endl;

    cout<<"----------Copy operator rec3=rec3---------"<<endl;
    rec3=rec3;
    cout<<"rec3()"<<rec3<<endl;
}
