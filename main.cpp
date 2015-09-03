#include <iostream>
#include <fstream>

#include "randomtextgenerator.h"

int main()
{
    std::ifstream f("test.txt");
    RandomTextGenerator rtg(f);

    for(auto opt : rtg.next_options(std::make_tuple("of", "the")))
    {
        std::cout << opt.first << " : " << opt.second << "\n";
    }

    return 0;
}

