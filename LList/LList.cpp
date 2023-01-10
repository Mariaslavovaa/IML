#include "LList.h"
#pragma once


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

template<typename T>
LList<T>::LList(){
    this->first = nullptr;
}

template<typename T>
LList<T>::LList(const LList<T>& other){
    copy(other);
}

template<typename T>
LList<T>& LList<T>::operator=(const LList<T>& other){
    if (this != &other){
        erase();
        copy(other);
    }
    return *this;
}

template<typename T>
LList<T>::~LList(){
    erase();
}

template <typename T>
typename LList<T>::Node* LList<T>::getFirst() const { 
    return first;
}

template<typename T>
void LList<T>::push_back(const T& elem){
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
void LList<T>::push_front(const T& data){
    Node* newNode = new Node(data, first);
    first = newNode;
}

template<typename T>
inline void LList<T>::map_increment(double n){
    Node* temp = first;
    if(temp == nullptr){
        return;
    }
    while(temp != nullptr){
        temp->data = temp->data + n;
        temp = temp->next;
    }
}

template<typename T>
inline void LList<T>::map_multiple(double n){
    Node* temp = first;
    if(temp == nullptr){
        return;
    }
    while(temp != nullptr){
        temp->data = temp->data * n;
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

//sort??? heap/merge????


    //slice срязва  Ако индекса е по-голям от броя елементи?? в този случай какво се случва
template<typename T>
inline void LList<T>::srt_slc(int index){
    if(first == nullptr || index < 0){
        return;
    }

    while(index > 0){
        index--;
        Node* curr = first;
        delete curr;
        first = first->next;
    }
}

//dst // ДА ГО ОПРАВЯ АКО МОГА
template<typename T>
inline void LList<T>::remove_duplicates(){  // 1 1 2 3 4 4   => 1 2 3 4
    Node *fst, *second = first;
    if(first == nullptr){
        return;
    }

    for (Node* i = first; i->next; i = i->next)
    {
        for (Node* j = i->next; j ; j = j->next)
        {
            
            if(j->data == i->data){
                if(j->next == nullptr){
                    i->next = nullptr;
                    delete j;
                    return;
                }
                std::cout << "Vlizam!" << j->data << "\n";
                Node* to_del = j;
                i->next = j->next;
                delete to_del;
                j = i;
            }
        }
        
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


// int main(){

//     LList<double> list;
//     list.push_back(1);   
//     list.push_back(2);   
//     list.push_back(2);   
//     list.push_back(4);   
//     list.push_back(5);
//     list.push_back(5);
//     list.push_back(5);

//     // list.remove_duplicates();
//     // list.srt_slc(2);
//     list.print();

//     // std::string op = "abab";
//     // op.erase(op.find('b'), op.find('b'));
//     // std::cout << op;

//     // std::cout << list.agg_first() << "  ";
//     // list.map_multiple(2);
//     // std::cout << list.agg_last();   
//     // std::cout << list.agg_last();   
// }