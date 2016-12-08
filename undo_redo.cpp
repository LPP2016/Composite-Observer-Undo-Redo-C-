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
void CompoundEdit::addEdit(UndoableEdit anEdit)
{
	if(&anEdit==NULL)
		UndoableEdit *anEdit=new UndoableEdit;
	edits.push_back(anEdit);
	cout<<"add"<<anEdit.getPresentationName()
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
		edits.push_back(anedit);
		cout<<"replace this command."<<endl;
	}
	else
	{
		cout<<"this command does not exist."<<endl;
	}
}
void UndoManager::undo()
{
	
	list<UndoableEdit>::iterator iter;
	*iter=editToBeUndone();
	iter->undo();
	
}
void UndoManager::redo()
{
	list<UndoableEdit>::iterator iter;
	*iter=editToBeRedone();
	iter->redo();
	replaceEdit(*iter);
}

UndoableEdit UndoManager::editToBeUndone()
{
	list<UndoableEdit>::iterator iter;
	iter=edits.end();
	for(;iter!=edits.begin();iter--)
	{
		if(iter->canUndo()==true)
			break;
	}
	if(iter!=edits.begin())
	{
		return *iter;
	}
	
}
UndoableEdit UndoManager::editToBeRedone()
{
	list<UndoableEdit>::iterator iter;
	iter=edits.end();
	for(;iter!=edits.begin();iter--)
	{
		if(iter->canRedo()==true)
			break;
	}
	return *iter;
}

