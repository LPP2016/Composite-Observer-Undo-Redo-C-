#include<iostream>
#include<string>
#include<algorithm>
#include"undo_redo.h"

using namespace std;

void UndoableEdit::undo()
{
	if(canUndo()==true)
		hasBeenDone=false;
	else
		cout<<"This command is not undoable."<<endl;
}
bool UndoableEdit::canUndo()
{
	if(hasBeenDone&&alive)
		return true;
	else 
		return false;
}
void UndoableEdit::redo()
{
	if(canRedo()==true)
		hasBeenDone=true;
	else 
		cout<<"This command is not redoable."<<endl;
}
bool UndoableEdit::canRedo()
{
	if(!hasBeenDone&&alive)
		return true;
	else
		return false;
}
void UndoableEdit::die()
{
	if(alive==true)
		alive=false;
	else 
		return;
}
string UndoableEdit::getPresentationName()
{
	int _type=type;
	string comm;
	switch (_type)
	{
	case 1:
		comm="new_dir";break;
	case 2:
		comm="delete_dir";break;
	case 3:
		comm="new_file";break;
	case 4:
		comm="delete_file";break;
	case 5:
		comm="setsize_file";break;
	default:
		break;
	}
	return comm;
}
void UndoableEdit::printList()
{
	cout<<getPresentationName()
		<<" ("<<getName()<<")";
	if(canUndo())
		cout<<" undoable";
	else if(canRedo())
		cout<<" redoable";
	cout<<endl;
}

void CompoundEdit::addEdit(UndoableEdit anEdit)
{
	if(&anEdit==NULL)
		UndoableEdit *anEdit=new UndoableEdit;
	edits.push_front(anEdit);
	cout<<"add "<<anEdit.getPresentationName()
		<<"("<<anEdit.getName()<<")"<<endl;
}
void CompoundEdit::replaceEdit(UndoableEdit anedit)
{
	list<UndoableEdit>::iterator iter1,iter2;
	iter1=edits.begin();
	iter2=edits.end();
	for(;iter1!=iter2;iter1++)
	{
		if(iter1->getName()==anedit.getName()
			&&iter1->getPresentationName()==anedit.getPresentationName())
			break;
	}
	if(edits.end()!=iter1)
	{
		edits.erase(iter1);
		edits.push_front(anedit);
		cout<<"replace this command."<<endl;
	}
	else
	{
		cout<<"this command does not exist."<<endl;
	}
}
void UndoManager::undo()
{
	
	UndoableEdit iter;
	iter=editToBeUndone();
	iter.undo();
	replaceEdit(iter);
	cout<<"Undo the command "<<iter.getPresentationName()<<"("<<iter.getName()<<")"<<endl;
}

void UndoManager::redo()
{
	UndoableEdit iter;
	iter=editToBeRedone();
	iter.redo();
	replaceEdit(iter);
	cout<<"Redo the command "<<iter.getPresentationName()<<"("<<iter.getName()<<")"<<endl;
}

UndoableEdit UndoManager::editToBeUndone()
{
	list<UndoableEdit>::iterator iter1,iter2;
	UndoableEdit* none=new UndoableEdit(0,"none");
	iter1=edits.begin();
	iter2=edits.end();
	for(;iter1!=iter2;iter1++)
	{
		if(iter1->canUndo())
			break;
	}
	if(iter1!=iter2)
	{
		cout<<"find undoableEdit "<<iter1->getPresentationName()<<"("<<iter1->getName()<<")"<<endl;
		return *iter1;
	}
	else
	{
		cout<<"none of the undoable edit."<<endl;
			return *none;
	}
}
UndoableEdit UndoManager::editToBeRedone()
{
	list<UndoableEdit>::iterator iter1,iter2;
	UndoableEdit* none=new UndoableEdit(0,"none");
	iter1=edits.begin();
	iter2=edits.end()--;
	for(;iter1!=iter2;iter1++)
	{
		cout<<iter1->getPresentationName()<<"("<<iter1->getName()<<")"<<endl;
		if(iter1->canRedo())
			break;
	}
	if(iter1!=iter2)
	{
		cout<<"find redoable edit "<<iter1->getPresentationName()<<"("<<iter1->getName()<<")"<<endl;
		return *iter1;
	}
	else 
	{
		cout<<"none of the redoable edit."<<endl;
		return *none;
	}
}

void UndoManager::printList()
{
	list<UndoableEdit>::iterator iter=edits.begin();
	for(;iter!=edits.end();iter++)
	{
		iter->printList();
	}
}