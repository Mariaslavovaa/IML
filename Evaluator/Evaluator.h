#include <iostream>
#pragma once
#include "..\Tag\Tag.cpp"
#include "..\LList\LList.cpp"


class Evaluator{
    public:
    //Converting string to list and number
    inline LList<double> convertToList(std::string str);
    inline double convertToDouble(std::string str);
    inline int convertToInt(std::string str);

    public:
    //performs the operation on the list
    //tag - The tag for convert
    //returns - the converted list
    inline LList<double> evaluate_expression(Tag tag);

};