#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Person 
{ 
public: 
    string x; 
protected: 
    string y; 
private: 
    string z; 

}; 

class B : public Person 
{ 
    // x is public 
    // y is protected 
    // z is not accessible from B 
}; 
  
class C : protected Person
{ 
    // x is protected 
    // y is protected 
    // z is not accessible from C 
}; 
  
class D : private Person    // 'private' is default for classes 
{ 
    // x is private 
    // y is private 
    // z is not accessible from D 
}; 

int main(){
    B osman;
    osman.x = "osman";
    string deneme = osman.x;

    cout << deneme;


    D bilici;

    bilici.z = "deneme";

    //cout << bilici.x;
}

