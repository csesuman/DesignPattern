#include<bits/stdc++.h>
using namespace std;

class IssueState;

class DeliveryAbstract  {
public:

    virtual void setCurrentState(IssueState *state) = 0;
};

class IssueState
{
public:
    // Business Logic
    virtual void updateState(DeliveryAbstract *ctx) = 0;
};

class Resolved : public IssueState
{
private:
    Resolved() {}
    ~Resolved() {}

public:
    static Resolved& Instance()
    {
        static Resolved myInstance;
        return myInstance;
    }


    void updateState(DeliveryAbstract *ctx) override
    {
        cout<<"Issue is Resolved!"<<endl;
//        ctx->updateState();
    }
};

class Testing : public IssueState
{
private:
    Testing() {}
    ~Testing() {}

public:
    static Testing& Instance()
    {
        static Testing myInstance;
        return myInstance;
    }


    void updateState(DeliveryAbstract *ctx) override
    {
        cout<<"Issue is in Testing!"<<endl;
        ctx->setCurrentState(&Resolved::Instance());
    }
};

class Done : public IssueState
{
private:
    Done() {}
    ~Done() {}

public:
    static Done& Instance()
    {
        static Done myInstance;
        return myInstance;
    }


    void updateState(DeliveryAbstract *ctx) override
    {
        cout<<"Issue is Done!"<<endl;
        ctx->setCurrentState(&Testing::Instance());
    }
};

class Progress : public IssueState
{
private:
    Progress() {}
    ~Progress() {}

public:
    static Progress& Instance()
    {
        static Progress myInstance;
        return myInstance;
    }


    void updateState(DeliveryAbstract *ctx) override
    {
        cout<<"Issue is in Progress!"<<endl;
        ctx->setCurrentState(&Done::Instance());
    }
};

class Open : public IssueState
{
private:
    Open() {}
    ~Open() {}

public:
    static Open& Instance()
    {
        static Open myInstance;
        return myInstance;
    }


    void updateState(DeliveryAbstract *ctx) override
    {
        cout<<"Issue is Opened!"<<endl;
        ctx->setCurrentState(&Progress::Instance());
    }
};

class Acknowledged : public IssueState
{
private:
    Acknowledged() {}
    ~Acknowledged() {}

public:
    static Acknowledged& Instance()
    {
        static Acknowledged myInstance;
        return myInstance;
    }

    void updateState(DeliveryAbstract *ctx) override
    {
        cout<<"Issue is Acknowledged! Hand Over to Next Processing..."<<endl;
        ctx->setCurrentState(&Open::Instance());
    }
};

class DeliveryContext : public DeliveryAbstract
{
private:
    IssueState *currentState;
    string issueId;
public:
    DeliveryContext(IssueState *state, string issueId)
    {
        this->currentState = state;
        this->issueId = issueId;

        if(state==nullptr) {
            currentState = &Acknowledged::Instance();
        }
    }

    IssueState* getCurrentState() {
        return this->currentState;
    }

    void setCurrentState(IssueState *state) {
        this->currentState = state;
    }

    string getIssueId() {
        return issueId;
    }

    void update() {
        this->currentState->updateState(this);
    }
};

int main()
{
    DeliveryContext *ctx = new DeliveryContext(nullptr , " Stream - 450 ");

    ctx->update();
    ctx->update();
    ctx->update();
    ctx->update();
    ctx->update();
    ctx->update();

    return 0;

}
