#include<iostream>
#include<vector>
#include"observer.h"
#include"Command.h"
using namespace std;

int main(){
	//测试Observer部分
	//测试内容：Observer的添加，删除，数量；改变状态的设置；改变状态观察者的响应
	cout<<"测试Observer部分："<<endl;
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
	cout<<endl<<endl<<"测试Composite部分："<<endl;
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
	//测试undo_redo部分
	cout<<endl<<endl<<"测试undo_red部分："<<endl;
	UndoManager* command=new UndoManager();
	UndoManager* newdir1=new UndoManager(1,"dir1",0);
	UndoManager* newdir2=new UndoManager(1,"dir2",0);
	UndoManager* newdir3=new UndoManager(1,"dir3",0);
	UndoManager* newfile1=new UndoManager(3,"file1",0);
	UndoManager* newfile2=new UndoManager(3,"file2",0);
	UndoManager* deletedir3=new UndoManager(2,"dir3",0);
	UndoManager* setsizefile1=new UndoManager(5,"file1",0);
	command->addEdit(*newdir1);
	command->addEdit(*newdir2);
	command->addEdit(*newdir3);
	command->addEdit(*newfile1);
	command->addEdit(*newfile2);
	command->addEdit(*deletedir3);
	command->addEdit(*setsizefile1);
	command->printList();
	command->replaceEdit(*deletedir3);
	command->printList();
	command->editToBeUndone();
	command->editToBeRedone();
	command->undo();
	command->printList();
	command->undo();
	command->printList();
	command->redo();
	command->printList();
	command->redo();
	command->printList();
	command->redo();
	command->printList();

	//Command
	Command cmd;
	cout<<endl<<endl<<endl;
	cout<<"****************************"<<endl;
	cout<<"**       0退出程序        **"<<endl;
	cout<<"**       1新建目录        **"<<endl;
	cout<<"**       2删除目录        **"<<endl;
	cout<<"**       3新建文件        **"<<endl;
	cout<<"**       4删除文件        **"<<endl;
	cout<<"**       5指令撤销        **"<<endl;
	cout<<"**       6指令恢复        **"<<endl;
	cout<<"**      7输出目录列表     **"<<endl;
	cout<<"**      8输出文件列表     **"<<endl;
	cout<<"**      9输出指令列表     **"<<endl;
	//cout<<"**     10修改文件大小     **"<<endl;
	cout<<"****************************"<<endl<<endl;
	cout<<"请输入指令："<<endl;
		cmd.execute();
		
	return 0;
}