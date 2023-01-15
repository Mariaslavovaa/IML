#include "Validator.h"
#include <stack>
#include <algorithm>
#include <iostream>
#include <fstream>
#pragma once


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

inline bool Validator::validateParameter(const std::string& parameter){  
    if (parameter == "ASC" || parameter == "DSC")
    {
        return true;
    }

    size_t count = 0;
    for (size_t i = 0; i < parameter.size(); i++){ 
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
