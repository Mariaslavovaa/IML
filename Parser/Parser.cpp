#pragma once
#include "Parser.h"
#include <string>
#include <algorithm>
// #include <fstream>
#include <chrono>
#include <ctime>
#include "..\Tag\Tag.cpp"
#include "..\Validator\Validation.cpp"
#include "..\Evaluator\Evaluator.cpp"

//here you read and parse the file string 

std::string Parser::extractParam(std::string expr, std::string startElem, char end){

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

bool Parser::hasParameter(std::string expr){
    for (size_t i = 0; i < expr.size(); i++)
    {
        if (expr[i] == '"')
        {
            return true;
        }
    }
    return false;
}

void Parser::parseTagFromFile(std::ifstream& in) //first this, its easier
{
    std::string myString;
    std::ofstream errorLogger("../errors.txt");
    auto currTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currTime);
    
    errorLogger  << std::ctime(&time) << "Errors history\n";
    if(in.is_open()){
        while (in.good())
        {
            std::getline (in, myString);
            std::cout << "All string: " << myString << std::endl;
            //<MAP-INC "1">1 2 3</MAP-INC>
            Tag t;
            Validation valid;
            //tag.parameter = "1"
            std::string parameter;
            if (hasParameter(myString))
            {
                parameter = extractParam(myString, "\"", '"');
                unsigned pos = myString.find(parameter);
                myString = myString.erase(pos, parameter.length());
                myString.erase(std::remove(myString.begin(), myString.end(), '"'), myString.end());

                if (valid.validateParameter(parameter)) {
                    t.setParameter(parameter);
                } else {
                    auto currTime = std::chrono::system_clock::now();
                    time = std::chrono::system_clock::to_time_t(currTime);
                    errorLogger  << std::ctime(&time) << "Invalid parameter!\n" << parameter << "\n";
                }
            }


            //tag.opentag = <MAP-INC>
            std::string openTag = extractParam(myString, "<", '>');
            openTag.erase(std::remove(openTag.begin(), openTag.end(), ' '), openTag.end());
            if(valid.validateOpenTag(openTag)){
                t.setOpenTag(openTag);
            } else {
                auto currTime = std::chrono::system_clock::now();
                time = std::chrono::system_clock::to_time_t(currTime);
                errorLogger << std::ctime(&time) << "Invalid open tag!\n";
            }
            std::cout << "Open tag: " << openTag << std::endl;

            //tag.closeTag = </MAP-INC>
            std::string closeTag = extractParam(myString, "</", '>');
            closeTag.erase(std::remove(closeTag.begin(), closeTag.end(), '/'), closeTag.end());
            if(valid.validateCloseTag(closeTag, openTag)){
                t.setCloseTag(closeTag);
            } else {
                auto currTime = std::chrono::system_clock::now();
                time = std::chrono::system_clock::to_time_t(currTime);
                errorLogger << std::ctime(&time) << "Invalid close tag!\n";
            }
            std::cout << "Close tag: " << closeTag<< std::endl;


            //tag.data = "1 2 3"
            std::string data = extractParam(myString, ">", '<');
            t.setData(data);
            std::cout << "Data: " << data << std::endl;

            // in >> myString;
        }
        
    }
    in.close();
}

//НЯМА КАК ДА РАБОТИ!!!
void Parser::writeIntoFile(const char* _fileName, std::ofstream& out){
    // std::cout << "Maria e MNOGO PROSTA";
    Tag t;
    Evaluator e;
    e.evaluate_expression(t);
    out.open(_fileName);
    if(!out){
        std::cout << "Maria e MNOGO PROSTA  !error!";
    }
    out << "mimi";
    out << t.getData();

}



int main(){
    Parser p;

    std::ifstream in("example_input.txt");
    p.parseTagFromFile(in);

    // std::ofstream out;
    // p.writeIntoFile("example_output.txt", out);

    return 0;
}