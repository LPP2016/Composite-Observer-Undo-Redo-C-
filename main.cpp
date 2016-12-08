#include<iostream>
#include<vector>
#include"observer.h"
#include"composite.h"
#include"undo_redo.h"
using namespace std;

int main(){
	//����Observer����
	//�������ݣ�Observer����ӣ�ɾ�����������ı�״̬�����ã��ı�״̬�۲��ߵ���Ӧ
	cout<<"Observer Testing"<<endl;
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
	cout<<"Composite testing:"<<endl;
	cout<<"Making user entries..."<<endl;
	Directory *rootdir=new Directory("root");
	Directory *bindir=new Directory("bin");
	Directory *tmpdir=new Directory("tmp");
	Directory *usrdir=new Directory("usr");
	rootdir->add(bindir);
	rootdir->add(tmpdir);
	rootdir->add(usrdir);
	File *vi=new File("vi",10000);
	File *latex=new File("latex",20000);
	bindir->add(vi);
	bindir->add(latex);
	rootdir->printList("/");
	bindir->printList("/");
	cout<<endl;
	cout<<"Making user entries..."<<endl;
	Directory *yuki=new Directory("yuki");
	Directory *hanako=new Directory("hanako");
	Directory *tomura=new Directory("tomura");
	usrdir->add(yuki);
	usrdir->add(hanako);
	usrdir->add(tomura);
	File *daily=new File("diary.html",100);
	File *Composite=new File("Composite.java",200);
	File *memo=new File("memo.tex",300);
	File *game=new File("game.doc",400);
	File *junk=new File("junk.mail",500);
	yuki->add(daily);
	yuki->add(Composite);
	hanako->add(memo);
	tomura->add(game);
	tomura->add(junk);
	rootdir->printList("/");
	//����undo_redo����
	cout<<endl<<endl<<"����undo_red���֣�"<<endl;
	UndoManager* command=new UndoManager();
	UndoManager* newdir1=new UndoManager(1,"dir1");
	UndoManager* newdir2=new UndoManager(1,"dir2");
	UndoManager* newdir3=new UndoManager(1,"dir3");
	UndoManager* newfile1=new UndoManager(1,"file1");
	UndoManager* newfile2=new UndoManager(1,"file2");
	UndoManager* deletedir3=new UndoManager(2,"dir3");
	UndoManager* setsizefile1=new UndoManager(1,"file1");
	command->addEdit(*newdir1);
	command->addEdit(*newdir2);
	command->addEdit(*newdir3);
	command->addEdit(*newfile1);
	command->addEdit(*newfile2);
	command->addEdit(*deletedir3);
	command->addEdit(*setsizefile1);
	//command->editToBeUndone();
	//command->redo();
	command->replaceEdit(*deletedir3);
	return 0;
}