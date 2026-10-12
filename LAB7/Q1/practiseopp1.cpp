
#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    void input(int r, int i)
    {
        real = r;
        imag = i;
    }

      void add(Complex c1,Complex c2)
    {
        real = c1.real + c2.real;
        imag = c1.imag + c2.imag;
    }
   
    

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1, c2, c3; 
    c1.input(5,3);    
    c2.input(2,4);
    c3.add(c1, c2);    
    c3.display();

    return 0;
}