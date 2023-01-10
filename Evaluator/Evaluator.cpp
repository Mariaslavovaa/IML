#pragma once
#include "Evaluator.h"
#include "..\Operations\Operations.cpp"
#include <fstream>

LList<double> Evaluator::convertToList(std::string s){

    std::string temp;
    LList<double> list;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            double number = std::stod(temp);
            list.push_back(number);
            temp = "";
            continue;
        }
        temp += s[i];
    }
    if(temp != ""){
        double number = std::stod(temp);
        list.push_back(number);
    }
    return list;
}

//or stringConvertToDouble?
double Evaluator::convertToDouble(std::string s){
    double number = std::stod(s);
    return number;
}

int Evaluator::convertToInt(std::string s){
    int number = std::stoi(s);
    return number;
}

LList<double> Evaluator::evaluate_expression(Tag t){
    LList<double> l = convertToList(t.getData());
    std::string operation = t.getOpenTag();
    std::ofstream output("result.txt");
    Operations oper;

    if (operation == "MAP-INC") {
        double number = convertToDouble(t.getParameter());
        oper.map_inc(l, number);
    } else if(operation == "MAP-MLT") {
        double number = convertToDouble(t.getParameter());
        oper.map_mlt(l, number);
    } else if(operation == "AGG-SUM") {
        oper.agg_sum(l);
    } else if(operation == "AGG-PRO") {
        oper.agg_pro(l);
    } else if(operation == "AGG-AVG" ) {
        oper.agg_avg(l);
    } else if(operation == "AGG-FST") {
        oper.agg_fst(l);
    } else if(operation == "AGG-LST") {
        oper.agg_lst(l);
    } else if(operation == "SRT-REV") {
        oper.srt_rev(l);
    } else if(operation == "SRT-ORD") {
        std::string param = t.getParameter();
        oper.srt_ord(l, param);
    } else if(operation == "SRT-SLC") {
        int index = convertToInt(t.getParameter());
        oper.srt_slc(l, index);
    } else if(operation == "SRT-DST") {
        oper.srt_dst(l);
    } 
    output << "----------RESULT-----------\n";
    l.printFile(output);
    return l;
}

// int main(){

//     Evaluator e;
//     std::string num = "123";
//     Tag t;
//     t.setCloseTag("MAP-INC");
//     t.setOpenTag("MAP-INC");
//     t.setData("1 2 3");
//     t.setParameter("1");
//     e.evaluate_expression(t).print();
//     int result = e.convertToInt(num);
//     //std::cout << result << "\n";

//     return 0;
// }
