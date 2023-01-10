#include <iostream>
#include <vector>
#include <fstream>


class Parser{
    public:
        void parseTagFromFile(const char* _fileName, std::ifstream& in); //first this, its easier //std::vector<Tag>
        void writeIntoFile(const char* _fileName, std::ofstream& out);
};