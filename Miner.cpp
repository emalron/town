#pragma once
#include "State.hpp"
#include "Miner.hpp"
#include <iostream>

void Entity::update() {
    this->current_state->execute(this);
}

void Entity::changeState(State* new_state) {
    delete this->current_state;
    this->current_state = new_state;
}

Miner::~Miner() {
    delete this->current_state;
}

void Miner::update() {
    this->current_state->execute(this);
}

void Miner::eat() {
    this->energy++;
    std::cout << "Miner: Zzz... [" << this->energy << "]" << std::endl;
}

void Miner::work() {
    this->bag++;
    this->energy--;
    std::cout << "Miner: Work! work! [" << this->bag << "]" << std::endl;
}

void Miner::sell() {
    if(this->bag > 0) {
        this->bag--;
        this->money++;
        std::cout << "Miner: got a coin! [" << this->money << "]" << std::endl;
    }
}