#include<bits/stdc++.h>

using namespace std;

// change object at run time

class TourPlan {
public:
    virtual void plan() {
        printf("Let's go the Great Pyramid of Giza, Egypt");
    }
};

class EiffelTower : public TourPlan {
    void plan() override {
        printf("Let's go the Eiffel Tower, Paris");
    }
};

class HollyWood : public TourPlan {
    void plan() override {
        printf("Let's go the Hollywood Sign, Los Angeles");
    }
};

class Berlin : public TourPlan {
    void plan() override {
        printf("Let's go the Berlin Wall, East Side Gallery, Berlin");
    }
};

class Decision {
private:
    TourPlan *tourPlan ;
public:
    Decision(TourPlan *tourPlan) {
        this->tourPlan = tourPlan;
    }

    void getThePlan() {
        this->tourPlan->plan();
    }
};

int main(){

    printf("\n\nCurrent Plan : ");

    Decision *decision = new Decision(new EiffelTower());
    decision->getThePlan();

    printf("\n\nNew Plan : ");

    decision = new Decision( new HollyWood() ) ;
    decision->getThePlan();


    printf("\n\nNew Plan : ");
    decision = new Decision( new Berlin() ) ;
    decision->getThePlan();

    puts("\n\n");

    return 0;
}
