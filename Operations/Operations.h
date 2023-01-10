#include "..\LList\LList.cpp"
#include <string>

class Operations{

    private:
    LList<double> t;

    public:
    //MAP
    void map_inc(LList<double>& t, double n);
    void map_mlt(LList<double>& t, double n);

    //AGG
    void agg_sum(LList<double>& t);
    void agg_pro(LList<double>& t);
    void agg_avg(LList<double>& t);
    void agg_fst(LList<double>& t);
    void agg_lst(LList<double>& t);

    //SRT
    void srt_rev(LList<double>& t);
    void srt_ord(LList<double>& t, std::string s);
    void srt_slc(LList<double>& t, int index);
    void srt_dst(LList<double>& t);


};