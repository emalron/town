#include "Entity.hpp"
#include "State.hpp"

class Miner : public Workable, public Restible, public Marketible {
    public:
    Miner(int energy, int bag) {
        this->energy = energy;
        this->energy_max = energy;
        this->bag = 0;
        this->bag_capability = bag;
        this->money = 0;
        this->current_state = new RestState();
    };
    ~Miner();

    void work() override;
    void eat() override;
    void sell() override;
    void update();
};