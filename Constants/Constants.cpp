#include <string>
class Constants{
    public:
    static const std::string invalidDataError;
    static const std::string noDataError;
    static const std::string invalidParamError;
    static const std::string mushHaveParamError;
    static const std::string mushHaveNoParamError;
    static const std::string invalidOpenTagError;
    static const std::string invalidCloseTagError;
    static const std::string errorLoggingFilePath;
};

const std::string Constants::invalidDataError = "Invalid data!\n";
const std::string Constants::noDataError = "No data!\n";
const std::string Constants::invalidParamError = "Invalid parameter!\n";
const std::string Constants::mushHaveParamError = "This operation must have parameter!\n";
const std::string Constants::mushHaveNoParamError = "This operation must have no parameter!\n";
const std::string Constants::invalidOpenTagError = "Invalid open tag!\n";
const std::string Constants::invalidCloseTagError = "Invalid close tag!\n";
const std::string Constants::errorLoggingFilePath = "errors.txt";
