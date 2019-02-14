#include <iostream>
#include <string>
#include <vector>   
#include <utility> 

using namespace std;

class MyHash
{
public: 

	MyHash( int table_size);

	int hash(const string & key) const;  //Should be private. It is set as public for you for debugging purposes.
	void insert(const std::string &key, int val );
	int get(const std::string &key) const;
	void printTable() const;

private:

	vector< std::pair<std::string, int> > table;
	int tableSize;

};

MyHash::MyHash(int table_size)
{
	table.resize(table_size);
	this->tableSize=table_size;
}

int MyHash::hash(const string &key) const
{
   int hashVal = 0; 
   for (int i = 0; i < key.length(); i++)
	hashVal = 13 * hashVal + key[i];
   hashVal %=tableSize; 
   if (hashVal < 0)   
	hashVal += tableSize; 

   return hashVal; 		
};

void MyHash::printTable() const
{

	cout<<"index \t key \tvalue"<<endl;
	for (int i=0;i<table.size();i++)
	{
		if (table[i].first=="") cout<<i<<":\t"<<"Empty ,\tEmpty"<<endl;
			else cout<<i<<":\t"<<table[i].first + " ,\t"<<table[i].second<<endl;
	}
}



void MyHash::insert(const std::string &key, int val )
{
	int hashVal = hash(key);
	for(int i=0;i<tableSize;i++)
	{
		if(table[hashVal+i].first=="")
		{
			table[hashVal+i]=make_pair(key,val);
			break;
		} else if (table[hashVal+i].first==key)
		{
			table[hashVal+i].second=val;
			break;
		}
	}
}

int MyHash::get(const std::string &key) const
{
	int hashVal = hash(key);
	for(int i=0;i<tableSize;i++)
	{
		if(table[hashVal+i].first==key)
		{
			return table[hashVal+i].second;
		}
	}
	return -1;
}




