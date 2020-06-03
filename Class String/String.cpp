#include "String.h"
#include <string.h>

String::String()
{
    _string = new char[1];
    *_string = '\0';
    _length = 1;
}

String::String(const char* str)
{
    _length = strlen(str) + 1;
    _string = new char[_length];
    strcpy(_string, str);
}

String::String(const String& str)
{
    _string = new char[str._length];
    strcpy(_string, str._string);
    _length = str._length;
}

String::~String()
{
    if(_string)
        delete[] _string;
}

int String::length() const
{
    return (_length > 0)?_length - 1: 0;
}

char String::at(int index) const
{
    return _string[index];
}

bool String::empty() const
{
    return _length == 1;
}

int String::size() const
{
    return length();
}

void String::clear()
{
    if(_string)
        delete [] _string;
    _string = new char[1];
    *_string = '\0';
    _length = 1;
}

void String::push_back(char c)
{
    char* temp = new char[_length + 1];
    strcpy(temp, _string);
    temp[_length - 1] = c;
    temp[_length] = '\0';
    if(_string) delete [] _string;
    _string = temp;
    _length++;
}

void String::append(const String &str)
{
    char* temp = new char[_length + str.length()];
    strcpy(temp, _string);
    strcpy(temp + _length - 1, str._string);
    temp[_length + str.length() - 1] = '\0';
    if(_string) delete [] _string;
    _string = temp;
    _length = length() + str.length() + 1;
}

int String::compare(const String &str)
{
    return strcmp(_string, str._string);
}


char &String::operator[](int index)
{
    return _string[index];
}

String String::operator+(const String &str)
{
    String temp = *this;
    temp.append(str);
    return temp;

}

String String::operator+(char c)
{
    String temp = *this;
    temp.push_back(c);
    return temp;
}



std::ostream &operator <<(std::ostream &stream, const String &str)
{
    for(int i = 0; i < str.length(); ++i)
        stream << str.at(i);
    return stream;
}
