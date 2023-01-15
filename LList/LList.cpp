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

template<typename T>
typename LList<T>::Node* LList<T>::middle_point(LList<T> first){
    // base case
    if(first.getFirst() == nullptr || first.getFirst()->next == nullptr) {
        return first.getFirst();
    }
    // recursive case
    Node* fast = first.getFirst();
    Node* slow = first.getFirst();
 
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
 
        if(fast->next == NULL)
            break;
 
        fast = fast->next;
        slow = slow->next;
    } 
    return slow;
}

template<typename T>
typename LList<T>::Node* LList<T>::merge(Node* a, Node* b)
{
    if(a == nullptr){
        return b;
    }
    if(b == nullptr){
        return a;
    }

    Node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
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

template <typename T>
typename LList<T>::Node* LList<T>::merge_sort(Node* head)
{
    // Node* 
    head = first;
    // base case
    if(head == nullptr || head->next == nullptr)
        return head;
 
    // recursive case
    // Step 1: divide the linked list into
    // two equal linked lists
    Node *mid = middle_point(head);
    Node *a = head;
    Node *b = mid->next;
 
    mid->next = nullptr;
 
    // Step 2: recursively sort the smaller
    // linked lists
    a = merge_sort(a);
    b = merge_sort(b);
 
    // Step 3: merge the sorted linked lists
    Node *c = merge(a, b);
    
    return c;
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

//sort??? heap/merge????
template <typename T>
inline void LList<T>::srt_ord(const std::string ord){
    // Node* result = merge_sort(first);
    // for (Node* i = first; i; i = i->next)
    // {
    //     for (Node* j = first; j != nullptr; j = j->next)
    //     {
    //         if (j && i->data >= j->data)
    //         {
    //             std::swap(i->data, j->data);
    //         }
    //     }
    // }
    // std::sort(this->begin(), this->end(), [](T a, T b){
    //     return  a < b; 
    // });

}


//slice срязва  Ако индекса е по-голям от броя елементи?? в този случай какво се случва
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


// int main(){

//     LList<double> list;
//     list.push_back(1);   
//     list.push_back(8);   
//     list.push_back(2);   
//     list.push_back(4);   
//     list.push_back(5);
//     list.push_back(3);
//     list.push_back(0);
    
//     list.reverse();
    
//     std::cout << "majka ti prosta\n";

//     LList<double> list2;
//     list2.push_back(1);   
//     list2.push_back(8);   
//     list2.push_back(2);   
//     list2.push_back(4);   
//     list2.push_back(5);
//     list2.push_back(3);
//     list2.push_back(0);
//     list2.reverse();
//     std::cout << "majka ti tupa\n";

//     std::cout << "kuche na islqma" << std::endl;
//     std::cout << (list == list2) << std::endl;


//     // LList<double> merge(list.merge_sort(list.getFirst()));
//     // merge.print();

//     //list.srt_ord("ASC");
//     //list.print();

//     // list.remove_duplicates();
//     // list.srt_slc(2);


//     // std::string op = "abab";
//     // op.erase(op.find('b'), op.find('b'));
//     // std::cout << op;

//     // std::cout << list.agg_first() << "  ";
//     // list.map_multiple(2);
//     // std::cout << list.agg_last();   
//     // std::cout << list.agg_last();   
// }