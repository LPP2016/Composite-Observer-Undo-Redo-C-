#include<iostream>
#include<list>
using namespace std;
class Observer;
//被观察者接口
class Observable{
protected:
	list<Observer*> obs;//观察者队列
	bool changed;//信号更新标志
	
public:
	Observable():changed(false){}
	virtual ~Observable();
	void addObserver(Observer* o);//新增对象
	void deleteObserver(Observer* o);//删除对象
	void notifyObservers();//通知对象状态改变
	void notifyObservers(Observer* arg);//通知某一观察者对象状态被改变
	virtual void setChanged(bool changed);//设置状态
	virtual bool getChanged();//得到状态
	void clearChanged();//变成未改变状态
	void hasChanged();//变成已改变状态
	void countObserver();//观察者的数量
};
//观察者接口
class Observer{
public:
	Observer():observerState(false){}
	Observer(string n):name(n),observerState(false){}
	virtual ~Observer(){}
	virtual void update(Observable* o)=0;//通知Observer状态发生了变化
protected:
	bool observerState;
	string name;
};

class ConcreateObservable:public Observable{
public:ConcreateObservable():Observable(){}
	   virtual ~ConcreateObservable(){}
	   virtual void setChanged(bool state);//设置状态
	   virtual bool getChanged();//得到状态
	  
};

class ConcreateObserver:public Observer
{
public:
	ConcreateObserver():Observer(){}
	ConcreateObserver(string name):Observer(name){}
	virtual ~ConcreateObserver(){}
	virtual void update(Observable* o);
};