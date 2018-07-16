#include <iostream>
#include "Festival.h"
#include <festival/festival.h>
#include <map>
#include <unistd.h>

std::map<std::string, std::string> s_polishLettersCoverter
{
    {"ą", "o~"},
    {"ć", "c~"},
    {"ę", "e~"},
    {"ł", "l/"},
    {"ń", "n~"},
    {"ó", "u" },
    {"ś", "s~"},
    {"ź", "z~"},
    {"ż", "z*"}
};

Festival* Festival::instance(ad_rec_s *p_ad)
{
    if (!s_instance)
        if (p_ad)
        {
            std::cout << __FUNCTION__ << "ad_rec_s is NULL!" << std::endl;
            return NULL;
        }
        s_instance = new Festival();
    return s_instance;
}

void Festival::sayText(std::string&& p_stringToSay)
{
        ad_stop_rec(m_ad);
        replace(p_stringToSay);
        festival_say_text(p_stringToSay.c_str());
            std::cout << __FUNCTION__ << "festival_say_text!" << std::endl;
        usleep(100000);
        ad_start_rec(m_ad);
            std::cout << __FUNCTION__ << "ad_start_rec!" << std::endl;
}

void Festival::replace(std::string& p_string)
{
    for (auto pair : s_polishLettersCoverter)
    {
        size_t index;
        while ((index = p_string.find(pair.first)) !=  std::string::npos)
            p_string.replace(index, pair.second.size(), pair.second);
    }
}
