#include "Parser/Parser.cpp"
#include "Tag/Tag.cpp"
#include "Evaluator/Evaluator.cpp"

class Processor{
    private:
        void prepareOutputFile(const char* fileName){
            std::ofstream out;
            out.open(fileName, std::ios::trunc);
            out << "----------RESULT-----------\n" ;
            out.close();
        }

         void prepareErrorFile(const char* fileName){
            std::ofstream out;
            out.open(fileName, std::ios::trunc);
            out << "----------Errors-----------\n" ;
            out.close();
        }
    public:
        void process(const char* inputFile, const char* outputFile){
            prepareOutputFile(outputFile);
            prepareErrorFile("errors.txt");
            Parser p;
            std::vector<Tag> tagsParsed = p.parseTagFromFile(inputFile);
            Evaluator e;
            for (Tag t : tagsParsed)
            {
                LList<double> list = e.evaluate_expression(t);
                p.writeIntoFile(outputFile, list);
            }
        }
};

// int main(){
//     Processor p;
//     p.process("example_input.txt", "result.txt");
// }