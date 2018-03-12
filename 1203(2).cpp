#include <iostream>
#include <cstring>
using namespace std;
 
template <class elemType>
class vector;
 
template <class elemType>
vector<elemType> operator+(const vector<elemType>& v1, const vector<elemType>& v2);
template <class elemType>
ostream & operator<<(ostream &os, const vector<elemType>&v);
 
template <class elemType>
class vector {
    friend vector<elemType> operator+ <>(const vector<elemType>& v1, const vector<elemType>& v2);
    friend ostream &operator<< <>(ostream &os, const vector<elemType>&v);
private:
    elemType *data;
    int length, maxSize;
 
    void doubleSpace();
 
public:
    vector(int size = 10) :length(0), maxSize(size) { data = new elemType[maxSize]; }
    vector(const vector<elemType>& v);
    ~vector() { delete[]data; }
    vector<elemType>& operator=(const vector<elemType>& v);
    void push(const elemType& x);
};
 
template <class elemType>
void vector<elemType>::doubleSpace() {
    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0;i < length;++i)data[i] = tmp[i];
    delete[]tmp;
}
 
template <class elemType>
vector<elemType>::vector(const vector<elemType>& v):length(v.length),maxSize(v.maxSize) {
    data = new elemType[maxSize];
    for (int i = 0;i < length;++i) data[i] = v.data[i];
}
 
template <class elemType>
vector<elemType>& vector<elemType>::operator=(const vector<elemType>& v) {
    if (this == &v)return *this;
    delete[]data;
    length = v.length;
    maxSize = v.maxSize;
    data = new elemType[maxSize];
    for (int i = 0; i < length; ++i) data[i] = v.data[i];
    return *this;
}
 
template <class elemType>
void vector<elemType>::push(const elemType& x) {
    if (length == maxSize)doubleSpace();
    data[length++] = x;
}
 
template <class elemType>
vector<elemType> operator+(const vector<elemType>&v1, const vector<elemType>& v2) {
    vector<elemType> tmp;
    tmp.length = v1.length + v2.length;
    tmp.maxSize = v1.maxSize + v2.maxSize;
    delete[]tmp.data;
    tmp.data = new elemType[tmp.maxSize];
    int i;
    for (i = 0; i < v1.length; ++i) tmp.data[i] = v1.data[i];
    for (; i < tmp.length; ++i) tmp.data[i] = v2.data[i - v1.length];
    return tmp;
}
 
template <class elemType>
ostream& operator<<(ostream &os, const vector<elemType>&v) {
    for (int i = 0; i < v.length; ++i)
        os << v.data[i] << ' ';
    os << endl;
    return os;
}
 
template <class T>
void link(int n, int m) {
    T tmp;
    vector<T> v1, v2, v;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v1.push(tmp);
    }
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        v2.push(tmp);
    }
    v = v1 + v2;
    cout << v;
}
 
int main() {

    char str[7]; cin >> str;
    int n, m; cin >> n >> m;
    if (strcmp(str, "int") == 0) link<int>(n, m);
    else if (strcmp(str, "char") == 0) link<char>(n, m);
    else if (strcmp(str, "double") == 0) link<double>(n, m);
    return 0;
}