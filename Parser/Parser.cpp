#pragma once
#include "Parser.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include "..\Tag\Tag.cpp"
#include "..\Validator\Validator.cpp"
#include "..\Evaluator\Evaluator.cpp"
#include "../Constants/Constants.cpp"

//here you read and parse the file string 

inline std::string Parser::extractParam(const std::string expr, const std::string startElem, const char end){

    unsigned start = expr.find(startElem);
    if (start > expr.size())
    {
        return NULL;
    }
    ++start;
    std::string res;
    while (expr[start] != end)
    {
        res += expr[start];
        start++;
    }
    
    return res;
}

inline bool Parser::hasParameter(const std::string expr){
    for (size_t i = 0; i < expr.size(); i++)
    {
        if (expr[i] == '"')
        {
            return true;
        }
    }
    return false;
}

inline void Parser::logError(std::string errorMsg){
    Constants c;
    std::ofstream errorLogger;
    errorLogger.open(c.errorLoggingFilePath, std::ios::app);
    auto currTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currTime);
    
    errorLogger  << std::ctime(&time) << errorMsg << std::endl;
    errorLogger.close();
}

inline std::vector<Tag> Parser::parseTagFromFile(const char* file) 
{   
    Constants c;
    std::ifstream in(file);
    std::string myString;
    std::vector<Tag> result;
    
        while (!in.eof())
        {
            Tag tag;
            std::getline(in, myString);
            Validator valid;
            std::string parameter = "";
            if(hasParameter(myString)){
                parameter = extractParam(myString, "\"", '"');
                unsigned pos = myString.find(parameter);
                myString = myString.erase(pos, parameter.length());
                myString.erase(std::remove(myString.begin(), myString.end(), '"'), myString.end());
            }

            std::string openTag = extractParam(myString, "<", '>');
            openTag.erase(std::remove(openTag.begin(), openTag.end(), ' '), openTag.end());
            if(valid.validateOpenTag(openTag)){
                tag.setOpenTag(openTag);
            } else {
                logError(c.invalidOpenTagError);
                continue;
            }

            //parameter
            if (parameter!="")
            {
                if(!valid.operRequiresParam(openTag)){
                    logError(c.mushHaveNoParamError);
                    continue;
                }
                if (valid.validateParameter(parameter)) {
                    tag.setParameter(parameter);
                } else {
                    logError(c.invalidParamError);
                    continue;
                }
            } else {
                if(valid.operRequiresParam(openTag)){
                    logError(c.mushHaveParamError);
                    continue;
                }
            }

            std::string closeTag = extractParam(myString, "</", '>');
            closeTag.erase(std::remove(closeTag.begin(), closeTag.end(), '/'), closeTag.end());
            if(valid.validateCloseTag(closeTag, openTag)){
                tag.setCloseTag(closeTag);
            } else {
                logError(c.invalidCloseTagError);
                continue;
            }

            std::string data = extractParam(myString, ">", '<');
            if(data.size() > 0){
                if(valid.validateData(data)){
                    tag.setData(data);
                } else {
                    logError(c.invalidDataError);
                    continue;
                }
            }
            else {
                logError(c.noDataError);
                continue;
            }
            result.push_back(tag);
        }
    in.close();
    return result;
}

inline void Parser::writeIntoFile(const char* _fileName, LList<double> list){
    std::ofstream out;
    out.open(_fileName,std::ios_base::app);
    if(!out){
        out.close();
        out.open("errors.txt", std::ios::app);
        out << "Invalid output file!\n";
        out.close();
    }
    list.printFile(out);
    out << "\n";
    out.close();
}



// int main(){
//     Parser p;
    
//     std::cout << p.parseTagFromFile("../example_input.txt").getOpenTag();

//     // std::ofstream out;
//     // p.writeIntoFile("../example_output.txt", out);

//     return 0;
// }