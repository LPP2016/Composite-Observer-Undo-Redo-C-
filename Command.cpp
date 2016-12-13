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
		cout<<"�˳�ϵͳ��"<<endl;
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
		cout<<"���ָ������˳�ϵͳ��"<<endl;
		break;
	}
	cout<<"������ָ�"<<endl;
	}
}
void Command::newDir()
{
	string name;
	cout<<"�½�Ŀ¼��"<<endl
		<<"�������½�Ŀ¼�����֣�";
	cin>>name;
	dirnameList[dirnameSize]=name;
	Directory *newdir=new Directory(dirnameList[dirnameSize]);
	dirArray[dirSize]=*newdir;
	dirSize++;
	dirnameSize++;
	cmdManager.addEdit(UndoableEdit(1,name,0));
	cout<<"��ǰ����Ŀ¼��";
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
	cout<<"ɾ��Ŀ¼��"<<endl;
	cout<<"������ɾ����Ŀ¼�����֣�";
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
		cout<<"ɾ���������Ŀ¼��";
		for(i=0;i<dirSize;i++)
			cout<<dirArray[i].getName()<<" ";
		cout<<endl;
	}
	else 
		cout<<"�Ҳ���ָ����Ŀ¼��";
	cout<<endl;
}
void Command::newFile()
{
	string name;
	int size;
	cout<<"�½��ļ���"<<endl
		<<"�������½��ļ������֣�";
	cin>>name;
	cout<<"�������½��ļ��Ĵ�С��";
	cin>>size;
	filenameList[filenameSize]=name;
	File *newfile=new File(filenameList[filenameSize],size);
	fileArray[fileSize]=*newfile;
	fileSize++;
	filenameSize++;
	cmdManager.addEdit(UndoableEdit(3,name,size));
	cout<<"��ǰ�����ļ���";
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
	cout<<"ɾ���ļ���"<<endl;
	cout<<"������ɾ�����ļ������֣�";
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
		cout<<"ɾ����������ļ���";
		for(i=0;i<fileSize;i++)
			cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
		cout<<endl;
	}
	else 
		cout<<"�Ҳ���ָ�����ļ���";
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
	cout<<"��ǰ����Ŀ¼��";
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
		cout<<"ɾ���������Ŀ¼��";
		for(i=0;i<dirSize;i++)
			cout<<dirArray[i].getName()<<" ";
		cout<<endl;
	}
	else 
		cout<<"�Ҳ���ָ����Ŀ¼��";
	cout<<endl;
}
void Command::newFile_undoredo(string name,int size)
{
	filenameList[filenameSize]=name;
	File *newfile=new File(filenameList[filenameSize],size);
	fileArray[fileSize]=*newfile;
	fileSize++;
	filenameSize++;
	cout<<"��ǰ�����ļ���";
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
		cout<<"ɾ����������ļ���";
		for(i=0;i<fileSize;i++)
			cout<<fileArray[i].getName()<<"("<<fileArray[i].getSize()<<")"<<" ";
		cout<<endl;
	}
	else 
		cout<<"�Ҳ���ָ�����ļ���";
	cout<<endl;
}