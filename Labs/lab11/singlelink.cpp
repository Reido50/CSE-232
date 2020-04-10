#include "singlelink.h"

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<stdexcept>
using std::out_of_range;

SingleLink::SingleLink(){
    head_ = nullptr;
    tail_ = nullptr;
}

SingleLink::SingleLink(int dat){
    head_= new Node(dat);
}

void SingleLink::append_back(int dat){
    if(head_ == nullptr){
        head_ = new Node(dat);
    }else{
        Node *n = head_;
        while(n->next_ != nullptr){
            n = n->next_;
        }
        n->next_ = new Node(dat);
    }
}

ostream& operator<<(ostream &out, SingleLink & s){
    Node *n = s.head_;
    out << n->data_;
    while(n->next_ != nullptr){
        n = n->next_;
        out << ", " << n->data_;
    }
    return out;
}

bool SingleLink::del(int val){
    if(head_ == nullptr){
        return false;
    }else if(head_->data_ == val){
        head_->next_ = head_;
        return true;
    }else{
        Node *n = head_;
        while(n->next_ != nullptr){
            if(n->next_->data_ == val){
                n->next_ = n->next_->next_;
                return true;
            }else{
                n = n->next_;
            }
        }
        return false;
    }
}

Node& SingleLink::operator[](size_t index){
    Node *n = head_;
    for (size_t i = 0; i < index; i++){
        if(n->next_ != nullptr){
            n = n->next_;
        }else{
            throw out_of_range("Index out of range");
        }
    }
    return *n;
}

SingleLink::~SingleLink(){

}

SingleLink::SingleLink(const SingleLink & link){
    head_ = link.head_;
}

SingleLink& SingleLink::operator=(SingleLink link){
    head_ = link.head_;
    return *this;
}