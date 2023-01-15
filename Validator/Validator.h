#include <string>
class Validator{

    private:
    //checks the operation is right
    inline bool checkOperation(const std::string& operation);
    //extracts only open tag
    inline std::string extractOpenTagOperation(std::string& openTag);
    //extracts only close tag
    inline std::string extractCloseTagOperation(std::string& closeTag);

    public:
    //These functions validate all parts of a tag
    inline bool validateOpenTag(const std::string& openTag);
    inline bool validateCloseTag(const std::string& closeTag, const std::string& openTag);
    inline bool validateParameter(const std::string& parameter);
    inline bool validateData(const std::string& data);

    //checks if the operator requires a parameter
    inline bool operRequiresParam(const std::string& operation);
};