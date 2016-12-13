#include "composite.h"
#include <iostream>
using namespace std;

void Directory::add(Entry* e)
{
    if(nullptr != e)
    {
        directory.push_back(e);
    }
}

void Directory::_delete(Entry* e)
{
    if(nullptr != e)
    {
        directory.remove(e);
    }
}

void Directory::printList(string str)
{
    list<Entry* >::iterator iter = directory.begin();
    cout<<str<<name<<"("<<getSize()<<")"<<endl;
    str = str + str;
    for ( ; iter != directory.end(); iter++)
    {
        (*iter)->printList(str);
    }
}

int Directory::getSize()
{
	int size=0;
	list<Entry*>::iterator iter;
	for(iter=directory.begin();iter!=directory.end();iter++)
	{
		size=size+(*iter)->getSize();
	}
	return size;
}
void File::printList(string str)
{
    cout<<str<<name<<"("<<size<<")"<<endl;
}
