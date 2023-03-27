#include "Zombie.hpp"

int main(void)
{
	Zombie *heap = newZombie("heap call");
	heap->announce();
	delete heap;

	Zombie stack = Zombie("Stack call");
	stack.announce();

	randomChump("Random");
	return (0);
}