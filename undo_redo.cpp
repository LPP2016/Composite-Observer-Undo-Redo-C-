#include<iostream>
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
		comm="edit_file";break;
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
}
void CompoundEdit::replaceEdit(UndoableEdit anEdit)
{
	list<UndoableEdit>::iterator iter;
	iter=find(edits.begin(),edits.end(),anEdit);
	if(edits.end()!=iter)
	{
		edits.erase(iter);
		edits.push_back(anEdit);
	}
	else
	{
		cout<<"This command does not exist."<<endl;
	}
}
void UndoManager::undoableEditHappened()
{

}