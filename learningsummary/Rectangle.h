#ifndef _RECTANGLE_
#define _RECTANGLE_

// forward declaration
#include<math.h>
#include<iostream>
using namespace std;

//class declaration
class Shape
{
    int no;
};
class Point
{
public:
    int x;
    int y;
};
class Rectangle: public Shape
{
    int width;
    int height;
    Point* leftup;
public:
    Rectangle(int width,int height,int x,int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();
    int Girth() const {return (width+height)*2;}
    int Area() const {return width*height;}
    int get_width() const {return width;}
    int get_height() const {return height;}
    Point* get_leftup() const {return leftup;}
};
//class definiition
/*
*ctor
*/
inline
Rectangle::Rectangle(int width=0,int height=0,int x=0,int y=0)
{
    leftup = new Point;
    leftup->x = x;
    leftup->y = y;
    this->width = width;
    this->height = height;
}
/*
*dtor
*/
inline
Rectangle::~Rectangle()
{
    delete leftup;
}
/*
*copy ctor
*/
inline
Rectangle::Rectangle(const Rectangle& other)
{
    leftup = new Point;
    leftup->x = other.leftup->x;
    leftup->y = other.leftup->y;
    this->width = other.width;
    this->height = other.height;
}
/*
*copy operator
*/
inline
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    //check self assignment
    if(this->leftup==other.leftup && this->width==other.width
        && this->height==other.height){
            return *this;
        }
    if(this->leftup == other.leftup)
    {
        this->width = other.width;
        this->height = other.height;
        return *this;
    }else{
        delete leftup;//caution: memory leak
        leftup = new Point;
        leftup->x = other.leftup->x;
        leftup->y = other.leftup->y;
        this->width = other.width;
        this->height = other.height;
        return *this;
    }
}
//output
ostream& operator<<(ostream& os,const Rectangle& other)
{
    os<<": width("<<other.get_width()<<"),"
    <<"height("<<other.get_height()<<"),"
    <<"leftup.x("<<other.get_leftup()->x<<"),"
    <<"leftup.y("<<other.get_leftup()->y<<"),"<<endl
    <<"       Girth="<<other.Girth()<<","
    <<" Area="<<other.Area()<<"."<<endl;
    return os;
}

#endif // _RECTANGLE_
