#include <iostream>
#include <stdlib.h>
#include <string.h>

class MyString
{
public:                  
    MyString(const MyString& right);
    MyString(const char *str);
    MyString& operator=(const MyString& right);
    MyString& operator=(const char *str);
    
     MyString(){
         mData = NULL;
         mCount = 0;
     }
	~MyString() {
	    if (mData) {
	        delete[] mData;
            mCount = 0;
        }
    }
	
public:
	int GetCount() const{
	    return mCount;
    }
    
    const char * GetStr() const{  
        return mData;
    }
    
    void Print(){
        std::cout << mData << std::endl;
    }
    
private:
    char *mData;
    int mCount;
};

MyString& MyString::operator=(const char *str)
{
    std::cout << "operator = char" << std::endl;
    int srcLen = strlen(str);
    if (srcLen <= 0) {
        return *this;
    }
    
    if (NULL != mData) {
        delete[] mData;
        mData = NULL;
        mCount = 0;
    }

    mCount = srcLen;
    mData = new char[mCount + 1];
    memcpy(mData, str, mCount);
    mData[mCount] = 0;
    return *this;
}

MyString::MyString(const MyString& right)
{
    std::cout << "MyString::MyString(const MyString& right)" << std::endl;
    mCount = 0;
    mData = NULL;
    this->operator=(right);
}


MyString::MyString(const char *str)
{
    std::cout << "MyString::MyString(const char* str)" << std::endl;
    mCount = 0;
    mData = NULL;
    this->operator=(str);
}

 
MyString& MyString::operator=(const MyString& right) 
{
    std::cout << "operator=(const MyString&)" << std::endl;
    if ((&right == this) || (right.GetCount() <= 0)) {
        return *this;
    }
    
    if (NULL != mData) {
        delete[] mData;
        mData = NULL;
        mCount = 0;
    }
    
    mCount = right.GetCount();
    mData = new char[mCount +1];
    memcpy(mData, right.GetStr(), mCount);
    mData[mCount] = 0; 
    
    return *this;
}

int main() {
	const char *data = "aaaaaaa";
    
    MyString str(data);
    str.Print();
    
    MyString str2(str);
    str2.Print();

    MyString str3;
    str3 = data;

    str3.operator=(data);
}


