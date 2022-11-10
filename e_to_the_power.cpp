/*
    e to the power of x calculation 

Write a program calculating sn(x) :=∑xk/k!,where n is the smallest natural number
satisfying the inequality xn+1/(n+1)!<10−6, as an approximate value of x. 

Ifx < 0,use the formula e to the power of -1 = 1/e to the power of x

calculate for x = 0, 1, -1, 0.5, -0.123, -25.5, -1776, 3.14159


*/

#include <iostream>
#include <cmath>
#define eps 0.000001


double e_to_the_power_of_x_approximation(double x, int k)
{   

    double approx = 1 + fabs(x); 
    double num = 1,  denum = 1; 
    
    /* 
    if (x == 0)
        return 1; 
    else if( x == 1)
        return 1 + x; 
    */ 

    
    for(int i = 2; i <= k; i++)
    {
        num = 1; 

        for(int j = 0; j < i; j++)
            {
                num *= fabs(x); 
                num /= (j + 1); 
            }
        
        approx += num;         

    }

    if (x > 0)
        return approx; 
    else  
        return (1 / approx); 
}


int main()
{
    double val; 
    double result; 
    int iter = 2;  
    int count = 0; 

    std::cout << "enter the value for the closest approximation: "; 
    std::cin >> val; 

    do
    {

    result = e_to_the_power_of_x_approximation(val, iter); 
    iter++; 
    count++; 
        
    } while ((exp(val) - result) > eps);
    

    std::cout << result << " " << "in " << count << " number of iterations"; 

    

}