#include<iostream>
#include<vector>
#include"composite.h"
#include"undo_redo.h"
using namespace std;
class Command
{
private:
	UndoManager cmdManager;
	Directory dirArray[100];
	File fileArray[100];
	string dirnameList[200];
	string filenameList[200];
	int dirSize;
	int fileSize;
	int dirnameSize;
	int filenameSize;
public:
	Command()
	{}
	~Command(){}
	void newDir();//�½�Ŀ¼
	void deleteDir();//ɾ��Ŀ¼
	void newFile();//�½��ļ�
	void deleteFile();//ɾ���ļ�
	void undoCommand();//ָ���
	void redoCommand();//ָ��ָ�
	void printDirList();//���Ŀ¼�б�
	void printFileList();//����ļ��б�
	void printCommandList();//���ָ���б�
	void newDir_undoredo(string name);
	void deleteDir_undoredo(string name);
	void newFile_undoredo(string name,int size);
	void deleteFile_undoredo(string name);
	void execute();
	
};
