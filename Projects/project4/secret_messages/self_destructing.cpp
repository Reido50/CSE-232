#include "self_destructing.h"
#include "redact.h"

#include<iostream>
using std::endl; using std::getline;
#include<iomanip>
using std::setw; using std::setfill;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;
#include<exception>
using std::out_of_range; using std::invalid_argument;
#include<limits>
using std::numeric_limits;
#include <ios>
using std::ostream; using std::istream; using std::streamsize;

/*
    Takes a vector of strings (messages) and a long (number_of_allowed_views). The messages are a list of 
    secret messages, and the number_of_allowed_views is how many times each individual message can be viewed.
*/
SelfDestructingMessage::SelfDestructingMessage(const vector<string> & m, long n){
    for(auto str: m){
        messages_.push_back(make_pair(str, n));
    }
    number_of_allowed_views_ = n;
}

/*
    Returns the number of messages (regardless of number of views remaining).
*/
size_t SelfDestructingMessage::size() const{
    return messages_.size();
}

/*
    Returns a vector of strings made up of each message in redacted form. Redact all alphabetic and digit characters.
*/
vector<string> SelfDestructingMessage::get_redacted() const{
    vector<string> redacted_messages;
    for(pair<string, long> m: messages_){
        redacted_messages.push_back(redact_alphabet_digits(m.first));
    }
    return redacted_messages;
}

/*
    Takes a single argument, the message index. It returns the number of views remaining for that specific message. 
    Each message starts with the number_of_allowed_views.
*/
long SelfDestructingMessage::number_of_views_remaining(size_t i) const{
    return messages_[i].second;
}

/*
    Returns a const reference to the message string that was indexed.
        If the index is not a legal index for a message (too large), throw a out_of_range exception.
        If the access is to a message with no remaining views, thow a invalid_argument exception.
*/
const string& SelfDestructingMessage::operator[](size_t i){
    if(i >= messages_.size()){
        throw out_of_range("Index too large.");
    }else if(messages_[i].second <= 0){
        throw invalid_argument("No views remaining.");
    }else{
        messages_[i].second--;
        return messages_[i].first;
    }
}

/*
    The class should allow the << operator. Each line of the message (in redacted form) is prefixed by the 
    number of views remaining, and should be inserted to the ostream.
*/
ostream& operator<<(ostream& out, const SelfDestructingMessage& m){
    vector<string> redacted = m.get_redacted();
    for(size_t i = 0; i < m.size(); i++){
        out << setw(2) << setfill('0') << m.number_of_views_remaining(i) << ": " << redacted[i] << endl;
    }
    return out;
}

/*
    If an instance is copied via a copy construction, it should transfer all the views remaining to the copy, and 
    zero out the original. (This is to protect from trying to get more views by making copies of the object).
*/
SelfDestructingMessage::SelfDestructingMessage(SelfDestructingMessage& m){
    messages_ = m.messages_;
    for(auto ptr = m.messages_.begin(); ptr != m.messages_.end(); ++ptr){
        ptr->second = 0;
    }
}

/*
    If an instance is assigned, it should transfer the views remaining to the left-hand-side like with the copy 
    constructor. This is also to prevent copy abuse.
*/
SelfDestructingMessage& SelfDestructingMessage::operator=(SelfDestructingMessage& m){
    messages_ = m.messages_;
    number_of_allowed_views_ = m.number_of_allowed_views_;
    for(auto ptr = m.messages_.begin(); ptr != m.messages_.end(); ++ptr){
        ptr->second = 0;
    }
    return *this;
}

/*
    The class should also implement the >> operator. It should extract a line from the istream and append it to the 
    message list. Number of views remaining starts at number_of_allowed_views.
*/
istream& operator>>(istream& in, SelfDestructingMessage& m){
    string new_message = "";
    getline(in, new_message);
    m.messages_.push_back(make_pair(new_message, m.number_of_allowed_views_));
    return in;
}

/*
    Takes two arguments: an array of strings (messages to be added) and a long (the size of the array). Each string 
    should be added to the list of messages (number of views remaining starts at number_of_allowed_views).
*/
void SelfDestructingMessage::add_array_of_lines(string ary [], long s){
    for(long i = 0; i < s; i++){
        messages_.push_back(make_pair(ary[i], number_of_allowed_views_));
    }
}