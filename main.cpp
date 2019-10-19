#include "Miner.hpp"
#include <iostream>

int main() {
    std::cout << "This program get started." << std::endl;

    Miner m(8, 8);
    std::cout << "a miner is created." << std::endl;
    std::cout << "Miner spec " << m.bag_capability << " " << m.energy_max << std::endl;

    int turn = 0;
    while(m.money != 20) {
        m.update();
        turn ++;
    }

    std::cout << "The miner took " << turn << " turns to get his " << m.money  << " coins." << std::endl;
}