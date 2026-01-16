#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element* newElement = new Element(entry);
    newElement->next = head;
    head = newElement;
    current_size++;
}

int List::pop() {
    int data = head->data;
    head = head->next;
    //Element* old_head = head;
    //delete old_head;
    current_size--;
    return data;
}

void List::reverse() {
    Element* prev = nullptr;
    Element* current = head;
    Element* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;  // Update head to the new first element
}

List::~List() {
    Element* current = head;
    while (current != nullptr) {
        Element* next = current->next;
        delete current;
        current = next;
    }
}

}  // namespace simple_linked_list
