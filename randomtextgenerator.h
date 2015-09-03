#ifndef RANDOMTEXTGENERATOR_H
#define RANDOMTEXTGENERATOR_H

#include <map>
#include <string>
#include <tuple>

class RandomTextGenerator
{
    std::map<std::tuple<std::string, std::string>, std::map<std::string, int>> m_marcov_chains;
public:
    RandomTextGenerator(std::istream &learning_data);
    std::map<std::string, int> next_options(std::tuple<std::string, std::string> tail);
};

#endif // RANDOMTEXTGENERATOR_H
