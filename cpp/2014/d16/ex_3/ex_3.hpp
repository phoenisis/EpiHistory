//
// ex_3.hpp for  in /home/pidoux_q/data/cpp/d16/ex_3
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 19 14:52:15 2011 quentin PIDOUX
// Last update Wed Jan 19 15:52:09 2011 quentin PIDOUX
//

#include <string>
#include <iostream>

template<typename T>
void foreach(T* a, void (*p)(T), size_t c)
{
    size_t i = 0;
    
    if (c == 0)
        return ;
    else
        while(i != c)
        {
            p(a[i]);
            i++;
        }
}

template<typename U>
void print(U a)
{
    std::cout << a << std::endl;
}
