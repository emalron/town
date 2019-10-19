#pragma once
class State;

class Entity {
    public:
    int energy, energy_max;
    int bag, bag_capability;
    int money;
    State* current_state;
    
    void update();
    void changeState(State* new_state);

    virtual void eat() = 0;
    virtual void work() = 0;
    virtual void sell() = 0;
};

class Restible : virtual public Entity {
    public:
    void eat() {};
};

class Workable : virtual public Entity {
    public:
    void work() {};
};

class Marketible : virtual public Entity {
    public:
    void sell() {};
};