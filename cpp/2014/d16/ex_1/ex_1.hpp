//
// ex_1.hpp for  in /home/pidoux_q/data/cpp/d16/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 19 12:32:03 2011 quentin PIDOUX
// Last update Thu Jan 20 00:19:47 2011 quentin pidoux
//

template<typename T>
int compare(const T& a, const T& b)
{
    if (a == b)
        return (0);
    else if (a < b)
        return (-1);
    else
        return (1);
}

template<typename T>
int compare(const T<char *> &a, const T& b)
{
    if (a == b)
        return (0);
    else if (a < b)
        return (-1);
    else
        return (1);
}