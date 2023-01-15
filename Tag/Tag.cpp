#include "Tag.h"
#pragma once 

inline std::string Tag::getOpenTag() const {
    return openTag;
}

inline std::string Tag::getParameter() const {
    return parameter;
}

inline std::string Tag::getCloseTag() const {
    return closeTag;
}

inline std::string Tag::getData() const {
    return data;
}

inline void Tag::setOpenTag(const std::string openTag){
    this->openTag = openTag;
}

inline void Tag::setParameter(const std::string parameter){
    this->parameter = parameter;
}

inline void Tag::setCloseTag(const std::string closeTag){
    this->closeTag = closeTag;
}

inline void Tag::setData(const std::string data){
    this->data = data;
}