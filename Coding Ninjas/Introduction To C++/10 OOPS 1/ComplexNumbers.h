
#include <iostream>

using namespace std;

class ComplexNumbers 
{
    int real;
    int imaginary;
    
  public:
    
    ComplexNumbers(int real, int imaginary)
    {
        this -> real = real;
        this -> imaginary = imaginary;
    }

    void print()
    {
        cout << real << " + i" << imaginary;
    }
    
    void plus(ComplexNumbers const &c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    
    void multiply(ComplexNumbers const &c2)
    {
        int c = real;
        real = (c * c2.real - imaginary * c2.imaginary);
        imaginary = (c * c2.imaginary + imaginary * c2.real);
    }
};