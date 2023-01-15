#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../LList/LList.h"
#include "../Tag/Tag.h"
#include <vector>
#pragma once


class Parser{
    private:
        //get the parameters from input tags
        inline std::string extractParam(const std::string expr, const std::string startElem, const char endElem);
        //checks if there is a parameter
        inline bool hasParameter(const std::string expr);
        //open file and write there errors
        inline void logError(std::string errorMsg);

    public:
        //Construct the vector of tags from the input file
        //fileName - name of the input file
        //returns - vector of parsed tags
        inline std::vector<Tag> parseTagFromFile(const char* fileName);
        //Write into output file
        //fileName - name of the output file
        //list - the data we write to the file
        inline void writeIntoFile(const char* fileName, const LList<double> list);
};