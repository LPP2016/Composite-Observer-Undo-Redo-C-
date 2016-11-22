#include<iostream>
#include"Observer.h"
#include<algorithm>
void Observable::addObserver(Observer *o){
	cout<<"Add an Observer."<<endl;
	obs.push_back(o);
}
void Observable::deleteObserver(Observer *o){
	list<Observer*>::iterator iter ;
	iter=find(obs.begin(),obs.end(),o);
	if(obs.end()!=iter){
		obs.erase(iter);
	}
	cout<<"Delete an Observer."<<endl;
}
void Observable::notifyObservers(){
	if(!changed)
	{
		cout<<"No change!"<<endl;
		return;
	}
	cout<<"Notify Observer the change."<<endl;
	list<Observer*>::iterator iter1,iter2;
	for(iter1=obs.begin(),iter2=obs.end();iter1!=iter2;iter1++)
	{
		(*iter1)->update(this);
	}
	clearChanged();
}
void Observable::notifyObservers(Observer *arg){
	if(!changed)
	{
		cout<<"No change!"<<endl;
		return;
	}
	cout<<"Notify the certain Observer the change. "<<endl;
	list<Observer*>::iterator iter;
	iter=find(obs.begin(),obs.end(),arg);
	if(iter!=obs.end()){
		(*iter)->update(this);
	}else
		cout<<"This Observer does not exits."<<endl;
	clearChanged();
	
}

void Observable::setChanged(bool state)
{
	cout<<"SetState by observable."<<endl;
	changed=state;
}
bool Observable::getChanged()
{
	cout<<"Getstate by Observable."<<endl;
	return changed;
}
Observable::~Observable(){
	list<Observer*>::iterator iter1,iter2,temp;
	for(iter1=obs.begin(),iter2=obs.end();iter1!=iter2;)
	{
		temp=iter1;
		iter1++;
		delete(*temp);
	}
	obs.clear();
	cout<<"the list obs has been clear."<<endl;
}
void Observable::countObserver(){
	int amount=0;
	list<Observer*>::iterator iter1,iter2;
	for(iter1=obs.begin(),iter2=obs.end();iter1!=iter2;iter1++)
	{
		++amount;
	}
	cout<<"the amount of observer is "<<amount<<endl;
	//return amount;
}
void Observable::clearChanged()
{
	if(!changed)return;
	changed=false;
}
void Observable::hasChanged()
{
	if(changed)return;
	changed=true; 
}
void ConcreateObservable::setChanged(bool state)
{
	cout<<"setChanged by ConcreateObservable."<<endl;
	changed=state;
}
bool ConcreateObservable::getChanged()
{
	cout<<"getChanged by ConcreateObservable."<<endl;
	return changed;
}

void ConcreateObserver::update(Observable* o){
	if(o==NULL)
		return;
	 observerState=o->getChanged();
	 if(observerState)
		 cout<<"The Observable has been changed!"<<endl;
	 else cout<<"The Observable has not been changed"<<endl;
}
