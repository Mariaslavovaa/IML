#include "Tag.h"

std::string Tag::getOpenTag() const {
    return openTag;
}

std::string Tag::getParameter() const {
    return parameter;
}

std::string Tag::getCloseTag() const {
    return closeTag;
}

std::string Tag::getData() const {
    return data;
}

void Tag::setOpenTag(std::string openTag){
    this->openTag = openTag;
}

void Tag::setParameter(std::string parameter){
    this->parameter = parameter;
}

void Tag::setCloseTag(std::string closeTag){
    this->closeTag = closeTag;
}

void Tag::setData(std::string data){
    this->data = data;
}