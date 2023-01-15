#include "Parser/Parser.cpp"
#include "Tag/Tag.cpp"
#include "Evaluator/Evaluator.cpp"
#include <iostream>

class Processor{
    private:
        //delete old entries in the file
        void prepareOutputFile(const char* fileName){
            std::ofstream out;
            out.open(fileName, std::ios::trunc);
            out << "----------RESULT-----------\n" ;
            out.close();
        }

        //handles error file
        void prepareErrorFile(const char* fileName){
            std::ofstream out;
            out.open(fileName, std::ios::trunc);
            out << "----------Errors-----------\n" ;
            out.close();
        }

    public:
        //For each tag processes the data and writes it to the file
        //inputFile - name of the input file
        //outputFile - name of the output file
        void process(const char* inputFile, const char* outputFile){
            prepareOutputFile(outputFile);
            prepareErrorFile("errors.txt");
            Parser parser;
            std::vector<Tag> tagsParsed = parser.parseTagFromFile(inputFile);
            Evaluator eval;
            for (Tag tag : tagsParsed)
            {
                LList<double> list = eval.evaluate_expression(tag);
                parser.writeIntoFile(outputFile, list);
            }
        }
};

int main(){
    Processor p;
    std::string inputFile;
    std::getline (std::cin, inputFile);

    std::string outputFile;
    std::getline (std::cin, outputFile);
    p.process(inputFile.c_str(), outputFile.c_str());
    // p.process("example_input.txt", "result.txt");
}