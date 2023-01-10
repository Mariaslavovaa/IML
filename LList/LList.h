#include <iostream>

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

    public:

    LList();
    LList(const LList<T>& other);
    LList<T>& operator=(const LList<T>& other);
    ~LList();

    Node* getFirst() const;

    void push_back(const T& elem);
    void push_front(const T& data);

    inline void map_increment(double n);
    inline void map_multiple(double n);

    inline double agg_summation();
    inline double agg_product();
    inline double agg_average();
    inline T agg_first();
    inline T agg_last();

    inline void reverse();
    //sort??? heap/merge????


    //slice срязва  Ако индекса е по-голям от броя елементи?? в този случай какво се случва
    inline void srt_slc(int index);

    //dst // ДА ГО ОПРАВЯ АКО МОГА
    inline void remove_duplicates();

    inline void print();
    inline void printFile(std::ofstream& out);
};