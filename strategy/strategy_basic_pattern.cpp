#include<iostream>
using namespace std;

class Talkable{
  public:
    virtual void Talk() = 0;
    virtual ~Talkable() {};
};

class NormalTalk : public Talkable{
  public:
    void Talk() override {
      cout<<"Talking Normally..."<<endl;
    }
};

class NoTalk : public Talkable{
  public:
    void Talk() override {
      cout<<"No Talking..."<<endl;
    }
};

class Walkable{
  public:
    virtual void Walk() = 0;
    virtual ~ Walkable(){};
};

class NormalWalk : public Walkable{
  public:
    void Walk() override {
      cout<<"Normal Walking..."<<endl;
    }
};

class NoWalk : public Walkable{
  public:
    void Walk() override {
      cout<<"No Walking..."<<endl;
    }
};

class Flyable{
  public:
    virtual void Fly() = 0;
    virtual ~Flyable(){}
};

class NormalFly : public Flyable{
  public:
    void Fly() override {
      cout<<"Normal Fly..."<<endl;
    }
};

class NoFly : public Flyable{
  public:
    void Fly() override {
      cout<<"No Fly..."<<endl;
    }
};

class Robot{
  protected:
    Talkable* t;
    Walkable* w;
    Flyable* f;

  public:
    Robot(Talkable* t, Walkable* w, Flyable* f){
      this->t = t;
      this->w = w;
      this->f = f;
    }

    void Talk(){
      t->Talk();
    }

    void Walk(){
      w->Walk();
    }

    void Fly(){
      f->Fly();
    }

    virtual void Projection()=0;
};

class Companion : public Robot{
  public:
    Companion(Talkable* t, Walkable* w, Flyable* f) : 
      Robot(t, w, f) {};
    void Projection() override {
      cout<<"Friendly Companion Robot..."<<endl;
    }
};

class Worker : public Robot{
  public:
  Worker(Talkable* t, Walkable* w, Flyable* f) : 
      Robot(t, w, f) {};
    void Projection() override {
      cout<<"Worker Robot..."<<endl;
    }
};

int main(){
  Robot* r1 = new Companion(new NormalTalk(), new NormalWalk(), new NoFly());
  r1->Projection();
  r1->Talk();
  r1->Walk();
  r1->Fly();

  cout<<"-----------------"<<endl;

  Robot* r2 = new Worker(new NoTalk(), new NoWalk(), new NormalFly());
  r2->Projection();
  r2->Talk();
  r2->Walk();
  r2->Fly();
}