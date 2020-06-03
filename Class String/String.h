#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
    char* _string;
    int _length;
public:
    String();
    String(const char*);
    String(const String& str);

    ~String();

    int length() const;
    char at(int) const;
    bool empty() const;
    int size() const;
    void clear();
    void push_back(char c);
    void append(const String& str);
    int compare(const String& str);

    char& operator[](int);
    String operator+(const String& str);
    String operator+(char);

};

std::ostream& operator <<(std::ostream&, const String&);



#endif // STRING_H
