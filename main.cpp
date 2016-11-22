#include<iostream>
#include<vector>
#include"observer.h"
using namespace std;

int main(){
	//测试Observer部分
	//测试内容：Observer的添加，删除，数量；改变状态的设置；改变状态观察者的响应
	cout<<"创建三个观察者和一个被观察者。"<<endl;
	Observer *p1=new ConcreateObserver;
	Observer *p2=new ConcreateObserver;
	Observer *p3=new ConcreateObserver;
	Observable* p=new ConcreateObservable;
	cout<<"被观察者添加它的观察者："<<endl;
	p->addObserver(p1);
	p->addObserver(p2);
	p->addObserver(p3);
	cout<<"计算它的观察者的数目："<<endl;
	p->countObserver();
	cout<<"删除其中一个观察者，并计算删除后的观察者数目："<<endl;
	p->deleteObserver(p2);
	p->countObserver();
	cout<<"设置被观察者的状态为已发生改变:"<<endl;
	p->setChanged(1);
	cout<<"通知所有观察者，显示观察者的响应情况："<<endl;
	p->notifyObservers();
	cout<<"再通知所有观察者，显示响应情况："<<endl;
	p->notifyObservers();
	cout<<"重新设置为已改变状态："<<endl;
	p->setChanged(1);
	cout<<"通知被删除的观察者，显示观察者响应的情况："<<endl;
	p->notifyObservers(p2);
	cout<<"设置为已改变状态，通知某一个观察者，显示观察者响应的情况："<<endl;
	p->setChanged(1);
	p->notifyObservers(p1);

	//测试composite部分
	return 0;
}