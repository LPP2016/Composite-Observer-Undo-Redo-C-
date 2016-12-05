#include <list>
#include <string>
#include <iostream>
using namespace std;

class Entry
{
public:
	Entry(char* name,int size):name(name),size(size){}
    virtual void add(Entry* e){}
    virtual void _delete(Entry* e){}
    virtual void printList(string str){}
	virtual int getSize(){return size;}
protected:
    char* name;
	int size;
    list<Entry* > directory;
};

class Directory:public Entry{
public:
    Directory(char* name):Entry(name,0){}
    virtual void add(Entry* e);
    virtual void _delete(Entry* e);
    virtual void printList(string str);
	virtual int getSize();
};

class File:public Entry{
public:
    File(char* name,int size):Entry(name,size){}
    virtual void printList(string str);
};

