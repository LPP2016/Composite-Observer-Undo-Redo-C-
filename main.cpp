#include<iostream>
#include<vector>
#include"observer.h"
using namespace std;

int main(){
	//����Observer����
	//�������ݣ�Observer����ӣ�ɾ�����������ı�״̬�����ã��ı�״̬�۲��ߵ���Ӧ
	cout<<"���������۲��ߺ�һ�����۲��ߡ�"<<endl;
	Observer *p1=new ConcreateObserver;
	Observer *p2=new ConcreateObserver;
	Observer *p3=new ConcreateObserver;
	Observable* p=new ConcreateObservable;
	cout<<"���۲���������Ĺ۲��ߣ�"<<endl;
	p->addObserver(p1);
	p->addObserver(p2);
	p->addObserver(p3);
	cout<<"�������Ĺ۲��ߵ���Ŀ��"<<endl;
	p->countObserver();
	cout<<"ɾ������һ���۲��ߣ�������ɾ����Ĺ۲�����Ŀ��"<<endl;
	p->deleteObserver(p2);
	p->countObserver();
	cout<<"���ñ��۲��ߵ�״̬Ϊ�ѷ����ı�:"<<endl;
	p->setChanged(1);
	cout<<"֪ͨ���й۲��ߣ���ʾ�۲��ߵ���Ӧ�����"<<endl;
	p->notifyObservers();
	cout<<"��֪ͨ���й۲��ߣ���ʾ��Ӧ�����"<<endl;
	p->notifyObservers();
	cout<<"��������Ϊ�Ѹı�״̬��"<<endl;
	p->setChanged(1);
	cout<<"֪ͨ��ɾ���Ĺ۲��ߣ���ʾ�۲�����Ӧ�������"<<endl;
	p->notifyObservers(p2);
	cout<<"����Ϊ�Ѹı�״̬��֪ͨĳһ���۲��ߣ���ʾ�۲�����Ӧ�������"<<endl;
	p->setChanged(1);
	p->notifyObservers(p1);

	//����composite����
	return 0;
}