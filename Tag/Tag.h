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
    //get open tag
    inline std::string getOpenTag() const;
    //get parameter
    inline std::string getParameter() const;
    //get close tag
    inline std::string getCloseTag() const;
    //get data
    inline std::string getData() const;
    
    //set open tag
    inline void setOpenTag(const std::string openTag);
    //set parameter
    inline void setParameter(const std::string parameter);
    //set close tag
    inline void setCloseTag(const std::string closeTag);
    //set data
    inline void setData(const std::string data);
};