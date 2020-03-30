#ifndef _SSTRING_HH
#define _SSTRING_HH

class String {
    char* str;
    size_t size;
    size_t capacity;
    public:
    String ();
    String (const size_t& _capacity);
    String (const String& other);
    String& operator = (const String& other);
    ~String ();
    String (const char* array);
    void push (char elem);
    size_t _size () const ;
    size_t _capacity const ();
    bool empty () const ;
    char& at (const size_t& pos);
    char& front ();
    char& back ();
    void append (const String& appStr);
    char* c_char ();
    void shrink_to_fit ();
    void resize (const size_t n);
    void resize (const size_t& n, char character);
    char& operator [] (const size_t& pos);
    operator bool () const ;
    String& operator += (const String& otherString);
    String operator + (const String& otherString) const ;
    friend std::ostream& operator << (std::ostream& out, const String& s);
    friend std::istream& operator >> (std::istream& in, String& s);
};

#endif
