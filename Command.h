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
	void newDir();//新建目录
	void deleteDir();//删除目录
	void newFile();//新建文件
	void deleteFile();//删除文件
	void undoCommand();//指令撤销
	void redoCommand();//指令恢复
	void printDirList();//输出目录列表
	void printFileList();//输出文件列表
	void printCommandList();//输出指令列表
	void newDir_undoredo(string name);
	void deleteDir_undoredo(string name);
	void newFile_undoredo(string name,int size);
	void deleteFile_undoredo(string name);
	void execute();
	
};
