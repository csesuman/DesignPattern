#include<bits/stdc++.h>

using namespace std;

class Pizza {
public:
    virtual string getDescription() = 0;
    virtual int getCost() = 0;
    virtual ~Pizza(){};
};

class PlainPizza : public Pizza {

public:
    string getDescription() override {
        return "Plain Pizza";
    }

    int getCost() override {
        return 7;
    }
};

class PizzaDecorator: public Pizza{
protected:
    Pizza* pizza;
public:
    PizzaDecorator(Pizza* pizza){
        this->pizza = pizza;
    }

    string getDescription() override {
        return pizza->getDescription();
    }

    int getCost() override {
        return pizza->getCost();
    }

    ~PizzaDecorator() {

    }
};

class Cheese: public PizzaDecorator {

public:
    Cheese(Pizza* pizza): PizzaDecorator(pizza) {

    }

    string getDescription() override {
        return pizza->getDescription() + ", cheese";
    }

    int getCost() override {
        return pizza->getCost() +  6;
    }
};


class Pepperoni: public PizzaDecorator {

public:
    Pepperoni(Pizza* pizza): PizzaDecorator(pizza) {

    }

    string getDescription() override {
        return pizza->getDescription() + ", Pepperoni";
    }

    int getCost() override {
        return pizza->getCost() +  9;
    }
};

int main() {
    Pizza* pizza = new PlainPizza();
    pizza = new Cheese(pizza);
    pizza = new Pepperoni(pizza);

    cout<<"Description >> " << pizza->getDescription() << endl;

    delete pizza;

    return 0;
}
