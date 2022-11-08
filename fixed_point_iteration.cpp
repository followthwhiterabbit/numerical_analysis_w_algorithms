/*
Algorithm for Fixed-Point iteration method 

1- input the initial value of root 
2- input maximum number of iterations; maxit
3- For count = 1 to maxit in steps of 1 
    c = f(a)
if((c - a)/c) > eps
    a = c
else
    exit for loop 

output root, count, f(root)
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "gnuplot.h"


#define eps 0.000001

inline float f(float x)
{
    return 1 / (9 - x*x); 
}

void fixed_point_iteration()
{
     std::ofstream plot_file; 
     plot_file.open("plot.dat"); 


    float a, c; 
    int count, max_iteration; 
    char op; 
    std::cout << "For default input values enter 'y' else 'n'\n";
    std::cin >> op; 
    if (op == 'y')
        a = 0; 
    else    
        {
            std::cout << "input initial root value\n"; 
            std::cin >> a; 
        }
    max_iteration = 50; 
    for(count = 1; count <= max_iteration; count++)
    {
        c = f(a); // we return the y value with the initial root 
        plot_file << a << std::setprecision(4) << "\t" << c << std::endl; 
        if (fabs((c - a)/c) > eps)  // we check for the accuracy of the operation
            a = c;                  // current y value - old y value(initially root as 0 or the one we defined)
        else                        // over the current y value to check for the relative error 
            break;
    }
    std::cout << "root= " << c << std::endl; 
    std::cout << "f(root)= " << f(c) << std::endl; 
    std::cout << "iterations= " << count  << std::endl; 

}

int main()
{
    gnuplot p; 
    
    fixed_point_iteration();
    p("set term postscript eps"); // gnuplot command for eps file format
    p("set output \"plot.eps\" "); // setting name of output file  
    p("plot \'./plot.dat\' u 0:0.2  w l "); // plot command     
}


