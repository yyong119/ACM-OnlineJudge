#include <iostream>
#include <cstring>
using namespace std;

char str[7];
int n, m;

template <class elemType>
class myVector;

template <class elemType>
myVector<elemType> operator+(const myVector<elemType>& v1, const myVector<elemType>& v2);
template <class elemType>
ostream & operator<<(ostream &os, const myVector<elemType>&v);

template <class elemType>
class myVector {
    friend myVector<elemType> operator+ <>(const myVector<elemType>& v1, const myVector<elemType>& v2);
    friend ostream &operator<< <>(ostream &os, const myVector<elemType>&v);
private:
    elemType *data;
    int length, maxSize;

    void doubleSpace() {
        elemType *tmp = data;
        maxSize *= 2;
        data = new elemType[maxSize];
        for (int i = 0; i < length; ++i)data[i] = tmp[i];
        delete [] tmp;
    }

public:
    myVector(int size = 10) : length(0), maxSize(size) {
        data = new elemType[maxSize];
    }
    myVector(const myVector<elemType>& v): length(v.length), maxSize(v.maxSize) {
        data = new elemType[maxSize];
        for (int i = 0; i < length; ++i) data[i] = v.data[i];
    }
    ~myVector() {
        delete [] data;
    }
    void push(const elemType& x) {
        if (length == maxSize) doubleSpace();
        data[length++] = x;
    }
    myVector<elemType>& operator=(const myVector<elemType>& v);
};

template <class elemType>
myVector<elemType>& myVector<elemType>::operator=(const myVector<elemType>& v) {
    if (this == &v) return *this;
    delete [] data;
    length = v.length;
    maxSize = v.maxSize;
    data = new elemType[maxSize];
    for (int i = 0; i < length; ++i)
        data[i] = v.data[i];
    return *this;
}

template <class elemType>
myVector<elemType> operator+(const myVector<elemType>&v1, const myVector<elemType>& v2) {
    myVector<elemType> tmp;
    tmp.length = v1.length + v2.length;
    tmp.maxSize = v1.maxSize + v2.maxSize;
    delete [] tmp.data;
    tmp.data = new elemType[tmp.maxSize];
    int i;
    for (i = 0; i < v1.length; ++i) tmp.data[i] = v1.data[i];
    for (; i < tmp.length; ++i) tmp.data[i] = v2.data[i - v1.length];
    return tmp;
}

template <class elemType>
ostream& operator<<(ostream &os, const myVector<elemType>&v) {
    for (int i = 0; i < v.length; ++i) os << v.data[i] << ' ';
    os << endl;
    return os;
}

template <class elemType>
void seqLink(int n, int m) {
    elemType tmp;
    myVector<elemType> v1, v2, v;
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
    ios::sync_with_stdio(false);
    cin >> str;
    cin >> n >> m;
    if (strcmp(str, "int") == 0) seqLink<int>(n, m);
    else if (strcmp(str, "char") == 0) seqLink<char>(n, m);
    else if (strcmp(str, "double") == 0) seqLink<double>(n, m);
    return 0;
}