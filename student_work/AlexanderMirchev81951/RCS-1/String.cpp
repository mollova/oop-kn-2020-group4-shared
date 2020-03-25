#include <iostream>
#include <cstring>
#include <cassert>
#include "String.h"

// Constructors

    // private
String::String(const char* const str, const size_t& size, const size_t& capacity):
 _capacity{capacity}, _size{size}, data{new char[capacity]} {
    assert(size < capacity);

    strcpy(data, str);
}
    // public
String::String(): String("", 0, 4) {}
String::String(const char* const str): String(str, strlen(str), strlen(str) + 1) {}
String::String(const String& str): String(str.data, str._size, str._capacity) {}
String::~String() {
    delete[] data;
}

// Methods

size_t String::size() const {
    return _size;
}
size_t String::capacity() const {
    return _capacity;
}
char& String::at(const int pos) const {
    assert(!empty() && pos >= 0 && pos < _size);
    return *(data + pos);
}
char& String::front() const {
    assert(!empty());
    return *(data);
}
char& String::back() const {
    assert(!empty());
    return *(data + _size - 1);
}
char* String::c_str() const {
    char* newString = new char[_size + 1];
    strcpy(newString, data);
    return newString;
}
bool String::empty() const {
    return _size == 0;
}

void String::push(const char character) {
    if(_size + 1 >= _capacity) {
        resize(_capacity*2);
    }
    data[_size] = character;
    data[_size + 1] = '\0';
    ++_size;
} 
void String::append(const String& str) {
    for(size_t i = 0; i < str._size; i++) {
        push(str[i]);
    }
}

void String::shrink_to_fit() {
    resize(_size + 1);
}
void String::resize(const size_t& newCapacity) {
    if(newCapacity < _size + 1) {
        return;
    }

    _capacity = newCapacity;
    char* newContainer = new char[_capacity];
    strcpy(newContainer, data);
    delete[] data;
    data = newContainer;
}
void String::resize(const size_t& newCapacity, const char filler) {
    resize(newCapacity);
    int difference = newCapacity - _size - 1;
    for (size_t i = 0; i < difference; i++)
    {
        push(filler);
    }
}

// Operators

String& String::operator =(const String& str) {
    if(this != &str) {
        delete[] data;
        data = new char[str._capacity];
        strcpy(data, str.data);
        _size = str._size;
        _capacity = str._capacity;
    }
    return (*this);    
} 
String String::operator +(const String& toAppend) const {
    String str(*this);
    str += toAppend;
    return str;
}
String& String::operator +=(const String& toAppend) {
    append(toAppend);
    return (*this);
}
const char String::operator[](const size_t& pos) const {
    return at(pos);
}
char& String::operator[](const size_t& pos) {
    return at(pos);
}

std::ostream& operator <<(std::ostream& out, const String& str) {
    out << str.data;
    return out;
}
std::istream& operator >>(std::istream& in, String& str) {
    in >> str.data;
    str._size = strlen(str.data);
    str._capacity = str._size + 1;
}

String::operator bool() const {
    return !empty();
}