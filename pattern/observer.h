#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <algorithm>
#include <vector>

namespace pattern {

    class Observable;

    // 观察者抽象类
    class Observer {
    public:
        virtual ~Observer();
        virtual void update() = 0;
        void observer(Observable* s);

    protected:
        Observable* subject_;
    };

    // 被观察者基类
    class Observable {
    public:
        void register_(Observer* x);
        void unregister_(Observer* x);
        void notifyObservers();

    private:
        ::std::vector<Observer*> observers_;
    };

    Observer::~Observer() {
        subject_->unregister_(this);
    }

    void Observer::observer(Observable* s) {
        s->register_(this);
        subject_ = s;
    }

    void Observable::register_(Observer* x) {
        observers_.push_back(x);
    }

    void Observable::unregister_(Observer* x) {
        ::std::vector<Observer*>::iterator
            iter = ::std::find(observers_.begin(), observers_.end(), x);
        if (iter != observers_.end()) {
            ::std::swap(*iter, observers_.back());
            observers_.pop_back();
        }
    }

    void Observable::notifyObservers() {
        for (size_t i = 0; i < observers_.size(); i++) {
            Observer* x = observers_[i];
            if (x) {
                x->update();
            }
        }
    }

}

#endif /* OBSERVER_H_ */

