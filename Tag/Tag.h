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
    std::string getOpenTag() const;
    std::string getParameter() const;
    std::string getCloseTag() const;
    std::string getData() const;
    
    void setOpenTag(std::string openTag);
    void setParameter(std::string parameter);
    void setCloseTag(std::string closeTag);
    void setData(std::string data);
};