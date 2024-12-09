#pragma once

#include <iostream>

namespace ds {
template <typename ElemType>
struct Node {
    ElemType data_;
    Node* next_;

    explicit Node(const ElemType& val) : data_{val}, next_{nullptr} {
    }

    ~Node() {
        next_ = nullptr;
    }

    Node(const Node& ano_node) : data_{ano_node.data_}, next_{nullptr} {
    }
};

template <typename ElemType>
struct LinkedList {
    Node<ElemType>* head_;

    LinkedList() : head_{nullptr} {
    }

    explicit LinkedList(ElemType val) : head_{new Node<ElemType>(val)} {
    }

    ~LinkedList() { clear(); }

    LinkedList(const LinkedList& ano_list) : head_{nullptr} {
        if (ano_list.head_ != nullptr) {
            head_ = ::new Node<ElemType>(ano_list.head_->data_);
            Node<ElemType>* this_current = head_;
            Node<ElemType>* ano_current = ano_list.head_->next_;

            while (ano_current != nullptr) {
                this_current->next_ = ::new Node<ElemType>(ano_current->data_);
                this_current = this_current->next_;
                ano_current = ano_current->next_;
            }
        }
    }

    LinkedList& operator=(const LinkedList& ano_list) {
        if (this != &ano_list) {
            clear();

            if (ano_list.head_ != nullptr) {
                head_ = ::new Node<ElemType>(ano_list.head_->data_);
                Node<ElemType>* this_current = head_;
                Node<ElemType>* ano_current = ano_list.head_->next_;

                while (ano_current != nullptr) {
                    this_current->next_ = ::new Node<ElemType>(ano_current->data_);
                    this_current = this_current->next_;
                    ano_current = ano_current->next_;
                }
            }
            else {
                head_ = nullptr;
            }
        }
        return *this;
    }


    void clear() {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            Node<ElemType>* next = current->next_;
            delete current;
            current = next;
        }
        head_ = nullptr;
    }

    void push_front(const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        new_node->next_ = head_;
        head_ = new_node;
    }

    void push_back(const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        Node<ElemType>* current = head_;

        if (head_ == nullptr) {
            head_ = new_node;
            return;
        }

        while (current->next_ != nullptr) {
            current = current->next_;
        }

        current->next_ = new_node;
    }

    void insert(const int& pos, const ElemType& val) {
        if (pos < 0)
            return;

        Node<ElemType>* new_node = new Node(val);

        if (pos == 0) {
            new_node->next_ = head_;
            head_ = new_node;
            return;
        }

        Node<ElemType>* current = head_;
        Node<ElemType>* prev = nullptr;
        int index = 0;

        while (current != nullptr && index < pos) {
            prev = current;
            current = current->next_;
            index++;
        }

        if (prev != nullptr) {
            prev->next_ = new_node;
            new_node->next_ = current;
        }

        if (current == nullptr && index != pos) {
            delete new_node;
        }
    }

    void pop_front() {
        if (head_ == nullptr)
            return;

        Node<ElemType>* old_head = head_;
        head_ = head_->next_;

        delete old_head;
    }

    void pop_back() {
        if (head_ == nullptr)
            return;
        if (head_->next_ == nullptr) {
            delete head_;
            head_ = nullptr;
            return;
        }

        Node<ElemType>* current = head_;
        Node<ElemType>* prev = nullptr;

        while (current->next_ != nullptr) {
            prev = current;
            current = current->next_;
        }

        delete current;
        prev->next_ = nullptr;
    }

    void erase(const int& pos) {
        if (head_ == nullptr)
            return;
        if (pos == 0) {
            pop_front();
            return;
        }

        Node<ElemType>* current = head_;
        Node<ElemType>* prev = nullptr;
        int index = 0;

        while (current != nullptr && index < pos) {
            prev = current;
            current = current->next_;
            ++index;
        }

        if (current != nullptr) {
            prev->next_ = current->next_;
            delete current;
        }
    }

    [[nodiscard]] bool find(const ElemType& val) const {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            if (current->data_ == val)
                return true;
            current = current->next_;
        }

        return false;
    }

    [[nodiscard]] bool empty() const { return head_ == nullptr; }

    void print() const {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            std::cout << current->data_ << " ";
            current = current->next_;
        }
        std::cout << std::endl;
    }
};
}
