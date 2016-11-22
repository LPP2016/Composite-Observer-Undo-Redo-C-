#include<iostream>
#include<list>
using namespace std;
class Observer;
//���۲��߽ӿ�
class Observable{
protected:
	list<Observer*> obs;//�۲��߶���
	bool changed;//�źŸ��±�־
	
public:
	Observable():changed(false){}
	virtual ~Observable();
	void addObserver(Observer* o);//��������
	void deleteObserver(Observer* o);//ɾ������
	void notifyObservers();//֪ͨ����״̬�ı�
	void notifyObservers(Observer* arg);//֪ͨĳһ�۲��߶���״̬���ı�
	virtual void setChanged(bool changed);//����״̬
	virtual bool getChanged();//�õ�״̬
	void clearChanged();//���δ�ı�״̬
	void hasChanged();//����Ѹı�״̬
	void countObserver();//�۲��ߵ�����
};
//�۲��߽ӿ�
class Observer{
public:
	Observer():observerState(false){}
	Observer(string n):name(n),observerState(false){}
	virtual ~Observer(){}
	virtual void update(Observable* o)=0;//֪ͨObserver״̬�����˱仯
protected:
	bool observerState;
	string name;
};

class ConcreateObservable:public Observable{
public:ConcreateObservable():Observable(){}
	   virtual ~ConcreateObservable(){}
	   virtual void setChanged(bool state);//����״̬
	   virtual bool getChanged();//�õ�״̬
	  
};

class ConcreateObserver:public Observer
{
public:
	ConcreateObserver():Observer(){}
	ConcreateObserver(string name):Observer(name){}
	virtual ~ConcreateObserver(){}
	virtual void update(Observable* o);
};