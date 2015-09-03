#include "randomtextgenerator.h"

#include <sstream>
#include <iostream>
#include <tuple>

RandomTextGenerator::RandomTextGenerator(std::istream &learning_data)
{
    std::string pptoken;
    std::string ptoken;
    std::string token;

    while(learning_data >> token)
    {
        auto tail = std::make_tuple(pptoken, ptoken);
        auto it = m_marcov_chains.find(tail);
        if(it != m_marcov_chains.end())
        {
            auto token_it = (*it).second.find(token);
            if(token_it != (*it).second.end())
            {
                (*token_it).second += 1;
            }
            else
            {
                (*it).second.insert(std::make_pair(token, 1));
            }
        }
        else
        {
            std::map<std::string, int> heads;
            heads.insert(std::make_pair(token, 1));
            m_marcov_chains.insert(std::make_pair(tail, heads));
        }
        pptoken = ptoken;
        ptoken = token;
    }
}

std::map<std::string, int> RandomTextGenerator::next_options(std::tuple<std::string, std::string> tail)
{
    auto it = m_marcov_chains.find(tail);
    if(it == m_marcov_chains.end())
    {
        return { };
    }
    return (*it).second;
}
