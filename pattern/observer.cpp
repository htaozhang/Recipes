#include <iostream>
#include <vector>
#include <stdio.h>

class Observable;

class Observer
{
public:
    virtual ~Observer();
    virtual void update() = 0;

    void observer(Observable* s);

protected:
    Observable* subject_;
};

class Observable
{
public:
    void register_(Observer* x);
    void unregister_(Observer* x);
    void notifyObservers();

private:
    std::vector<Observer*> observers_;
};

Observer::~Observer()
{
    subject_->unregister_(this);
}

void Observer::observer(Observable* s)
{
    s->register_(this);
    subject_ = s;
}

void Observable::register_(Observer* x)
{
    observers_.push_back(x);
}

void Observable::unregister_(Observer* x)
{
    std::vector<Observer*>::iterator iter = 
        std::find(observers_.begin(), observers_.end(), x);
    if (iter != observers_.end())
    {
        std::swap(*iter, observers_.back());
        observers_.pop_back();
    }
}

void Observable::notifyObservers()
{
    for (size_t i = 0; i < observers_.size(); i++)
    {
        Observer* x = observers_[i];
        if (x) 
        {
            x->update();
        }
    }
}


class Foo : public Observer
{
    virtual void update()
    {
        printf("Foo::update() %p\n", this);
    }
};


int main()
{
    Foo* p = new Foo;
    Observable subject;
    p->observer(&subject);
    subject.notifyObservers();
    delete p;
    subject.notifyObservers();

    return 0;
}


