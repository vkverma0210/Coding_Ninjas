/*Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. 
Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.*/

/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations

#include <climits>
#include <iostream>

using namespace std;

class Polynomial
{
public:
    int *degCoeff;
    int capacity;

    //default constructor
    Polynomial()
    {
        capacity = 4;
        degCoeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    //Copy Constructor
    Polynomial(Polynomial const &p)
    {
        degCoeff = new int[p.capacity];
        capacity = p.capacity;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    // = Operator Overloading
    void operator=(Polynomial const &p)
    {
        int *newPol = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newPol[i] = degCoeff[i];
        }

        delete[] degCoeff;
        degCoeff = newPol;
        capacity = p.capacity;
    }

    //Set Coefficient
    void setCoefficient(int const &a, int const &b)
    {
        if (a >= capacity)
        {
            int *temp = new int[a + 1];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = degCoeff[i];
            }

            for (int i = capacity; i < a + 1; i++)
            {
                temp[i] = 0;
            }

            delete[] degCoeff;
            degCoeff = temp;
            capacity = a + 1;
        }

        degCoeff[a] = b;
    }

    // Addition Operator Overloading
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial p3;
        if (p.capacity >= capacity)
        {
            for (int i = 0; i < capacity; i++)
            {
                int coeff = this->degCoeff[i] + p.degCoeff[i];
                p3.setCoefficient(i, coeff);
            }

            for (int j = capacity; j < p.capacity; j++)
            {
                p3.setCoefficient(j, p.degCoeff[j]);
            }

            return p3;
        }
        else
        {
            for (int i = 0; i < p.capacity; i++)
            {
                int coeff = this->degCoeff[i] + p.degCoeff[i];
                p3.setCoefficient(i, coeff);
            }

            for (int j = p.capacity; j < capacity; j++)
            {
                p3.setCoefficient(j, degCoeff[j]);
            }

            return p3;
        }
    }

    // Subtraction Operator Overloading
    Polynomial operator-(Polynomial const &p)
    {
        Polynomial p3;
        if (p.capacity >= capacity)
        {
            for (int i = 0; i < capacity; i++)
            {
                int coeff = this->degCoeff[i] - p.degCoeff[i];
                p3.setCoefficient(i, coeff);
            }

            for (int j = capacity; j < p.capacity; j++)
            {
                p3.setCoefficient(j, -p.degCoeff[j]);
            }

            return p3;
        }
        else
        {
            for (int i = 0; i < p.capacity; i++)
            {
                int coeff = this->degCoeff[i] - p.degCoeff[i];
                p3.setCoefficient(i, coeff);
            }

            for (int j = p.capacity; j < capacity; j++)
            {
                p3.setCoefficient(j, degCoeff[j]);
            }

            return p3;
        }
    }

    // Multiplication Operator Overloading
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial p3;
        int *temp = new int[(capacity) + (p.capacity)];

        for (int i = 0; i < capacity + p.capacity; i++)
        {
            temp[i] = 0;
        }

        delete[] p3.degCoeff;
        p3.degCoeff = temp;
        p3.capacity = capacity + p.capacity;

        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                p3.degCoeff[i + j] += degCoeff[i] * p.degCoeff[j];
            }
        }

        return p3;
    }

    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] == 0)
                continue;
            cout << degCoeff[i] << "x" << i << " ";
        }

        cout << endl;
    }
};

//Driver program to test above functions
int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}