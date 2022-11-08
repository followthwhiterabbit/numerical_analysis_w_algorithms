/*
we will keep halving the interval until we achieve a certain accuracy 


*/

#include <iostream>
#include <cmath>
#define eps 0.0001

inline float f(float x)
{
    return x*x*x - 9*x + 1; 
}

void bisection_method()
{
    float a, b, c; 
    int count; 
    std::cout << "please enter initial root interval a, b\n"; 
    std::cin >> a >> b; 

    if (f(a) * f(b) <  0) // we have a root in this interval 
    {
        count = 0; 
        do
        {
            c = (a + b) / 2; 
            if (f(a) * f(c) < 0)
                b = c; 
            else
                a = c; 

        count += 1; 
        }while((count <=20) && fabs(f(c)) > eps); 

    std::cout << "root " << c << std::endl; 
    std::cout << "f(root) = " << f(c) << std::endl; 
    std::cout << "iterations= " << count << std::endl; 
    }
    else
    {
        std::cout << "initial interval incorrect\n"; 
    }
    
}



int main()
{
bisection_method(); 



}