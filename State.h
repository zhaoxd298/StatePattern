#ifndef STATE_H
#define STATE_H

#include <iostream>

namespace StatePattern {

using std::cout;
using std::endl;

class GumballMachine;

class State {
public:
	State(){}
	virtual ~State(){}

	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;		
};

// 未投入硬币
class NoQuarterState : public State {
private:
	GumballMachine* m_gumballMachine;
public:
	NoQuarterState(GumballMachine* gumballMachine);
	virtual ~NoQuarterState();

	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

// 投入硬币
class HasQuarterState : public State {
private:
	GumballMachine* m_gumballMachine;
public:
	HasQuarterState(GumballMachine* gumballMachine);
	virtual ~HasQuarterState();

	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

// 准备出售糖果
class SoldState : public State {
private:
	GumballMachine* m_gumballMachine;
public:
	SoldState(GumballMachine* gumballMachine);
	virtual ~SoldState();

	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

// 糖果售罄
class SoldOutState : public State {
private:
	GumballMachine* m_gumballMachine;
public:
	SoldOutState(GumballMachine* gumballMachine);
	virtual ~SoldOutState();

	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

class WinnerState : public State {
private:
	GumballMachine* m_gumballMachine;
public:
	WinnerState(GumballMachine* gumballMachine);
	virtual ~WinnerState();

	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

}

#endif
