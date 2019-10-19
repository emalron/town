#pragma once
#include "Entity.hpp"
#include <string>

class State {
    public:
    std::string name;
    State() {};
    virtual ~State();
    virtual void execute(Entity*) = 0;
};

class RestState : virtual public State {
    public:
    RestState() : State() {this->name = "rest state";};
    ~RestState();
    void execute(Entity* entity);
};

class WorkState : virtual public State {
    public:
    WorkState() : State() {this->name = "work state";};
    ~WorkState();
    void execute(Entity* entity);
};

class MarketState : virtual public State {
    public:
    MarketState() : State() {this->name = "market state";};
    ~MarketState();
    void execute(Entity* entity);
};