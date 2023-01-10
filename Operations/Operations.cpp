#pragma once
#include "Operations.h"



//MAP
void Operations::map_inc(LList<double>& t, double n){
    t.map_increment(n);
}

void Operations::map_mlt(LList<double>& t, double n){
    t.map_multiple(n);
}

//AGG
void Operations::agg_sum(LList<double>& t){
    LList<double> newList;
    //change name
    double element = t.agg_sumary();
    newList.push_back(element);
}

void Operations::agg_pro(LList<double>& t){
    LList<double> newList;
    double element = t.agg_product();
    newList.push_back(element);
}

void Operations::agg_avg(LList<double>& t){
    LList<double> newList;
    double element = t.agg_average();
    newList.push_back(element);
}

void Operations::agg_fst(LList<double>& t){
    LList<double> newList;
    double element = t.agg_first();
    newList.push_back(element);
}

void Operations::agg_lst(LList<double>& t){
    LList<double> newList;
    double element = t.agg_last();
    newList.push_back(element);
}

//SRT
void Operations::srt_rev(LList<double>& t){
    t.reverse();
}

void Operations::srt_ord(LList<double>& t, std::string s){

}

void Operations::srt_slc(LList<double>& t, int index){
    t.srt_slc(index);
}

void Operations::srt_dst(LList<double>& t){
    t.remove_duplicates();
}
