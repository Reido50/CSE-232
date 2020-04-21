#ifndef SELF_DESTRUCTING_H
#define SELF_DESTRUCTING_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include<utility>
using std::pair;
#include <ios>
using std::ostream; using std::istream;

class SelfDestructingMessage {
    private:
        vector<pair<string, long>> messages_;
        long number_of_allowed_views_;

    public:
        SelfDestructingMessage() = default;
        SelfDestructingMessage(const vector<string> &, long);

        // Rule of Three
        SelfDestructingMessage(SelfDestructingMessage&);
        ~SelfDestructingMessage() = default;
        SelfDestructingMessage& operator=(SelfDestructingMessage&);

        size_t size() const;
        vector<string> get_redacted() const;
        long number_of_views_remaining(size_t) const;
        void add_array_of_lines(string [], long);
        const string& operator[](size_t);
        friend ostream& operator<<(ostream&, const SelfDestructingMessage&);
        friend istream& operator>>(istream&, SelfDestructingMessage&);
};

#endif
