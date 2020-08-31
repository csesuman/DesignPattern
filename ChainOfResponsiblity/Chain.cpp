#include<bits/stdc++.h>

using namespace std;

class Age {
private:
    int age ;
public:
    Age(int age) {
        assert(age>=0);
        this->age = age;
    }
    int getAge() {
        return age;
    }
};

class Member {

private:
    Member *member;

public:
    Member(Member *member) {
        this->member = member ;
    }

    virtual void nextCategory(Age *age) {
        if(this->member != NULL) {
            this->member->nextCategory(age);
        }
        else {
            puts("You are Instering Out of range Data");
        }
    }
};

class Child : public Member{

public:
    Child(Member *member):Member(member) {

    }

    void nextCategory(Age *age) override {

        if( age->getAge() < 13 ) {
            printf("Child Added : Age %d\n",age->getAge());
        }
        else{
            Member::nextCategory(age);
        }
    }
};

class Teenage : public Member{

public:
    Teenage(Member *member):Member(member) {

    }

    void nextCategory(Age *age) {

        if( age->getAge() < 20 ) {
            printf("Teenage Added : Age %d\n",age->getAge());
        }
        else{
            Member::nextCategory(age);
        }
    }
};

class Young : public Member{

public:
    Young(Member *member):Member(member) {

    }

    void nextCategory(Age *age) {

        if( age->getAge() < 50 ) {
            printf("Young Added : Age %d\n",age->getAge());
        }
        else{
            Member::nextCategory(age);
        }
    }
};

class Old : public Member{

public:
    Old(Member *member):Member(member) {

    }

    void nextCategory(Age *age) {

        if( age->getAge() < 80 ) {
            printf("Old Added : Age %d\n",age->getAge());
        }
        else{
            Member::nextCategory(age);
        }
    }
};

class Chain {
private:
    Member *chain;
    void buildChain() {
      chain = new Child(new Teenage(new Young(new Old(NULL))));
//        chain = new Child( new Teenage( new You) );
    }

public:
    Chain() {
        buildChain();
    }
    void process(Age *age) {
        chain->nextCategory(age);
    }
};

int main(){

    Chain *chain = new Chain();

    chain->process( new Age(15) );
    chain->process( new Age(8) );
    chain->process( new Age(60) );
    chain->process( new Age(20) );
    chain->process( new Age(60) );
    chain->process( new Age(5) );
    chain->process( new Age(500) );

    return 0;
}
