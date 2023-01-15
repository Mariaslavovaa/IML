#pragma once
#include "Operations.h"

//MAP
inline void Operations::map_inc(LList<double>& list,const double number){
    list.map_increment(number);
}

inline void Operations::map_mlt(LList<double>& list,const double number){
    list.map_multiply(number);
}

//AGG
inline void Operations::agg_sum(LList<double>& list){
    LList<double> newList;
    double element = list.agg_summation();
    newList.push_back(element);
    list = newList;
}

inline void Operations::agg_pro(LList<double>& list){
    LList<double> newList;
    double element = list.agg_product();
    newList.push_back(element);
    list = newList;
}

inline void Operations::agg_avg(LList<double>& list){
    LList<double> newList;
    double element = list.agg_average();
    newList.push_back(element);
    list = newList;
}

inline void Operations::agg_fst(LList<double>& list){
    LList<double> newList;
    double element = list.agg_first();
    newList.push_back(element);
    list = newList;
}

inline void Operations::agg_lst(LList<double>& list){
    LList<double> newList;
    double element = list.agg_last();
    newList.push_back(element);
    list = newList;
}

//SRT
inline void Operations::srt_rev(LList<double>& list){
    list.reverse();
}

inline void Operations::srt_ord(LList<double>& list, const std::string ordered){
    list.srt_ord(ordered);
}

inline void Operations::srt_slc(LList<double>& list, int index){
    list.srt_slc(index);
}

inline void Operations::srt_dst(LList<double>& list){
    list.remove_duplicates();
}
