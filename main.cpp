#include <iostream>
#include "gra.h"
using namespace std;

int main()
{
   gra Gra;

    //petla gry
    while (Gra.dziala())
    {


        //update
        Gra.update();

        //render
        Gra.render();


    }

    return 0;
}
