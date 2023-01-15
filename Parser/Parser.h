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
        inline std::string extractParam(const std::string expr, const std::string startElem, const char end);
        inline bool hasParameter(const std::string expr);

    public:
        inline std::vector<Tag> parseTagFromFile(const char* file);
        inline void writeIntoFile(const char* _fileName, const LList<double> list);
};