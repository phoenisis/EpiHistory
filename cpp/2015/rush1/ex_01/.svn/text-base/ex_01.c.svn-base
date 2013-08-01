#include "new.h"
#include "point.h"

int main()
{
    Object* tab[100];
    unsigned int i;
    for (i = 0; i < 10; i++)
        tab[i] = new(Point);
    for (i = 0; i < 10; i++)
        delete(tab[i]);
    return 0;
}
