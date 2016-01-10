#ifndef RANDOMTEXTGENERATOR_H
#define RANDOMTEXTGENERATOR_H

#include <map>
#include <vector>
#include <string>
#include <tuple>

class RandomTextGenerator
{
    std::map<std::tuple<std::string, std::string>, std::vector<std::string>> m_marcov_chains;
public:
    RandomTextGenerator(std::istream &learning_data);
    std::vector<std::string> possible_successors(std::tuple<std::string, std::string> starting_with);
    std::string generate_text(std::tuple<std::string, std::string> starting_with, int max_words);
};

#endif // RANDOMTEXTGENERATOR_H
