#include <iostream>
#pragma once
#include "..\Tag\Tag.cpp"
#include "..\LList\LList.cpp"


class Evaluator{
    public:
    //converting 
    LList<double> convertToList(std::string s);
    double convertToDouble(std::string s);
    int convertToInt(std::string s);

    public:
    //Не знам как да я кръстя и какво да върна
    LList<double> evaluate_expression(Tag t);

};