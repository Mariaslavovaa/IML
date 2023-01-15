#include <string>
#pragma once

class Tag{

    private:
    std::string openTag;
    std::string parameter;
    std::string closeTag;
    std::string data;

    public:
    Tag() = default;
    inline std::string getOpenTag() const;
    inline std::string getParameter() const;
    inline std::string getCloseTag() const;
    inline std::string getData() const;
    
    inline void setOpenTag(const std::string openTag);
    inline void setParameter(const std::string parameter);
    inline void setCloseTag(const std::string closeTag);
    inline void setData(const std::string data);
};