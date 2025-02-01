#include <iostream>
#include <cstring>  

using namespace std;

class String {
private:
    char *str;  

public:
    
    String(const char *s = "") {
        str = new char[strlen(s) + 1];  
        strcpy(str, s);  
    }

    
    ~String() {
        delete[] str;  
    }


    String operator+(const String &obj) {

        char *temp = new char[strlen(str) + strlen(obj.str) + 1];
        strcpy(temp, str);  
        strcat(temp, obj.str);  

        String result(temp);  
        delete[] temp;  
        return result;  
    }


    String& operator=(const String &obj) {
        if (this != &obj) {  
            delete[] str;  
            str = new char[strlen(obj.str) + 1];  
            strcpy(str, obj.str);  
        }
        return *this;  
    }


    bool operator==(const String &obj) {
        return strcmp(str, obj.str) == 0;  
    }


    friend ostream& operator<<(ostream &os, const String &obj) {
        os << obj.str;  
        return os;
    }


    friend istream& operator>>(istream &is, String &obj) {
        char buffer[100];
        is >> buffer;  
        obj = String(buffer);  
        return is;
    }
};

int main() {

    String s1("Hello");
    String s2("World");
    String s3;


    cout << "Enter a string: ";
    cin >> s3;


    cout << "You entered: " << s3 << endl;


    String s4 = s1 + s2;
    cout << "Concatenated string: " << s4 << endl;


    if (s1 == s2) {
        cout << "s1 and s2 are equal." << endl;
    } else {
        cout << "s1 and s2 are not equal." << endl;
    }

    return 0;
}
