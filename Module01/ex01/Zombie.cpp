#include "Zombie.hpp"

Zombie::Zombie(std::string name){this->name = name;}

Zombie::Zombie(void) {this->name = "";}

Zombie::~Zombie()
{
    std::cout << "Zombie object " << this->name << " destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}