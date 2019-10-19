#include "State.hpp"
#include <iostream>

State::~State() {
    //
}

RestState::~RestState() {
    //
}

void RestState::execute(Entity* entity) {
    if(entity->energy < entity->energy_max) {
        entity->eat();
    }
    if(entity->energy >= entity->energy_max) {
        entity->energy = entity->energy_max;
        entity->changeState(new WorkState);
    }
}

WorkState::~WorkState() {
    //
}

void WorkState::execute(Entity* entity) {
    if(entity->bag < entity->bag_capability) {
        entity->work();
    }
    if(entity->bag >= entity->bag_capability) {
        entity->changeState(new MarketState);
    }
    if(entity->energy <= 5 ) {
        entity->changeState(new RestState);
    }
}

MarketState::~MarketState() {
    //
}

void MarketState::execute(Entity* entity) {
    if(entity->bag > 0) {
        entity->sell();
    }
    else {
        entity->changeState(new WorkState);
    }
}