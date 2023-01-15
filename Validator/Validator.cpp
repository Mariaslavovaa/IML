#include "Validator.h"
#include <stack>
#include <algorithm>
#include <iostream>
#include <fstream>
#pragma once


inline bool Validator::rightBrackets(const std::string& expression) {
    std::stack<char> brackets;

    if(std::count(expression.begin(), expression.end(), '<') != 1 &&
       std::count(expression.begin(), expression.end(), '>') != 1){
            return false;
    }
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '<') {
            brackets.push(expression[i]);
        }
        else {
            if(expression[i] == '>') {
                if(brackets.top() == '<') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return brackets.empty();
}

inline bool Validator::checkOperation(const std::string& operation){
    if (operation == "MAP-INC") {
        return true;
    } else if(operation == "MAP-MLT") {
        return true;
    } else if(operation == "AGG-SUM") {
        return true;
    } else if(operation == "AGG-PRO") {
        return true;
    } else if(operation == "AGG-AVG" ) {
        return true;
    } else if(operation == "AGG-FST") {
        return true;
    } else if(operation == "AGG-LST") {
        return true;
    } else if(operation == "SRT-REV") {
        return true;
    } else if(operation == "SRT-ORD") {
        return true;
    } else if(operation == "SRT-SLC") {
        return true;
    } else if(operation == "SRT-DST") {
        return true;
    } else {
        return false;
    }
}

// extract into external private method extractOpenTagOperation, extractCloseTagOperation
inline std::string Validator::extractOpenTagOperation(std::string& openTag){

    std::string openTagOperation = openTag.erase(openTag.find('<'), openTag.find('<'));
    openTagOperation= openTag.erase(openTag.find('>'), openTag.find('>')); 
    return openTagOperation;
}

inline std::string Validator::extractCloseTagOperation(std::string& closeTag){

    std::string closeTagOperation = closeTag.erase(closeTag.find('<'), closeTag.find('<') + 1);
    closeTagOperation= closeTag.erase(closeTag.find('>'), closeTag.find('>'));
    return closeTagOperation;
}

inline bool Validator::validateOpenTag(const std::string& openTag){
    return this->checkOperation(openTag);
}

inline bool Validator::validateCloseTag(const std::string& closeTag, const std::string& openTag){
    return this->checkOperation(openTag) && this->checkOperation(closeTag) && closeTag == openTag;
}

inline bool Validator::validateParameter(const std::string& parameter){  //-2.2
    if (parameter == "ASC" || parameter == "DSC")
    {
        return true;
    }

    size_t count = 0;
    for (size_t i = 0; i < parameter.size(); i++){  /// -12.5
        if(parameter[i] == '.'){
            count++;
        }
        if (i == 0 && parameter[i] == '-')
        {
            continue;
        }
        
        if (parameter[i] != '.')
        {
            if(!(parameter[i] >= '0' && parameter[i] <= '9')){
                return false;
            }
        }
        
    }
    return true;
}

inline bool Validator::validateData(const std::string& data){

    for (size_t i = 0; i < data.size(); i++)
    {
        if(data[i] == ' '){
            continue;
        }
        if(data[i] < '0' || data[i] > '9'){
            return false;
        } 
    }
    return true; 
}

inline bool Validator::operRequiresParam(const std::string& operation){
    if (operation == "MAP-INC") {
        return true;
    } else if(operation == "MAP-MLT") {
        return true;
    } else if(operation == "SRT-ORD") {
        return true;
    } else if(operation == "SRT-SLC") {
        return true;
    } else {
        return false;
    }
}




// int main(){

//     Validator val;
//     // std::cout << std::boolalpha << val.validateOpenTag("MAP-MLT ") << std::endl;
//     // std::cout << std::boolalpha << val.validateParameter("2") << std::endl;
//     // std::cout << val.removeSpaces("1 2 3") << std::endl;
//     // std::string s = val.removeSpaces("1 2 3");
//     std::cout << std::boolalpha << val.validateParameter("1300008") << std::endl;


//     return 0;
// }