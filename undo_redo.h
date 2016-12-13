#include<iostream>
#include<list>
#include<string>

using namespace std;

class UndoableEdit
{
private:
	bool hasBeenDone;
	bool alive;
protected:
	int type;//指令类型
	//1-新建目录，2-删除目录，3-新建文件，4-删除文件，5-修改文件大小
	string name;
	int size;
public:
	UndoableEdit()
		:hasBeenDone(true),alive(true){}
	UndoableEdit(int type,string name,int size)
		:hasBeenDone(true),alive(true),
		type(type),name(name),size(size)
	{}
	virtual void undo();
	bool canUndo();
	virtual void redo();
	bool canRedo();
	void die();
	virtual void addEdit(UndoableEdit anEdit){}
	virtual void replaceEdit(UndoableEdit* anEdit){}
	//virtual bool isSignificant(){}
	string getPresentationName();
	string getName()
	{
		return name;
	}
	int getSize()
	{
		return size;
	}
	int getType()
	{
		return type;
	}
	virtual void printList();
	//virtual string getUndoPresentationName(){return NULL;}
	//virtual string getRedoPresentationName(){return NULL;}
};
class CompoundEdit:public UndoableEdit
{
protected:
	list<UndoableEdit> edits;

public:
	CompoundEdit():UndoableEdit()
	{}
	CompoundEdit(int type,string name,int size)
		:UndoableEdit(type,name,size)
	{}
	virtual void undo(){}
	//virtual bool canUndo();
	virtual void redo(){}
	//virtual bool canRedo();
	virtual void addEdit(UndoableEdit anEdit);
	virtual void replaceEdit(UndoableEdit anEdit);
	virtual void printList(){}
	//virtual bool isSignificant();
	//virtual string getPresentationName();
	//virtual string getUndoPresentationName();
	//virtual string getRedoPresentationName();
};

class UndoManager:public CompoundEdit
	//执行具体的指令
{
	//int indexOfNextAdd;
	//int limit;
public:
	UndoManager():CompoundEdit()
	{
		cout<<"create a command"<<endl;
	}
	UndoManager(int type,string name,int size)
		:CompoundEdit(type,name,size)
	{
		cout<<"create a Command. The command is "<<getPresentationName()
			<<"the objecct is "<<getName()<<endl;
	}
	//int getLimit();
	//void setLimit(int i);
	//void discardAllEdits();

	virtual void undo();
	//virtual bool canUndo();
	virtual void redo();
	//virtual bool canRedo();
	//void undoTo(UndoableEdit edit);
	//void redoTo(UndoableEdit edit);
	//void undoOrRedo();
	//bool canUndoOrRedo();

	//virtual void addEdit(UndoableEdit anEdit);
	//virtual void replaceEdit(UndoableEdit anEdit);
	//virtual bool isSignificant();
	//virtual string getPresentationName();
	//virtual string getUndoPresentationName();
	//virtual string getRedoPresentationName();

	//void undoableEditHappened();
//protected:
	//void trimForLimit();
	//void trimEdits(int from,int to);
	UndoableEdit editToBeUndone();
	UndoableEdit editToBeRedone();

	virtual void printList();

};