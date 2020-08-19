#include <iostream>
#include <list>
#include <string>

using namespace std;

class IObserver { // How Try To Observer
public :
    virtual ~IObserver(){};
    virtual void Update(const string &message) = 0 ;
};

class IMath{  // Which Holds the list of Observers......
public:
    virtual ~IMath(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

class Math : public IMath {

private:
    list<IObserver *> list_observer;
    string message  ;

public:

    virtual ~Math() {
        cout << " Destructing the object of the Math " << endl ;
    }

    void Attach(IObserver *observer) override {
        list_observer.push_back( observer );
    }

    void Detach(IObserver *observer) override {
        list_observer.remove(observer);
    }

    void Notify() override {
        for( list<IObserver*>::iterator it = list_observer.begin() ; it != list_observer.end() ; it ++ ) {
            (*it)->Update(message);
        }
    }

    void CreateMessage(string message = "Empty") {
        this->message = message;
        Notify();
    }

    void getTotalNum() {
        cout<<"\nThere are "<< list_observer.size() << " observers in the list." << endl ;
    }
};

class Observer : public IObserver {
private:
    string messageFromMath;
    Math  &math;
    static int serial ;
    int number;
public:
    Observer(Math &math) : math(math) {
        this->math.Attach(this);
        cout<<"Hi I am no " << ++ Observer::serial << ".\n" ;
        this->number = Observer::serial;
    }

    virtual ~Observer() {
        cout << "Hi I was no " << this->number <<".\n";
    }

    virtual void Update(const string &messageFromMath) override {
        this->messageFromMath = messageFromMath;
        cout<<"Man " <<this->number<<" : "<<this->messageFromMath<<endl;
    }
};

class NewObserver1 : public Observer {

    using Observer::Observer;

    void Update(const string &messageFromMath) override {
        cout<<"\n I am Alien ......... ;) : " <<messageFromMath <<endl;
    }
};


class NewObserver2 : public Observer {

    using Observer::Observer;

    void Update(const string &messageFromMath) override {
        cout<<"\n I am Panda ......... ;) : " <<messageFromMath <<endl;
    }
};

class NewObserver3 : public Observer {

    using Observer::Observer;

    void Update(const string &messageFromMath) override {
        cout<<"\n I am Tiger ......... ;) : " <<messageFromMath <<endl;
    }
};

int Observer::serial = 0;

void HowToUse() {
    Math *odd = new Math();

    Observer* ob1 = new Observer(*odd);
    Observer* ob2 = new Observer(*odd);
    Observer* ob3 = new NewObserver1(*odd);

    odd -> getTotalNum();
    odd -> CreateMessage("xxxxxxxxxxxxxxxxxxx");

    Observer* ob4 = new NewObserver2(*odd);
    Observer* ob5 = new NewObserver3(*odd);

    odd -> getTotalNum();
    odd -> CreateMessage(">>>>>>>");

    odd -> Detach(ob1);
    odd -> Detach(ob2);
    odd -> Detach(ob3);

    odd -> getTotalNum();
    odd -> CreateMessage("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");

    odd -> Detach(ob4);
    odd -> Detach(ob5);

    cout<<"\n................Deleting Objects................. \n";
    delete ob1;
    delete ob2;
    delete ob3;
    delete ob4;
    delete ob5;
}

int main(){

    HowToUse();

    return 0;
}
