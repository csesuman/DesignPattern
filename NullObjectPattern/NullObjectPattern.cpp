#include<bits/stdc++.h>

using namespace std;

class AbstractCountry {
public:
    virtual bool isNil() = 0 ;
    virtual string getName() = 0;
};

class Country : public AbstractCountry {
private:
    string name;
public:
    Country(string name) {
        this->name = name ;
    }

    bool isNil() override {
        return false ;
    }

    string getName() override {
        return name;
    }
};

class NoCountry : public AbstractCountry {
public:

    bool isNil() override {
        return true ;
    }

    string getName() override {
        return "Country does not exist";
    }
};

class CountryFactory {

private:
    const vector<string> v = {"Japan","China","USA","UK","KOREA"};
public:

    AbstractCountry* getCountry(string name) {

        for(int i = 0 ; i < v.size() ;  i ++) {
            if( v[i] == name ) {
                return new Country(name) ;
            }

        }
        return new NoCountry();
    }
};

int main() {

    CountryFactory *ob = new CountryFactory();

    AbstractCountry *c1 = ob->getCountry("Japan");
    AbstractCountry *c2 = ob->getCountry("AUS");
    AbstractCountry *c3 = ob->getCountry("USA");
    AbstractCountry *c4 = ob->getCountry("UK");
    AbstractCountry *c5 = ob->getCountry("china");

    cout << "Country List==> "<<endl;
    cout << c1->getName() <<endl;
    cout << c2->getName() <<endl;
    cout << c3->getName() <<endl;
    cout << c4->getName() <<endl;
    cout << c5->getName() <<endl;

    return 0;
}
