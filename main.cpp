#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

#include "randomtextgenerator.h"

int main()
{
    srand(time(0));

    std::istringstream stream("Say A, then say B, then say C, then say D, then say E, then say F.");
    RandomTextGenerator rtg(stream);

    std::cout << rtg.generate_text(std::make_tuple("Say", "A,"), 100) << "\n";

    return 0;
}

