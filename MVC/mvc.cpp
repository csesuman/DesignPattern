#include<bits/stdc++.h>

using namespace std;

class Engineer { // Model
private:
    string name ;
    string role ;
public:
    Engineer() {

    }

    void setName(string name) {
        this->name=name;
    }

    void setRole(string role) {
        this->role=role;
    }

    string getName() {
        return name;
    }

    string getRole() {
        return role;
    }

};

class EngineerView {  // View

public:
    void printTheDetails(string name,string role) {
        cout<<"Name : " <<name<<endl;
        cout<<"Role : " <<role<<endl;
    }
};

class EngineerController {
private:
    Engineer     *model;
    EngineerView *view;
public:
    EngineerController(Engineer *model, EngineerView *view) {
        this->model = model;
        this->view  = view ;
    }

    void setEngineerName(string name) {
        model->setName(name);
    }

    void setEngineerRole(string role) {
        model->setRole(role);
    }

    string getEngineerName() {
        return model->getName();
    }

    string getEngineerRole() {
        return model->getRole();
    }

    void updateView() {
        view->printTheDetails(model->getName(),model->getRole());
    }
};

Engineer* retriveModelFromDB() {

    Engineer *eng = new Engineer();
    eng->setName("Suman");
    eng->setRole("Software Engineer");

    return eng;
}

int main(){

    Engineer *model = retriveModelFromDB(); // default or get by parameter

    EngineerView *view = new EngineerView();

    EngineerController *controller = new EngineerController( model , view );


    controller->updateView();

    controller->setEngineerName("Bhadra");

    cout<<"------------\n";

    controller->updateView();

    return 0;
}
