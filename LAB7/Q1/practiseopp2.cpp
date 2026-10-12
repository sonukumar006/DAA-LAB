#include<iostream>
using namespace std;

class time

{
    int hours, minutes, seconds;
    public:
   /* void input()
 {
        cout<<"Enter hours, minutes and seconds: ";
        cin>>hours>>minutes>>seconds;
    }*/
   void input(int h,int m,int s)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }
    void add(time t1,time t2)
    {
        seconds=t1.seconds+t2.seconds;
        minutes=t1.minutes+t2.minutes+seconds/60;
        hours=t1.hours+t2.hours+minutes/60;
        seconds=seconds%60;
        minutes=minutes%60;
    }
    void display()
    {
        cout<<hours<<" hours "<<minutes<<" minutes "<<seconds<<" seconds"<<endl;
    }}t1,t2,t3;

    main()
    {
        t1.input(2,45,30);
        t2.input(1,20,50);
        t3.add(t1,t2);
        t3.display();
        return 0;
    }