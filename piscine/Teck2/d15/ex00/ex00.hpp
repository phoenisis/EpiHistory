#ifndef _EX00_H_
#define _EX00_H_

template<typename T>
T add(const T &a, const T &b)
{
  T c = a+b;
    return (c);
}

template<typename U>
void swap(U& a, U& b)
{
    U tmp;
    tmp = b;
    b = a;
    a = tmp;
}

template<typename V>
V min(const V &a, const V &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template<typename W>
W max(const W &a, const W &b)
{
    if (a > b)
        return a;
    else
        return b;
}


#endif
