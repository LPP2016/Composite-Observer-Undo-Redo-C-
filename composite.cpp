#include<iostream>
#include<string>
#include"composite.h"
Entry::Entry()
{

}
Entry::Entry(string name,int size):name(name),size(size)
{

}
Entry::~Entry()
{

}
string Entry::getName()
{
	return name;
}
int Entry::getSize()
{
	return size;
}
void Entry::printList()
{
	cout<<"/"<<name<<"("<<size<<")"<<endl;
}
string Entry::tostring()
{
	string s;
	char t;
	int i=getSize();
	itoa(i,&t,10);
	s=getName();
	s+=" (";
	s+=t;
	s+=")\n";
	return s;
}
void Entry::add(Entry* e)
{
	cout<<"add Entry by Entry."<<endl;
}
File::~File()
{

}
void File::printList()
{
	cout<<"/"<<name<<"("<<size<<")"<<endl;
}
Directory::Directory()
{

}
Directory::~Directory()
{

}
int Directory::getSize()
{
	int size=0;
	vector<Entry>::iterator iter;
	for(iter=directory.begin();iter!=directory.end();iter++)
	{
		size=size+iter->getSize();
	}
	return size;
}
void Directory::printList()
{
	cout<<"/"<<name<<"("<<size<<")"<<endl;
	vector<Entry>::iterator iter;
	for(iter=directory.begin();iter!=directory.end();iter++)
	{
		(*iter).printList();
	}
}

void Directory::add(Entry* e)
{
	directory.push_back(*e);
	cout<<"Add Entry by Directory."<<endl;
}