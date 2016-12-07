#include<iostream>
#include<vector>
#include"observer.h"

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
	
public:
	UndoableEdit()
		:hasBeenDone(true),alive(true){}
	UndoableEdit(int type,string name)
		:hasBeenDone(true),alive(true),
		type(type),name(name)
	{}
	void undo(){}
	bool canUndo();
	void redo(){}
	bool canRedo();
	void die(){}
	virtual void addEdit(UndoableEdit anEdit){}
	virtual void replaceEdit(UndoableEdit anEdit){}
	//virtual bool isSignificant(){}
	virtual string getPresentationName(){return NULL;}
	//virtual string getUndoPresentationName(){return NULL;}
	//virtual string getRedoPresentationName(){return NULL;}
};
class CompoundEdit:public UndoableEdit
{
protected:
	vector<UndoableEdit> edits;

public:
	virtual void addEdit(UndoableEdit anEdit);
	virtual void replaceEdit(UndoableEdit anEdit);
	//virtual bool isSignificant();
	virtual string getPresentationName();
	//virtual string getUndoPresentationName();
	//virtual string getRedoPresentationName();
};

class UndoManager:public CompoundEdit
	//执行具体的指令
{
	int indexOfNextAdd;
	//int limit;
public:
	//int getLimit();
	//void setLimit(int i);
	//void discardAllEdits();

	//void undoTo(UndoableEdit edit);
	//void redoTo(UndoableEdit edit);
	//void undoOrRedo();
	//bool canUndoOrRedo();

	virtual void addEdit(UndoableEdit anEdit);
	virtual void replaceEdit(UndoableEdit anEdit);
	//virtual bool isSignificant();
	virtual string getPresentationName();
	//virtual string getUndoPresentationName();
	//virtual string getRedoPresentationName();

	void undoableEditHappened();
protected:
	//void trimForLimit();
	//void trimEdits(int from,int to);
	UndoableEdit editToBeUndone();
	UndoableEdit editToBeRedone();

};