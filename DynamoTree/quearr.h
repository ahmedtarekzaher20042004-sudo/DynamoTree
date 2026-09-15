#ifndef QUEARR_H
#define QUEARR_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template<class T>
class quearr {
private:
    void underline()
    {
        for (int i = 0; i < 100; ++i) {
            cout << '-';
        }
        cout << "\n";
    }
    int head;
    int tail;
    int length;
    T* arr;
    int max_size;
public:
    
    quearr(int size);
    quearr();

    bool isempty();

    bool isfull();

    void enque(const T& element);

    void deque();

    T getheadque();

    T gettailque();

    int searchque(const T &element);

    void printque();

    bool operator==(const quearr<T>& other);

    bool operator<(const quearr<T>& other);
                                    
    bool operator>(const quearr<T>& other);

    friend ostream& operator<<(ostream& os, quearr<T>& queue)
    {
        queue.printque();
        return os;
    }
    friend istream& operator>>(istream& is, quearr<T>& queue)
    {
        cout << "Enter Number Of Operation : ";
        int n;
        cin >> n;
        T element;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter operation num [" << i+1<< "] : ";
            cin >> element;
            queue.enque(element);
        }
        return is;
    };


    quearr<T>& operator=(const quearr<T>& other);

    ~quearr();
};
template<class T>
quearr<T>::quearr(int size)
{
    if (size < 0)
        max_size = 100;
    else
        max_size = size;
    head = 0;
    tail = max_size - 1;
    length = 0;
    arr = new T[max_size];
}
template<class T>
quearr<T>::quearr() {
    max_size = 100;
    head = 0;
    tail = max_size - 1;
    length = 0;
    arr = new T[max_size];
}

template<class T>
bool quearr<T>::isempty() {
    return length == 0;
}

template<class T>
bool quearr<T>::isfull() {
    return length == max_size;
}

template<class T>
void quearr<T>::enque(const T& element) {
    if (isfull())
        cout << "full....... can not to add " << endl;
    else {
        tail = (tail + 1) % max_size;
        arr[tail] = element;
        length++;
    }
}

template<class T>
void quearr<T>::deque() {
    if (isempty())
        cout << "empty.....can not remove" << endl;
    else {
        head = (head + 1) % max_size;
        length--;
    }
}

template<class T>
T quearr<T>::getheadque() {
    assert(!isempty());
    return arr[head];
}

template<class T>
T quearr<T>::gettailque() {
    assert(!isempty());
    return arr[tail];
}

template<class T>
int quearr<T>::searchque(const T &element) {
    int pos = -1;
    if (!isempty()) {
        for (int i = head; i != tail; i = (i + 1) % max_size) {
            if (arr[i] == element) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            if (arr[tail] == element)
                pos = tail;
        }
    }
    else
        cout << "queue is empty " << endl;

    return pos;
}

template<class T>
void quearr<T>::printque() {
    int i = head - 1;
    underline();
    while (i != tail) {
        i = (i + 1) % max_size;
        cout << arr[i] << "\n";
    }
    underline();
}

template<class T>
bool quearr<T>::operator==(const quearr<T>& other)
{
    if (length != other.length) {
        return false;
    }

    int i = head;
    int j = other.head;
    for (int count = 0; count < length; ++count) {
        if (arr[i] != other.arr[j]) {
            return false;
        }

        i = (i + 1) % max_size;
        j = (j + 1) % other.max_size;
    }

    return true;
}

template<class T>
bool quearr<T>::operator<(const quearr<T>& other)  {
    if (length != other.length) {
        return length < other.length;
    }

    int i = head;
    int j = other.head;

    for (int count = 0; count < length; ++count) {
        if (arr[i] != other.arr[j]) {
            return arr[i] < other.arr[j];
        }

        i = (i + 1) % max_size;
        j = (j + 1) % other.max_size;
    }

    return false;
}


template<class T>
bool quearr<T>::operator>(const quearr<T>& other)
{

    if (length != other.length) {
        return length > other.length;
    }

    int i = head;
    int j = other.head;

    for (int count = 0; count < length; ++count) {
        if (arr[i] != other.arr[j]) {
            return arr[i] > other.arr[j];
        }

        i = (i + 1) % max_size;
        j = (j + 1) % other.max_size;
    }

    return false;
}



template<class T>
quearr<T>& quearr<T>::operator=(const quearr<T>& other) {
    if (this == &other) return *this;

    delete[] arr;

    max_size = other.max_size;
    length = other.length;
    head = other.head;
    tail = other.tail;

    arr = new T[max_size];
    for (int i = 0; i < max_size; ++i) arr[i] = other.arr[i];

    return *this;
}
template<class T>
quearr<T>::~quearr() {
    delete[] arr;
}
#endif