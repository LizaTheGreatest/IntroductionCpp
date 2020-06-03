#include <iostream>
#include "String.h"



int main()
{
    String g = "GAME";
    String o = "OVER";

    String go = g + ' ' + o + '\n';
    std::cout<<go<<'\n';

    g.push_back(' ');
    g.append("IS NOT ");
    g.append(o);
    std::cout<<g<<'\n';



    return 0;
}
