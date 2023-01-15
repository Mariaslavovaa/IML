#pragma once
#include "Evaluator.h"
#include "..\Operations\Operations.cpp"
#include <fstream>

inline LList<double> Evaluator::convertToList(std::string str){

    std::string temp;
    LList<double> list;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            double number = std::stod(temp);
            list.push_back(number);
            temp = "";
            continue;
        }
        temp += str[i];
    }
    if(temp != ""){
        double number = std::stod(temp);
        list.push_back(number);
    }
    return list;
}

inline double Evaluator::convertToDouble(std::string str){
    try
    {
        return std::stod(str);
    }
    catch(const std::exception& e)
    {
        std::ofstream out;
        out.open("../errors.txt");
        out << e.what() << str << std::endl;
        out.close();
    }
}

inline int Evaluator::convertToInt(std::string str){
    int number = std::stoi(str);
    return number;
}

inline LList<double> Evaluator::evaluate_expression(Tag tag){
    LList<double> list = convertToList(tag.getData());
    std::string operation = tag.getOpenTag();
    Operations oper;

    if (operation == "MAP-INC") {
        if(tag.getParameter().size() > 0){
            double number = convertToDouble(tag.getParameter());
            oper.map_inc(list, number);
        }
    } else if(operation == "MAP-MLT") {
        if(tag.getParameter().size() > 0){
            double number = convertToDouble(tag.getParameter());
            oper.map_mlt(list, number);
        }
    } else if(operation == "AGG-SUM") {
        oper.agg_sum(list);
    } else if(operation == "AGG-PRO") {
        oper.agg_pro(list);
    } else if(operation == "AGG-AVG" ) {
        oper.agg_avg(list);
    } else if(operation == "AGG-FST") {
        oper.agg_fst(list);
    } else if(operation == "AGG-LST") {
        oper.agg_lst(list);
    } else if(operation == "SRT-REV") {
        oper.srt_rev(list);
    } else if(operation == "SRT-ORD") {
        std::string param = tag.getParameter();
        oper.srt_ord(list, param);
    } else if(operation == "SRT-SLC") {
        int index = convertToInt(tag.getParameter());
        oper.srt_slc(list, index);
    } else if(operation == "SRT-DST") {
        oper.srt_dst(list);
    } 

    return list;
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
