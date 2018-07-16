#pragma once
#include <sphinxbase/ad.h>

class Festival
{
    public:
    void sayText(std::string&&);
    static Festival* instance(ad_rec_s *p_ad = NULL);
    static Festival* s_instance;

    private:
    void replace(std::string&);
    Festival(){};
    ad_rec_s* m_ad;
};
