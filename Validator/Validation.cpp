#include "Validation.h"
#include <stack>
#include <algorithm>
#include <iostream>


bool Validation::rightBrackets(const std::string& expression) {
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


bool Validation::checkOperation(std::string operation){
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
std::string Validation::extractOpenTagOperation(std::string openTag){
    std::string openTagOperation = openTag.erase(openTag.find('<'), openTag.find('<'));
    openTagOperation= openTag.erase(openTag.find('>'), openTag.find('>')); 
    return openTagOperation;
}

std::string Validation::extractCloseTagOperation(std::string closeTag){

    std::string closeTagOperation = closeTag.erase(closeTag.find('<'), closeTag.find('<') + 1);
    closeTagOperation= closeTag.erase(closeTag.find('>'), closeTag.find('>'));
    return closeTagOperation;
}

bool Validation::validateOpenTag(std::string openTag){
    // if (!this->rightBrackets(openTag))
    // {
    //     return false;
    // }
    // std::string operation = extractOpenTagOperation(openTag);
    // return checkOperation(operation) == true;

    return this->checkOperation(openTag);
}

bool Validation::validateCloseTag(std::string closeTag, std::string openTag){
    // if (!this->rightBrackets(closeTag) || closeTag[closeTag.find('<') + 1] != '/')
    // {
    //     return false;
    // }
    // std::string openTagOperation = extractOpenTagOperation(openTag);
    // std::string closeTagOperation = extractCloseTagOperation(closeTag);
    // return checkOperation(closeTagOperation) == true && openTagOperation == closeTagOperation;

    return this->checkOperation(openTag) && this->checkOperation(closeTag) && closeTag == openTag;
}

bool Validation::validateParameter(std::string parameter){
    if (parameter == "ASC" || parameter == "DSC")
    {
        return true;
    }
    // //stoi?   stod
    // try
    // {
    //     int param = std::stoi(parameter);
    // }
    // catch(const std::invalid_argument& e)
    // {
    //     // errorLogger  << std::ctime(&time) << "Invalid parameter!\n" << parameter << "\n";
    // }
    
    for (size_t i = 0; i < parameter.size(); i++)
    {
        if(parameter[i] < '0' || parameter[i] > '9'){
            return false;
        } 
    }
    return true; 
}


// int main(){

//     Validation val;
//     std::cout << std::boolalpha << val.validateOpenTag("MAP-MLT ") << std::endl;
//     std::cout << std::boolalpha << val.validateParameter("2") << std::endl;

//     return 0;
// }