#pragma once
#include <set>

//参数基类
class Argument {};
enum class MessageType
{
	UnKnow = 0,
	LButtonClick,
	LButtonDoubleClick,
	RButtonClick,
	RButtonDoubleClick,
	Move,
	MidButtonMove,
};
class Observable;
class Observer
{
public:
	virtual void Update(Observable* o, Argument* arg) = 0;
	virtual ~Observer() {}
};

class Observable
{
public:
	virtual ~Observable() = 0;
	virtual void AddObserver(Observer*) {};
	virtual void DelObserver(Observer*) {};
	virtual void Clear() {};
	virtual void NotifyObservers() {}
	virtual void NotifyObservers(int type) {}

private:
	std::set<Observer*> m_observers;
};