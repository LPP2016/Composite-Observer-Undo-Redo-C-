#include"Command.h"
using namespace std;

void Command::execute()
{
	int c;
	dirSize=0;
	fileSize=0;
	dirnameSize=0;
	filenameSize=0;
	while(cin>>c){
	switch (c)
	{
	case 0:
		cout<<"退出系统！"<<endl;
		exit(0);
		break;
	case 1:
		newDir();
		break;
	case 2:
		deleteDir();
		break;
	case 3:
		newFile();
		break;
	case 4:
		deleteFile();
		break;
	case 5:
		undoCommand();
		break;
	case 6:
		redoCommand();
		break;
	case 7:
		printDirList();
		break;
	case 8:
		printFileList();
		break;
	case 9:
		printCommandList();
		break;
	default:
		cout<<"输出指令错误，退出系统！"<<endl;
		break;
	}
	cout<<"请输入指令："<<endl;
	}
}
void Command::newDir()
{
	string name;
	cout<<"新建目录："<<endl
		<<"请输入新建目录的名字：";
	cin>>name;
	dirnameList[dirnameSize]=name;
	Directory *newdir=new Directory(dirnameList[dirnameSize]);
	dirArray[dirSize]=*newdir;
	dirSize++;
	dirnameSize++;
	cmdManager.addEdit(UndoableEdit(1,name,0));
	cout<<"当前所有目录：";
	for(int i=0;i<dirSize;i++)
	{
		cout<<dirArray[i].getName()<<" ";
	}
	cout<<endl;
}
void Command::deleteDir()
{
	string name;
	int i;
	cout<<"删除目录："<<endl;
	cout<<"请输入删除的目录的名字：";
	cin>>name;
	for(i=0;i<dirnameSize;i++)
	{
		if(dirnameList[i]==name)
			break;
	}
	if(i!=dirnameSize)
	{
		for(int j=i;j<dirnameSize;j++)
		{
			dirArray[j]=dirArray[j+1];
			dirnameList[j]=dirnameList[j+1];
		}
		dirSize--;
		dirnameSize--;
		cmdManager.addEdit(UndoableEdit(2,name,0));
		cout<<"删除后的所有目录：";
		for(i=0;i<dirSize;i++)
			cout<<dirArray[i].getName()<<" ";
		cout<<endl;
	}
	else 
		cout<<"找不到指定的目录！";
	cout<<endl;
}
void Command::newFile()
{
	string name;
	int size;
	cout<<"新建文件："<<endl
		<<"请输入新建文件的名字：";
	cin>>name;
	cout<<"请输入新建文件的大小：";
	cin>>size;
	filenameList[filenameSize]=name;
	File *newfile=new File(filenameList[filenameSize],size);
	fileArray[fileSize]=*newfile;
	fileSize++;
	filenameSize++;
	cmdManager.addEdit(UndoableEdit(3,name,size));
	cout<<"当前所有文件：";
	for(int i=0;i<fileSize;i++)
	{
		cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
	}
	cout<<endl;
}
void Command::deleteFile()
{
	string name;
	int i;
	int size;
	cout<<"删除文件："<<endl;
	cout<<"请输入删除的文件的名字：";
	cin>>name;
	for(i=0;i<filenameSize;i++)
	{
		if(filenameList[i]==name)
			break;
	}
	if(i!=filenameSize)
	{
		size=fileArray[i].getSize();
		for(int j=i;j<filenameSize;j++)
		{
			fileArray[j]=fileArray[j+1];
			filenameList[j]=filenameList[j+1];
		}
		fileSize--;
		filenameSize--;
		cmdManager.addEdit(UndoableEdit(4,name,size));
		cout<<"删除后的所有文件：";
		for(i=0;i<fileSize;i++)
			cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
		cout<<endl;
	}
	else 
		cout<<"找不到指定的文件！";
	cout<<endl;
}
void Command::undoCommand()
{
	UndoableEdit edit=cmdManager.editToBeUndone();
	string name=edit.getName();
	int type=edit.getType();
	int size=edit.getSize();
	switch (type)
	{
	case 1:
		deleteDir_undoredo(name);
		break;
	case 2:
		newDir_undoredo(name);
		break;
	case 3:
		deleteFile_undoredo(name);
		break;
	case 4:
		newFile_undoredo(name,size);
		break;
	default:
		break;
	}
	cmdManager.undo();
}
void Command::redoCommand()
{
	UndoableEdit edit=cmdManager.editToBeRedone();
	string name=edit.getName();
	int type=edit.getType();
	int size=edit.getSize();
	switch (type)
	{
	case 1:
		newDir_undoredo(name);
		break;
	case 2:
		deleteDir_undoredo(name);
		break;
	case 3:
		newFile_undoredo(name,size);	
		break;
	case 4:
		deleteFile_undoredo(name);
		break;
	default:
		break;
	}
	cmdManager.redo();
}
void Command::printDirList()
{
	for(int i=0;i<dirSize;i++)
	{
		cout<<dirArray[i].getName()<<" ";
	}
	cout<<endl;
}
void Command::printFileList()
{
	for(int i=0;i<fileSize;i++)
	{
		cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
	}
	cout<<endl;
}
void Command::printCommandList()
{
	cmdManager.printList();
}
void Command::newDir_undoredo(string name)
{
	dirSize++;
	dirnameSize++;
	dirnameList[dirnameSize]=name;
	Directory *newdir=new Directory(dirnameList[dirnameSize]);
	dirArray[dirSize]=*newdir;
	dirSize++;
	dirnameSize++;
	cout<<"当前所有目录：";
	for(int i=0;i<dirSize;i++)
	{
		cout<<dirArray[i].getName()<<" ";
	}
	cout<<endl;
}
void Command::deleteDir_undoredo(string name)
{
	int i;
	for(i=0;i<dirnameSize;i++)
	{
		if(dirnameList[i]==name)
			break;
	}
	if(i!=dirnameSize)
	{
		for(int j=i;j<dirnameSize;j++)
		{
			dirArray[j]=dirArray[j+1];
			dirnameList[j]=dirnameList[j+1];
		}
		dirSize--;
		dirnameSize--;
		cout<<"删除后的所有目录：";
		for(i=0;i<dirSize;i++)
			cout<<dirArray[i].getName()<<" ";
		cout<<endl;
	}
	else 
		cout<<"找不到指定的目录！";
	cout<<endl;
}
void Command::newFile_undoredo(string name,int size)
{
	filenameList[filenameSize]=name;
	File *newfile=new File(filenameList[filenameSize],size);
	fileArray[fileSize]=*newfile;
	fileSize++;
	filenameSize++;
	cout<<"当前所有文件：";
	for(int i=0;i<fileSize;i++)
	{
		cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
	}
	cout<<endl;
}
void Command::deleteFile_undoredo(string name)
{
	
	int i;
	for(i=0;i<filenameSize;i++)
	{
		if(filenameList[i]==name)
			break;
	}
	if(i!=filenameSize)
	{
		for(int j=i;j<filenameSize;j++)
		{
			fileArray[j]=fileArray[j+1];
			filenameList[j]=filenameList[j+1];
		}
		fileSize--;
		filenameSize--;
		cout<<"删除后的所有文件：";
		for(i=0;i<fileSize;i++)
			cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
		cout<<endl;
	}
	else 
		cout<<"找不到指定的文件！";
	cout<<endl;
}