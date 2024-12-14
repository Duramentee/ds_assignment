#pragma once

#include <iostream>

namespace ds {

template <typename ElemType>
struct Node {
    ElemType data_;
    Node* next_;
    Node* prev_;

    explicit Node(const ElemType& val) : data_{val}, next_{nullptr}, prev_{nullptr} {
    }

    ~Node() {
        next_ = nullptr;
        prev_ = nullptr;
    }

    Node(const Node& ano_node) : data_{ano_node.data_}, next_{nullptr}, prev_{nullptr} {
    }
};

template <typename ElemType>
struct LinkedList {

struct Iterator {
    Node<ElemType>* node_;

    explicit Iterator(Node<ElemType>* node = nullptr) : node_{node} {}

    Iterator& operator++() {
        if (node_ != nullptr) {
            node_ = node_->next_;
        }
        return *this;
    }
    Iterator operator++(int) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    Iterator& operator--() {
        if (node_ != nullptr) {
            node_ = node_->prev_;
        }
        return *this;
    }
    Iterator operator--(int) {
        Iterator temp = *this;
        --(*this);
        return temp;
    }

    Iterator& operator+=(const size_t n) {
        for (size_t i = 0; i < n && node_ != nullptr; ++i) {
            node_ = node_->next_;
        }
        return *this;
    }
    Iterator& operator-=(const size_t n) {
        for (size_t i = 0; i < n && node_ != nullptr; ++i) {
            node_ = node_->prev_;
        }
        return *this;
    }

    ElemType& operator*() {
        return node_->data_;
    }
    const ElemType& operator*() const {
        return node_->data_;
    }

    ElemType* operator->() {
        return &(node_->data_);
    }
    const ElemType* operator->() const {
        return &(node_->data_);
    }

    bool operator==(const Iterator& other) const {
        return node_ == other.node_;
    }
    bool operator!=(const Iterator& other) const {
        return node_ != other.node_;
    }

};

    Node<ElemType>* head_;
    Node<ElemType>* tail_;

    LinkedList() : head_{nullptr}, tail_{nullptr} {}

    explicit LinkedList(ElemType val) : head_{new Node<ElemType>(val)}, tail_{head_} {}

    ~LinkedList() { clear(); }

    LinkedList(const LinkedList& ano_list) : head_{nullptr}, tail_{nullptr} {
        if (ano_list.head_ != nullptr) {
            head_ = new Node<ElemType>(ano_list.head_->data_);
            tail_ = head_;
            Node<ElemType>* this_current = head_;
            Node<ElemType>* ano_current = ano_list.head_->next_;

            while (ano_current != nullptr) {
                this_current->next_ = new Node<ElemType>(ano_current->data_);
                this_current->next_->prev_ = this_current;
                this_current = this_current->next_;
                tail_ = this_current;
                ano_current = ano_current->next_;
            }
        }
    }

    LinkedList& operator=(const LinkedList& ano_list) {
        if (this != &ano_list) {
            clear();

            if (ano_list.head_ != nullptr) {
                head_ = new Node<ElemType>(ano_list.head_->data_);
                tail_ = head_;
                Node<ElemType>* this_current = head_;
                Node<ElemType>* ano_current = ano_list.head_->next_;

                while (ano_current != nullptr) {
                    this_current->next_ = new Node<ElemType>(ano_current->data_);
                    this_current->next_->prev_ = this_current;
                    this_current = this_current->next_;
                    tail_ = this_current;
                    ano_current = ano_current->next_;
                }
            }
            else {
                head_ = nullptr;
                tail_ = nullptr;
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
        tail_ = nullptr;
    }

    void push_front(const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        new_node->next_ = head_;
        if (head_ != nullptr) {
            head_->prev_ = new_node;
        }
        head_ = new_node;
        if (tail_ == nullptr) {
            tail_ = new_node;
        }
    }

    void push_back(const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        if (tail_ != nullptr) {
            tail_->next_ = new_node;
            new_node->prev_ = tail_;
        }
        tail_ = new_node;
        if (head_ == nullptr) {
            head_ = new_node;
        }
    }

    Iterator insert(Iterator pos, const ElemType& val) {
        Node<ElemType>* new_node = new Node(val);
        Node<ElemType>* current = pos.node_;

        if (current == nullptr) {
            push_back(val);
            return Iterator(tail_);
        }

        new_node->next_ = current;
        new_node->prev_ = current->prev_;

        if (current->prev_ != nullptr) {
            current->prev_->next_ = new_node;
        }
        else {
            head_ = new_node;
        }

        current->prev_ = new_node;

        return Iterator(new_node);
    }

    void pop_front() {
        if (head_ == nullptr)
            return;

        Node<ElemType>* old_head = head_;
        head_ = head_->next_;

        if (head_ != nullptr) {
            head_->prev_ = nullptr;
        } else {
            tail_ = nullptr;
        }

        delete old_head;
    }

    void pop_back() {
        if (head_ == nullptr)
            return;
        if (head_->next_ == nullptr) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            return;
        }

        Node<ElemType>* current = tail_;
        tail_ = tail_->prev_;
        tail_->next_ = nullptr;

        delete current;
    }

    Iterator erase(Iterator pos) {
        Node<ElemType>* current = pos.node_;
        if (current == nullptr) {
            return end();
        }

        Node<ElemType>* next = current->next_;
        Node<ElemType>* prev = current->prev_;

        if (prev != nullptr) {
            prev->next_ = next;
        }
        else {
            head_ = next;
        }

        if (next != nullptr) {
            next->prev_ = prev;
        }
        else {
            tail_ = prev;
        }

        delete current;

        return Iterator(next);
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

    void print() const {
        Node<ElemType>* current = head_;
        while (current != nullptr) {
            std::cout << current->data_ << " ";
            current = current->next_;
        }
        std::cout << std::endl;
    }

    [[nodiscard]] bool empty()  const { return head_ == nullptr; }
    Iterator           begin()        { return Iterator(head_); }
    Iterator           end()          { return Iterator(nullptr); }
    Iterator           begin()  const { return Iterator(head_); }
    Iterator           end()    const { return Iterator(head_); }
};

}
