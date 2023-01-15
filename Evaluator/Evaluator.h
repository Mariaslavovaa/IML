#include <iostream>
#pragma once
#include "..\Tag\Tag.cpp"
#include "..\LList\LList.cpp"


class Evaluator{
    public:
    //converting string
    inline LList<double> convertToList(std::string str);
    inline double convertToDouble(std::string str);
    inline int convertToInt(std::string str);

    public:
    inline LList<double> evaluate_expression(Tag tag);

};