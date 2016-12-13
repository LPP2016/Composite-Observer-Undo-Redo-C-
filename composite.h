#include <list>
#include <string>
#include <iostream>
using namespace std;

class Entry
{
public:
	Entry(){}
	Entry(string name,int size):name(name),size(size){}
    virtual void add(Entry* e){}
    virtual void _delete(Entry* e){}
    virtual void printList(string str){}
	virtual int getSize(){return size;}
	virtual string getName()
	{
		
		return name;
	}
protected:
    string name;
	int size;
    list<Entry* > directory;
};

class Directory:public Entry{
public:
	Directory(){}
    Directory(string name):Entry(name,0){}
    virtual void add(Entry* e);
    virtual void _delete(Entry* e);
    virtual void printList(string str);
	virtual int getSize();
	virtual string getName()
	{ 
		
		return name;
	}
};

class File:public Entry{
public:
	File(){}
    File(string name,int size):Entry(name,size){}
    virtual void printList(string str);
	virtual string getName()
	{
		return name;
	}
};

