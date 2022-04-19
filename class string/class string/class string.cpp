#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
long Count_size(const char* data){
    long size = 0;
    const char* start = data;
    while (*start++)
        size++;
    return size;
}long Count_size(int data) {
    long size = 0;
    while (data > 0) {
        size++;
        data /= 10;
    }
    return size;
}
char* allocate(long size) {
    char* data = new char[size + 1];
    data[size] = '\0';
    return data;
}
char* Copy(const char* p) {
    long size = Count_size(p);
    char* data_tail = allocate(size);
    char* data = data_tail;
    while (*data_tail++ = *p++);
    data_tail--;
    return data;
}
char* Copy(long p) {
    long size = Count_size(p);
    char* data = allocate(size);
    while (p > 0) {
        *data++ = p % 10;
        p /= 10;
    }
    return data;
}
class Sstring {
protected:
    char* data;
    char* data_tail;
    long size;
public:
    Sstring() {
        size = 0;
        data = new char[1];
        data[0] = '\0';
        data_tail = data;
    };
    Sstring(const char* p) {
        long size = Count_size(p);
        char*res = Copy(p);
        data_tail = res + size;
        data = res;
    };
    Sstring(long p) {
        long size = Count_size(p);
        char* res = Copy(p);
        data_tail = res + size;
        data = res;
    };
    Sstring(const Sstring& a) {
        data = a.data;
        data_tail = a.data_tail;
        size = a.size;
    };
    Sstring& operator = (const Sstring& a) {
        if (this->data != a.data)
        {
            this->data = a.data;
            this->data_tail = a.data_tail;
            this->size = a.size;
        };
        return  *this;
    };
    Sstring& operator = (const char* p) {
        long size = Count_size(p);
        char* res = Copy(p);
        data_tail = res + size;
        data = res;
        return *this;
    };
    friend ostream& operator <<(ostream& os, const Sstring& st);
    Sstring& operator +(const Sstring& st) {
        char* tmp = new char[st.size + size];
        char* start1 = data;
        char* start2 = st.data;
        while (*tmp++ = *start1++);
        while (*tmp++ = *start2++);
        Sstring new_Str(tmp);
        return new_Str;
    };
    Sstring& operator +(char* st) {
        long st_size = Count_size(st);
        char* tmp = new char[st_size  + size];
        char* start1 = data;
        char* start2 = st;
        while (*tmp++ = *start1++);
        while (*tmp++ = *start2++);
        Sstring new_Str(tmp);
        return new_Str;
    };
    friend istream& operator >>(istream& is, Sstring& st);
    friend char* Copy(const char* p);
    friend char* allocate(long size);
    friend bool operator <(Sstring& a,Sstring& b);
};
ostream& operator <<(ostream& os, const Sstring& st) {
    os << st.data;
    return os;
};
istream& operator >>(istream& is, Sstring& st) {
    istream::sentry s(is);
    char* m = allocate(100);
    int pointer = 0;
    if (s) while (is.good()) {
        if (pointer == 100){
            string string1 = string(st.data);
            string string2 = string(m);
            string answ = string1 + string2;
            st = answ.c_str();
            m = allocate(100);
            pointer = 0;
        }
        char c = is.get();
        m[pointer++] = c;
        if (isspace(c))break;
    }
    m[pointer] = '\0';
    char* n = Copy(m);
    st.data = n;
    delete [] m;
    return is;
}
bool operator <(Sstring& a, Sstring& b) {
    return a.size < b.size;
};
bool operator >(Sstring & a, Sstring & b) {
        return not operator<(a, b);
};
class Snumber : Sstring {
    Snumber() {
        size = 0;
        data = new char[1];
        data[0] = '\0';
        data_tail = data;
    };
    Snumber(const char* p) {
        long size = Count_size(p);
        char* res = Copy(p);
        data_tail = res + size;
        data = res;
    };
    friend Snumber& sum(Snumber& a, Snumber& b);
    Snumber& operator = (const Snumber& a) {
        if (this->data != a.data)
        {
            this->data = a.data;
            this->data_tail = a.data_tail;
            this->size = a.size;
        };
        return  *this;
    };
    Snumber& operator +(char* st) {
        long st_size = Count_size(st);
        char* tmp = new char[st_size + size];
        char* start1 = data;
        char* start2 = st;
        while (*tmp++ = *start1++);
        while (*tmp++ = *start2++);
        Snumber new_Str(tmp);
        return new_Str;
    };
};
Snumber& sum(Snumber& a, Snumber& b) {
    Snumber answ;
    int temp = 0;
    if (a < b) {
        char* temp = allocate(b.size+1);
        char* start = a.data;
        while (*start++ = *temp++);
        while (*temp++ = '0');

    }
    else{
        char* temp = allocate(a.size+1);
        char* start = b.data;
        while (start++ or temp++)
            *temp = *start;
        while (temp++)
            *temp = '0';

    }
    while (*a.data++ && *b.data++) {
        long sum_res = atoi(a.data) + atoi(b.data) + temp;
        temp = sum_res / 10;
        answ = answ + (sum_res+'0');
    }
}
int main()
{
    Sstring a("abc");
    Sstring b(a);
    b = "aba";
    a = b;
    Sstring c;
    cin >> c;
    //c = (a + b);
    cout << c << endl;
    cout << a << endl;
}