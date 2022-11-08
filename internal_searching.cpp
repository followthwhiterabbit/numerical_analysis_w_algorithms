#include <iostream>
#include <iomanip>
#include <fstream>

#include "gnuplot.h"


inline float func(float x)
{
    return (x*x*x - 9*x + 1 ); 
}              

void internal_search()
{
    std::ofstream plot_file; 
    plot_file.open("plot.dat"); 

    float xi, xf, dx, x, y; 
    char option; 
    std::cout << "For default input values enter 'y' else 'n'\n"; 
    std::cin >> option;
    if(option == 'y')
        {
            xi = 0; 
            xf = 10; 
            dx = 1; 
        }
    else
        {
            std::cout << "input initial, final, step-size values, xi, xf and dx\n"; 
            std::cin >> xi >> xf >> dx; 
        }
        x = xi; 
        std::cout << "x\ty\n"; 
        while(x < xf)
        {
            y = func(x);
            std::cout << x << std::setprecision(4) << "\t" <<  y << std::endl; 
            plot_file << x << std::setprecision(4) << "\t" << y << std::endl; 
            x = x + dx; 
        }

        plot_file.close(); 

}


int main()
{

    gnuplot p; // object of class gnuplot  
    internal_search(); 
    p("set term postscript eps"); // gnuplot command for eps file format
    p("set output \"plot.eps\" "); // setting name of output file  
    p("plot \'./plot.dat\' u 1:2 w l"); // plot command    
    


}