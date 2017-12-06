
#include "GumballMachine.h"

using namespace StatePattern;

int main()
{
	GumballMachine* gumballMachine = new GumballMachine(1);

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();

	gumballMachine->turnCrank();

	delete gumballMachine;
}