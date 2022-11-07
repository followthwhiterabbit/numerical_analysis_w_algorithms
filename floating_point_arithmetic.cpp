#include <iostream>
#include <cmath>


class operation
{
    public:


    void get()
    {
        std::cout << "enter mantissa & exponent, m1, e1 and m2, e2 " << std::endl;
        std::cin >> m1 >> e1 >> m2 >> e2; 
        
    }
    void add()
    {

        b = e1 - e2; 
        if (b >= 0)
            {
                e = e1; 
                m2 = m2 / pow(10, fabs(b)); 
            }
        else
            {
                e = e2; 
                m1 = m1 / pow(10, fabs(b)); 
            }

        m = m1 + m2 ; 
        if (m > 1)
            {
                m = m / 10; 
                e = e + 1; 

            }
        std::cout << "sum: " << m << "e" << e << std::endl; 

    }

    void sub()
    {
        b = e1 - e2; 
        if (b >= 0)
            {
                e = e1; 
                m2 = m2 / pow(10, fabs(b)); 

            }
        else
            {
                e = e2; 
                m1 = m1 / pow(10, fabs(b)); 
            }
        m = m1 - m2; 
    do
    {
        m *= 10; 
        e = e - 1;
    } while (fabs(m) < 0.1);
    std::cout << "difference is: " << m << "e" << e << std::endl; 

    }

    void multip()
    {
        m = m1 * m2; 
        e = e1 + e2; 
        while (fabs(m) < 0.1)
            {
                m *= 10; 
                e = e - 1; 

            }
        while (fabs(m) >= 1)
        {
            m /= 10; 
            e = e + 1; 
        }
        if (e > 99)
            std::cout << "number overflow\n"; 
        else if (e < -99)
            std::cout << "number underflow\n"; 
        else
        {
            std::cout << "multiplication: " << m << "e" << e << std::endl; 
        }
    }

    void division()
    {
        m = m1 / m2; 
        e = e1 - e2; 
        while(fabs(m) < 0.1)
            {
                m = m*10; 
                e = e - 1; 
            }
        while(fabs(m) >= 1)
            {
                m = m / 10; 
                e = e + 1; 
            }
        if (e > 99)
            std::cout << "number overflow" << std::endl; 
        else if (e < -99)
            std::cout << "number underflow" << std::endl; 
        else
        {
            std::cout << "division is: " << m << "e" << e << std::endl; 
        }



    }


private:
    float m, m1, e, e1, m2, e2, b; 





}; 



int main()
{
operation op; 
char operation; 
op.get(); 

std::cout << "enter option: (a)-addition, (s)-subtraction, (m)-multiplication, (d)-division" << std::endl; 

std::cin >> operation; 

if(operation == 'a')
{
    op.add(); 
}
else if (operation == 's')
{
    op.sub(); 
}
else if (operation == 'm')
{
    op.multip(); 

}
else if (operation == 'd')
{
    op.division(); 
}



 




}