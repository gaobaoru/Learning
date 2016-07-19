#ifndef _DATA_
#define _DATA_

// forward declaration
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Data;

//class declaration
class Data
{
public:
    Data (int y = 0, int m = 0, int d = 0):ye(y),mon(m),da(d) {}
    void print();
    int year()  const {return ye;}
    int month() const {return mon;}
    int day()   const {return da;}
private:
    int ye,mon,da;

    friend bool operator > (const Data& data1, const Data& data2);
    friend bool operator < (const Data& data1, const Data& data2);
    friend bool operator == (const Data& data1, const Data& data2);
};

//class definition
inline void
Data::print()
{
    cout<<ye<<'-'<<mon<<'-'<<da<<endl;
}

inline int
year(const Data& data)
{
    return data.year();
}

inline int
month(const Data& data)
{
    return data.month();
}

inline int
day(const Data& data)
{
    return data.day();
}

inline bool
operator > (const Data& data1, const Data& data2)
{
    return ( year(data1)>year(data2) || ( year(data1)==year(data2) && (month(data1)>month(data2)))
    || ( year(data1)==year(data2) && (month(data1)==month(data2)) && (day(data1)>day(data2))));
}

inline bool
operator < (const Data& data1, const Data& data2)
{
    return ( year(data1)<year(data2) || ( year(data1)==year(data2) && (month(data1)<month(data2)) )
    || ( year(data1)==year(data2) && (month(data1)==month(data2)) && (day(data1)<day(data2)) ) );
}

inline bool
operator == (const Data& data1, const Data& data2)
{
    return year(data1)==year(data2) && (month(data1)==month(data2)) && (day(data1)==day(data2));
}

inline int
random(const int start,const int end)
{
    return start+(rand()%(end-start+1));
}

inline Data*
CreatePoints()
{
    int i;
    Data *data = new Data[10];
    //special month of days
    int NumOfDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int randYear,randMonth;
    cout<<"-------------------Before Sort------------------"<<endl;
    srand((int)time(0));
//    srand((unsigned)time(NULL));
    for(i=0;i<10;i++){
        randYear = random(1900,2050);//year scope [1900,2050]
        randMonth = random(1,12);
        //isLeapYear
        if(randYear%400 ==0 || (randYear%100 != 0 && randYear%4 ==0)){
            NumOfDays[1] = 29;
        }else{
            NumOfDays[1] = 28;
        }
        data[i]=Data(randYear, randMonth,random(1,NumOfDays[randMonth-1]));
        data[i].print();
    }
    return data;
}

inline void
Sort(Data* data)
{
    int i,j;
    Data tmp(0,0,0);
    for(i=0;i<10;i++){// from small to big,time cost is O(n^2)
        for(j=i+1;j<10;j++){
            if(data[i]>data[j]){
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    cout<<"-------------------After Sort------------------"<<endl;
    for(i=0;i<10;i++)
    {
        data[i].print();
    }
    delete[] data;
}
//consider the smart pointer int the later,optimize the memory.
#endif // _DATA_
