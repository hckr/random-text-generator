#include "randomtextgenerator.h"

#include <sstream>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstdlib>

RandomTextGenerator::RandomTextGenerator(std::istream &learning_data)
{
    std::string pptoken;
    std::string ptoken;
    std::string token;

    while(learning_data >> token)
    {
        auto starting_with = std::make_tuple(pptoken, ptoken);
        auto it = m_marcov_chains.find(starting_with);
        if(it != m_marcov_chains.end())
        {
            auto &successors = (*it).second;
            if(std::find(successors.begin(), successors.end(), token) == successors.end())
            {
                successors.push_back(token);
            }
        }
        else
        {
            m_marcov_chains.insert({starting_with, {token}});
        }
        pptoken = ptoken;
        ptoken = token;
    }
}

std::vector<std::string> RandomTextGenerator::possible_successors(std::tuple<std::string, std::string> starting_with)
{
    auto it = m_marcov_chains.find(starting_with);
    if(it == m_marcov_chains.end())
    {
        return { };
    }
    return (*it).second;
}

std::string RandomTextGenerator::generate_text(std::tuple<std::string, std::string> starting_with, int max_words)
{
    std::string pptoken = std::get<0>(starting_with);
    std::string ptoken = std::get<1>(starting_with);
    std::string text = pptoken + " " + ptoken;
    std::string token;

    while(max_words--)
    {
        auto possible_tokens = possible_successors(starting_with);
        size_t tokens_count = possible_tokens.size();
        if(tokens_count == 0)
            break;
        int index = rand() % possible_tokens.size();
        token = possible_tokens[index];
        text += " " + token;
        pptoken = ptoken;
        ptoken = token;
        starting_with = std::make_tuple(pptoken, token);
    }

    return text;
}
