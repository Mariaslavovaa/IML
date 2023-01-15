#include <iostream>
#pragma once

template<typename T>
class LList{

    private:
    struct Node{
        T data;
        Node* next;

        Node(T data, Node* next){
            this->data = data;
            this->next = next;
        }
    };
    
    Node* first;

    void copy(const LList<T>& other);
    void erase();
    Node* middle_point(LList<T> first);
    Node* merge(Node* a, Node* b);

    public:

    inline LList();
    inline LList(const LList<T>& other);
    inline LList(Node* first);
    inline LList<T>& operator=(const LList<T>& other);
    inline ~LList();

    inline Node* getFirst() const;

    inline void push_back(const T& elem);
    inline void push_front(const T& data);

    inline void map_increment(const double& number);
    inline void map_multiple(const double& number);

    inline double agg_summation();
    inline double agg_product();
    inline double agg_average();
    inline T agg_first();
    inline T agg_last();

    inline void reverse();
    //sort??? heap/merge????
    Node* merge_sort(Node* head);
    inline void srt_ord(const std::string ord);

    inline void srt_slc(int index);
    inline void remove_duplicates();

    inline void print();
    inline void printFile(std::ofstream& out);

    class Iterator
    {
        private:
        Node* current;
        
        public:
        Iterator(Node* first);
        bool operator!=(const Iterator& it);
        Iterator& operator++();
        T& operator*();       
    };

    Iterator begin();
    Iterator end();
};