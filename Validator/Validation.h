#include "..\Tag\Tag.h" ///НЕ ГО ИЗПОЛЗВАМЕ???? ЩЕ НИ ТРЯБВА ЛИ??
//validator
class Validation{

    private:
    //in the moment <<>> is valid, u should take care of this
    bool rightBrackets(const std::string& expression);
    bool checkOperation(std::string operation);
    std::string extractOpenTagOperation(std::string openTag);
    std::string extractCloseTagOperation(std::string closeTag);
    
    public:

    bool validateOpenTag(std::string openTag);
    bool validateCloseTag(std::string closeTag, std::string openTag);
    bool validateParameter(std::string parameter);
    //bool validate data???

};