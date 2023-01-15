#include <string>
class Validator{

    private:
    //in the moment <<>> is valid, u should take care of this
    inline bool rightBrackets(const std::string& expression);
    inline bool checkOperation(const std::string& operation);
    inline std::string extractOpenTagOperation(std::string& openTag);
    inline std::string extractCloseTagOperation(std::string& closeTag);

    
    public:
    inline bool validateOpenTag(const std::string& openTag);
    inline bool validateCloseTag(const std::string& closeTag, const std::string& openTag);
    inline bool validateParameter(const std::string& parameter);
    inline bool validateData(const std::string& data);

    inline bool operRequiresParam(const std::string& operation);
};