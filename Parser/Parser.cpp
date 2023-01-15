#pragma once
#include "Parser.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include "..\Tag\Tag.cpp"
#include "..\Validator\Validator.cpp"
#include "..\Evaluator\Evaluator.cpp"

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

inline std::vector<Tag> Parser::parseTagFromFile(const char* file) 
{   
    std::ifstream in(file);
    std::string myString;
    std::ofstream errorLogger;
    errorLogger.open("errors.txt", std::ios::app);
    auto currTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currTime);
    
    errorLogger  << std::ctime(&time) << "Errors history\n";
    std::vector<Tag> result;
    
        while (!in.eof())
        {
            Tag tag;
            std::getline(in, myString);
            std::cout << "All string: " << myString << std::endl;
            Validator valid;
            std::string parameter = "";
            if(hasParameter(myString)){
                parameter = extractParam(myString, "\"", '"');
                unsigned pos = myString.find(parameter);
                myString = myString.erase(pos, parameter.length());
                myString.erase(std::remove(myString.begin(), myString.end(), '"'), myString.end());
            }

            //tag.opentag = <MAP-INC>
            std::string openTag = extractParam(myString, "<", '>');
            openTag.erase(std::remove(openTag.begin(), openTag.end(), ' '), openTag.end());
            if(valid.validateOpenTag(openTag)){
                tag.setOpenTag(openTag);
            } else {
                auto currTime = std::chrono::system_clock::now();
                time = std::chrono::system_clock::to_time_t(currTime);
                errorLogger << std::ctime(&time) << "Invalid open tag!\n";
                continue;
            }
            std::cout << "Open tag: " << openTag << std::endl;


            //parameter
            if (parameter!="")
            {
                if(!valid.operRequiresParam(openTag)){
                    auto currTime = std::chrono::system_clock::now();
                    time = std::chrono::system_clock::to_time_t(currTime);
                    errorLogger  << std::ctime(&time) << "This operation must have no parameter!\n" << parameter << "\n";
                    continue;
                }
                if (valid.validateParameter(parameter)) {
                    tag.setParameter(parameter);
                } else {
                    auto currTime = std::chrono::system_clock::now();
                    time = std::chrono::system_clock::to_time_t(currTime);
                    errorLogger  << std::ctime(&time) << "Invalid parameter!\n" << parameter << "\n";
                    continue;
                }
            } else {
                if(valid.operRequiresParam(openTag)){
                    auto currTime = std::chrono::system_clock::now();
                    time = std::chrono::system_clock::to_time_t(currTime);
                    errorLogger  << std::ctime(&time) << "This operation must have parameter!\n" << parameter << "\n";
                    continue;
                }
            }

            std::string closeTag = extractParam(myString, "</", '>');
            closeTag.erase(std::remove(closeTag.begin(), closeTag.end(), '/'), closeTag.end());
            if(valid.validateCloseTag(closeTag, openTag)){
                tag.setCloseTag(closeTag);
            } else {
                auto currTime = std::chrono::system_clock::now();
                time = std::chrono::system_clock::to_time_t(currTime);
                errorLogger << std::ctime(&time) << "Invalid close tag!\n";
                continue;
            }
            std::cout << "Close tag: " << closeTag << std::endl;


            //tag.data = "1 2 3"
            std::string data = extractParam(myString, ">", '<');
            if(data.size() > 0){
                if(valid.validateData(data)){
                    tag.setData(data);
                } else {
                    auto currTime = std::chrono::system_clock::now();
                    time = std::chrono::system_clock::to_time_t(currTime);
                    errorLogger << std::ctime(&time) << "Invalid data!\n";
                    continue;
                }
            }
            else {
                auto currTime = std::chrono::system_clock::now();
                time = std::chrono::system_clock::to_time_t(currTime);
                errorLogger << std::ctime(&time) << "No data found!\n";
                continue;
            }
            
            std::cout << "Data: " << data << std::endl;

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
        out.open("../errors.txt");
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