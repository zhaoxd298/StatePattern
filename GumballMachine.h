#ifndef GUMBALLMACHINE_H
#define GUMBALLMACHINE_H

#include "State.h"

namespace StatePattern {

class GumballMachine 
{
private:
	State* m_soldOutState;
	State* m_noQuarterState;
	State* m_hasQuarterState;
	State* m_soldState;

	State* m_state;
	int count;

public:
	GumballMachine(int numberGumballs = 0)
	{
		m_soldOutState = new SoldOutState(this);
		m_noQuarterState = new NoQuarterState(this);
		m_hasQuarterState = new HasQuarterState(this);
		m_soldState = new SoldState(this);

		this->count = numberGumballs;
		m_state = m_soldOutState;

		if (numberGumballs > 0) {
			m_state = m_noQuarterState;
		}
	}	
	~GumballMachine(){}
	void insertQuarter()	// 放入硬币
	{
		m_state->insertQuarter();
	}
	void ejectQuarter()		// 退钱
	{
		m_state->ejectQuarter();
	}
	void turnCrank()		// 转动曲柄，拿到糖果
	{
		m_state->turnCrank();
		m_state->dispense();
	}
	void setState(State* state)
	{
		this->m_state = state;
	}
	void releaseBall()
	{
		cout << "A gumball comes rolling out the slot..." << endl;
		if (0 != count) {
			count --;
		}
	}
	void refill(int numberGumballs) 
	{
		this->count = numberGumballs;
		if (numberGumballs > 0) {
			m_state = m_noQuarterState;
		}
	}

	State* getSoldOutState()
	{
		return m_soldOutState;
	}
	State* getNoQuarterState()
	{
		return m_noQuarterState;
	}
	State* getHasQuarterState()
	{
		return m_hasQuarterState;
	}
	State* getSoldState()
	{
		return m_soldState;
	}
	int getCount()
	{
		return count;
	}
};

}

#endif
