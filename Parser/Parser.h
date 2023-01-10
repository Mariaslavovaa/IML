#include <iostream>
#include <vector>
#include <fstream>


class Parser{
    private:
    std::string extractParam(std::string expr, std::string startElem, char end);
    bool hasParameter(std::string expr);

    public:
        // void parseTagFromFile(const char* _fileName, std::ifstream& in); //first this, its easier //std::vector<Tag>
        void parseTagFromFile(std::ifstream& in);
        void writeIntoFile(const char* _fileName, std::ofstream& out);
};