#include<iostream>
#include<string.h>

using namespace std;

class Country {
public:
    virtual void capitalCity() = 0;
    virtual void nationalAnimal() = 0;
};

class Bangladesh : public Country {
public:
    void capitalCity() {
        cout<<"Dhaka"<<endl;
    }
    void nationalAnimal() {
        cout<<"Royal Bengal Tiger"<<endl;
    }
};

class Japan : public Country {
public:
    void capitalCity() {
        cout<<"Tokyo"<<endl;
    }
    void nationalAnimal() {
        cout<<"Boar Black-headed gull"<<endl;
    }
};

class USA : public Country {
public:
    void capitalCity() {
        cout<<"Washington, D.C."<<endl;
    }
    void nationalAnimal() {
        cout<<"The American Bison"<<endl;
    }
};

// Factory Method - Abstract Creator Class
class CountryFactory {
public:
    virtual Country *createCountry(char *) = 0;
};

//class CountryFactory {
//public:
//    virtual Country *createCountry(char *type) {
//        cout<<"Create Country is Under Construction ;)";
//        return nullptr;
//    }
//};

// Factory Method - Concrete Creator Class
class Factory : public CountryFactory {
public:
    Country *createCountry(char *type) {
        if( 0 == strcmp(type,"Bangladesh") ) {
            return new Bangladesh();
        } else if( 0 == strcmp(type,"USA") ) {
            return new USA();
        } else if(  0 == strcmp(type,"Japan") ) {
            return new Japan();
        }
        return nullptr;
    }
};
