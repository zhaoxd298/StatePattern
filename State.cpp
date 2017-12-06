#include "State.h"
#include "GumballMachine.h"

using namespace StatePattern;

NoQuarterState::NoQuarterState(GumballMachine* gumballMachine)
{
	this->m_gumballMachine = gumballMachine;
}
NoQuarterState::~NoQuarterState(){}

void NoQuarterState::insertQuarter()
{
	cout << "You inserted a quarter" << endl;
	m_gumballMachine->setState(m_gumballMachine->getHasQuarterState());
}
void NoQuarterState::ejectQuarter()
{
	cout << "You haven't inserted a quarter..." << endl;
}
void NoQuarterState::turnCrank()
{
	cout << "YOu turned, but there's no quarter" << endl;
}
void NoQuarterState::dispense()
{
	cout << "You need to pay first" << endl;
}		



HasQuarterState::HasQuarterState(GumballMachine* gumballMachine)
{
	this->m_gumballMachine = gumballMachine;
}
HasQuarterState::~HasQuarterState()
{

}
void HasQuarterState::insertQuarter()
{
	cout << "You can't insert another quarter" << endl;
}
void HasQuarterState::ejectQuarter()
{
	cout << "Quarter returned" << endl;
	m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
}
void HasQuarterState::turnCrank()
{
	cout << "You turned..." << endl;
	m_gumballMachine->setState(m_gumballMachine->getSoldState());
}
void HasQuarterState::dispense()
{
	cout << "No gumball dispensed" << endl;
}	



SoldState::SoldState(GumballMachine* gumballMachine)
{
	this->m_gumballMachine = gumballMachine;
}
SoldState::~SoldState(){}

void SoldState::insertQuarter()
{
	cout << "Please wait, we're already giving you a gumball" << endl;
}
void SoldState::ejectQuarter()
{
	cout << "Sorry, you alread turned the crank" << endl;
}
void SoldState::turnCrank()
{
	cout << "Turning twice doesn't get you another gumball" << endl;
}
void SoldState::dispense()
{
	m_gumballMachine->releaseBall();
	if (m_gumballMachine->getCount() > 0) {
		m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
	} else {
		cout << "Oops, out of gumballs" << endl;
		m_gumballMachine->setState(m_gumballMachine->getSoldOutState());
	}
}	
		

SoldOutState::SoldOutState(GumballMachine* gumballMachine)
{
	this->m_gumballMachine = gumballMachine;
}
SoldOutState::~SoldOutState(){}

void SoldOutState::insertQuarter()
{
	cout << "You can't insert a quarter, the machine is sold out" << endl;
}
void SoldOutState::ejectQuarter()
{
	cout << "You can't eject, you haven't inserted a quarter yet" << endl;
}
void SoldOutState::turnCrank()
{
	cout << "You turned, but there are no gumballs" << endl;
}
void SoldOutState::dispense()
{
	cout << "No gumball dispensed" << endl;
}


WinnerState::WinnerState(GumballMachine* gumballMachine)
{
	this->m_gumballMachine = gumballMachine;
}
WinnerState::~WinnerState(){}

void WinnerState::insertQuarter()
{

}
void WinnerState::ejectQuarter()
{

}
void WinnerState::turnCrank()
{

}
void WinnerState::dispense()
{
	
}				
