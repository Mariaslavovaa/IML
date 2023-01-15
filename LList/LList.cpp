#include "LList.h"
#pragma once
#include <algorithm>

template<typename T>
void LList<T>::copy(const LList<T>& other){

    if(other.first == nullptr){
        this->first = nullptr;
        return;
    }
    Node* currOther = other.first;
    this->first = new Node(currOther->data, nullptr);
    Node* curr = this->first;
    while(currOther->next != nullptr){
        currOther = currOther->next;
        curr->next = new Node(currOther->data, nullptr);
        curr = curr->next;
    }
}

template<typename T>
void LList<T>::erase(){
    while(this->first != nullptr){
        Node* curr = this->first->next;
        delete this->first;
        first = curr;
    }
}

template <typename T>
inline unsigned  LList<T>::size(){
    Node* tmp = this->first;
    unsigned counter = 0; 
    while (tmp)
    {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

template<typename T>
inline LList<T>::LList(){
    this->first = nullptr;
}

template<typename T>
inline LList<T>::LList(const LList<T>& other){
    copy(other);
}

template<typename T>
inline LList<T>::LList(Node* first){
    this->first = first;
}

template<typename T>
inline LList<T>& LList<T>::operator=(const LList<T>& other){
    if (this != &other){
        erase();
        copy(other);
    }
    return *this;
}

template<typename T>
inline LList<T>::~LList(){
    erase();
}

template <typename T>
inline bool LList<T>::operator==(LList<T> other){
    if (this->size() != other.size())
    {
        return false;
    }
    
    Node* tmp = this->first, *sndTmp = other.getFirst();
    while (tmp && sndTmp)
    {
        if(tmp->data != sndTmp->data){
            return false;
        }
        tmp = tmp->next;
        sndTmp = sndTmp->next;
    }
    return true;
}

template <typename T>
inline typename LList<T>::Node* LList<T>::getFirst() const { 
    return first;
}

template<typename T>
inline void LList<T>::push_back(const T& elem){
    Node* curr = first;
    if(first == nullptr){
        first = new Node(elem, nullptr);
        return;
    }
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = new Node(elem, nullptr);
}

template<typename T>
inline void LList<T>::push_front(const T& data){
    Node* newNode = new Node(data, first);
    first = newNode;
}

template<typename T>
inline void LList<T>::map_increment(const double& number){
    Node* temp = first;
    if(temp == nullptr){
        return;
    }
    while(temp != nullptr){
        temp->data = temp->data + number;
        temp = temp->next;
    }
}

template<typename T>
inline void LList<T>::map_multiply(const double& number){
    Node* temp = first;
    if(temp == nullptr){
        return;
    }
    while(temp != nullptr){
        temp->data = temp->data * number;
        temp = temp->next;
    }
}

template<typename T>
inline double LList<T>::agg_summation(){
    double sum = 0;
    Node* temp = first;
    if(temp == nullptr){
        return sum;
    }
    while(temp != nullptr){
        sum = sum + temp->data;
        temp = temp->next;
    }
    return sum;
}

template<typename T>
inline double LList<T>::agg_product(){
    Node* temp = first;
    double sum = 1;
    if(temp == nullptr){
        return sum;
    }
    while(temp != nullptr){
        sum = sum * temp->data;
        temp = temp->next;
    }
    return sum;
}

template<typename T>
inline double LList<T>::agg_average(){
    Node* temp = first;
    double avg = 0;
    size_t counter = 0;
    if(temp == nullptr){
        std::cout << "Error!\n" << first;
        return avg;
    }
    while(temp != nullptr){
        avg = avg + temp->data;
        counter++;
        temp = temp->next;
    }
    return (avg/counter);
}

template<typename T>
inline T LList<T>::agg_first(){
    Node* temp = first;
    if(temp == nullptr){
        return NULL; 
    }
    return temp->data;
}

template<typename T>
inline T LList<T>::agg_last(){
    Node* temp = first;
    if(temp == nullptr){
        return NULL;  
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
inline void LList<T>::reverse() {  
    Node* current = first;
    if(first == nullptr){
    	return;
    }

    Node* next = nullptr; 
    Node* prev = nullptr;

    while(current){
    	next = current->next;
    	current->next = prev;
    	prev = current;
    	current = next;
    }
    first = prev;
}

/*
template <typename T>
inline void LList<T>::split(LList<T>& list, LList<T>& list1, LList<T>& list2) {
        LList<T>* first = &list1;
        LList<T>* second = &list2;
        typename LList<T>::Iterator iterator = list.begin();
        while (iterator != nullptr) {
            (*first).push_back(*iterator);
            std::swap(first, second);

            iterator.operator++();
        }
}

template <typename T>
inline LList<T> LList<T>::merge(LList<T>& list1, LList<T>& list2) {
        LList<T> sorted;
        typename LList<T>::Iterator iterator1 = list1.begin(), iterator2 = list2.begin();

        while (iterator1!=nullptr && iterator2!=nullptr) {
            if (*iterator1 <= *iterator2) {
                sorted.push_back(*iterator1);
                iterator1.operator++();
            }
            else {
                sorted.push_back(*iterator2);
                iterator2.operator++();
            }
        }

        while (iterator1 != nullptr) {
            sorted.push_back(*iterator1);
            iterator1.operator++();
        }
        while (iterator2 != nullptr) {
            sorted.push_back(*iterator2);
            iterator2.operator++();
        }
        return sorted;
}

template <typename T>
inline void LList<T>::merge_Sort(LList<T>& list) {
        if (!(list.begin() != list.end()))
            return;

        LList<T> list1, list2;
        split(list, list1, list2);

        merge_Sort(list1);
        merge_Sort(list2);

        list = merge(list1, list2);
}*/

template <typename T>
inline void LList<T>::srt_ord(const std::string ord){
    if(ord == "ASC"){
        for (Node* i = first; i; i = i->next) {
            for (Node* j = first; j != nullptr; j = j->next) {
                if (j && i->data < j->data) {
                    std::swap(i->data, j->data);
                }
            }
        }
    } else {
        for (Node* i = first; i; i = i->next) {
            for (Node* j = first; j != nullptr; j = j->next) {
                if (j && i->data >= j->data) {
                    std::swap(i->data, j->data);
                }
            }
        }
    }

}

template<typename T>
inline void LList<T>::srt_slc(int index){
    if(first == nullptr || index < 0){
        return;
    }

    while(index > 0){
        index--;
        Node* curr = first;
        first = first->next;
        delete curr;
    }
}

template<typename T>
inline void LList<T>::remove_duplicates(){  
    Node *fst, *second, *duplicate;
    fst = first;
    while (fst != nullptr && fst->next != nullptr)
    {
        second = fst;
        
        while (second->next != nullptr)
        {
            if (fst->data == second->next->data)
            {
                duplicate = second->next;
                second->next = second->next->next;
                delete duplicate;
            }
            else 
                second = second->next;
        }
        fst = fst->next;
    }
}

template<typename T>
inline void LList<T>::print(){
    if(first == nullptr){
        return;
    }

    Node* curr = first;
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}

template<typename T>
inline void LList<T>::printFile(std::ofstream& out){
    if(first == nullptr){
        return;
    }

    Node* curr = first;
    while (curr != nullptr)
    {
        out << curr->data << " ";
        curr = curr->next;
    }
}

template<typename T>
LList<T>::Iterator::Iterator(Node *start)
{
    this->current = start;
}

template<typename T>
typename LList<T>::Iterator LList<T>::begin()
{
    return typename LList<T>::Iterator(this->first);
}

template <typename T>
typename LList<T>::Iterator LList<T>::end()
{
    return typename LList<T>::Iterator(nullptr);
}

template <typename T>
bool LList<T>::Iterator::operator!= (const Iterator& other)
{
    return (current != other.current);
}

template <typename T>
T& LList<T>::Iterator::operator*()
{
    return current->data;
}

template <typename T>
typename LList<T>::Iterator& LList<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}
