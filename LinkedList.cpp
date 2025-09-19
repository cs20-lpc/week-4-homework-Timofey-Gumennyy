#include "LinkedList.hpp"
#include <iostream>
using namespace std;
// Ensure Student is available for explicit template instantiation below
#include "Student.hpp"

template <typename T>
LinkedList<T>::LinkedList()
    : head(nullptr) {
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // reset current list first
    head = nullptr;
    this->length = 0;

    if (copyObj.head == nullptr) return;

    // create the head node
    head = new Node(copyObj.head->value);
    Node* src = copyObj.head->next;
    Node* dst = head;
    this->length = 1;

    while (src != nullptr) {
        dst->next = new Node(src->value);
        dst = dst->next;
        src = src->next;
        this->length++;
    }

}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }

    if (position == 0) {
        head = new Node(elem, head);
    } else {
        Node* prev = head;
        for (int i = 0; i < position - 1; ++i) prev = prev->next;
        prev->next = new Node(elem, prev->next);
    }

    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }

    if (position == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    } else {
        Node* prev = head;
        for (int i = 0; i < position - 1; ++i) prev = prev->next;
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }

    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

// Explicit template instantiation for the Student type so the linker
// can find the template definitions when LinkedList<Student> is used
template class LinkedList<Student>;
