#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Entry{
public:
	virtual ~Entry();
	virtual string getName();//取其名称
	virtual int getSize();//取其大小
	virtual void printList();//总览
	string tostring();//string格式
	virtual void add(Entry *e);
protected:
	Entry();
	Entry(string name,int size);
	string name;
	int size;
};

class File:public Entry{
public:
	File(string name,int size):Entry(name,size)
	{
		cout<<"new file by File:"<<endl;
		cout<<"the name of new file is "<<name<<". The size of new file is "<<size <<endl;
	}
	string getName()
	{
		return name;
	}
	int getSize()
	{
	return size;
	}
	virtual ~File();
protected:
	virtual void printList();
};
class Directory:public Entry{
private:
	string name;
	vector<Entry>directory;//容器
public:
	Directory();
	Directory(string name):Entry(name,0)
	{
		cout<<"new directory by Directory."<<endl;
		cout<<"the name of new directory is "<<name<<endl;
	}
	~Directory();
	virtual string getName()
	{
	return name;
	}
	virtual int getSize();
	virtual void add(Entry* e);
	virtual void printList();
};