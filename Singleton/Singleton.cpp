#include<bits/stdc++.h>

using namespace std;

class Singleton {
 private:
  Singleton() { // no external object can be initialized using private constructor
    cout<<"Singleton object is Initialing"<<endl;
  }
  ~Singleton() { // will only be called after finishing the program's life time
    cout<<"Singleton object is Destructing"<<endl;
  }

 public:
  static Singleton& Instance() { // will return the reference of the object
    // thread-safe in C++11.
    static Singleton myInstance; // created only once
    return myInstance;
  }

  // delete copy and move constructors and assign operators
  Singleton(Singleton const&) = delete;             // Copy construct
  Singleton(Singleton&&) = delete;                  // Move construct
  Singleton& operator=(Singleton const&) = delete;  // Copy assign
  Singleton& operator=(Singleton &&) = delete;      // Move assign

  // Add more public methods here
   void display(){
        cout<<"This is display Method"<<endl;
   }
};

int main(){

    Singleton *ob = &Singleton::Instance();
    ob->display();

    return 0;
}
