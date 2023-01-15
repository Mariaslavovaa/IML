#pragma once
#include "..\LList\LList.cpp"
#include <string>

class Operations{

    private:
    LList<double> list;

    public:
    //MAP functions
    inline void map_inc(LList<double>& list,const double number);
    inline void map_mlt(LList<double>& list,const double number);

    //AGG functions
    inline void agg_sum(LList<double>& list);
    inline void agg_pro(LList<double>& list);
    inline void agg_avg(LList<double>& list);
    inline void agg_fst(LList<double>& list);
    inline void agg_lst(LList<double>& list);

    //SRT functions
    inline void srt_rev(LList<double>& list);
    inline void srt_ord(LList<double>& list, const std::string ordered);
    inline void srt_slc(LList<double>& list, int index);
    inline void srt_dst(LList<double>& list);
};