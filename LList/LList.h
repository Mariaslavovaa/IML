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
    inline unsigned size();

    public:

    inline LList();
    inline LList(const LList<T>& other);
    inline LList(Node* first);
    inline LList<T>& operator=(const LList<T>& other);
    inline ~LList();
    inline bool operator==(LList<T> other);

    inline Node* getFirst() const;
    inline void push_back(const T& elem);
    inline void push_front(const T& data);

    //add each number by the given number
    inline void map_increment(const double& number);
    //multiplies each number by the given number
    inline void map_multiply(const double& number);

    //returns the summ of all numbers
    inline double agg_summation();
    //returns the product of all numbers
    inline double agg_product();
    //returns average number
    inline double agg_average();
    //returns the first element
    inline T agg_first();
    //returns the last element
    inline T agg_last();

    //reverse list
    inline void reverse();
    // Node* merge_sort(Node* head);


    //sorts in ascending order (for argument "ASC") or descending order (for argument "DSC")
    // inline void split(LList<T>& list, LList<T>& list1, LList<T>& list2);
    // inline LList<T> merge(LList<T>& list1, LList<T>& list2);
    // inline void merge_Sort(LList<T>& list);
    inline void srt_ord(const std::string ord);


    //returns a subscript from the specified index onwards
    inline void srt_slc(int index);
    //Remove duplicates from the list
    inline void remove_duplicates();

    inline void print();
    //print in file
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