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
    time()
    {
        hours=3;
        minutes=45;
        seconds=30;
    }
   time(int h,int m,int s)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }
    time(time &t2)
    {
        hours=t2.hours;
        minutes=t2.minutes;
        seconds=t2.seconds;
    }
    
        
    
    void display()
    {   cout<<"Hours: "<<hours<<endl;
        cout<<"Minutes: "<<minutes<<endl;
        cout<<"Seconds: "<<seconds<<endl;
    }};
        
    main()
    { time t1;
       time t2(2,45,30);
        time t3(t2);
    
        t3.display();
        return 0;
    }