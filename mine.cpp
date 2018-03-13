//Edited

#include<iostream>
#include <sys/stat.h>
#include <chrono>
#include <ctime>
#include "hash_sha.h"
#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<limits>
#include<sstream>
#include <numeric>
#include<string>
#include "merkel.h"


using namespace std;

vector<string> arr;
vector< pair <string,string> > vect1;
vector< pair <string,string> > vect2;
vector< pair <string,string> > vect3;
vector<string> arr1;
vector<string> arr2;
vector<string> arr3;
vector<string> temp;

class Blockchain
{
string sval;
string value;
time_t end_time;
string et;
string version="000001";
string previous_hash;
string merkle_root;
int nonce=0;

public:

void insert_value(string p,vector<string> mr)
{

    string previous_hash=p;
    string merkle_root=accumulate(begin(mr),end(mr),merkle_root);

    sval=version+previous_hash+merkle_root;
    cout<<"\nsval: "<<sval;
}

string calculate()
{
string n;
string str;
string s1;
string s2;
string s;

while(1)
{
    auto start = chrono::system_clock::now();
    cout<<"\nnonce: "<<nonce<<endl;
    n=to_string(nonce);
    cout<<"\ntotalhash:"<<str<<endl;
    s2=merkle_root+n;
    s=calculate_sha(s2);
    cout<<s<<endl;
	if(s[0] == '0'&& s[1]=='0'&& s[2]=='0'&& s[3]=='0'&& s[4]=='0'/* && s[5]=='0'*/)
	{
	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end-start;
	end_time = std::chrono::system_clock::to_time_t(end);
	et = ctime(&end_time);
	str=sval+n+et ; //this is the block-header version+previous_hash+merkle_root+nonce value
	s1=calculate_sha(str); //previous block hash must be added to incoming block

	ofstream file1("blockchain.txt",ios::app);
	cout<<"\n Solved final hash found: "<<s<<endl;
	cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	file1 << s1 <<endl;
	file1.close();

	/*ofstream fileD("Data_blockchain.txt",ios::app);
	fileD << str <<"\n";
	fileD.close();*/
	return str;
	break;
	}
	else
	{
	nonce++;
	continue;
	}

}

}

istream& ignoreline(ifstream& in , ifstream::pos_type& pos)
{
    pos=in.tellg();
    return in.ignore(numeric_limits<streamsize>::max(),'\n');
}

string lastHash(ifstream& in)
{
    ifstream::pos_type pos = in.tellg();
    ifstream::pos_type lastPos;
        while (in >> std::ws && ignoreline(in, lastPos))
        {
            pos = lastPos;
        }
        in.clear();
        in.seekg(pos);
    getline(in,value);
    return value;
}

bool fileExists(string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

};



int main()
{

Blockchain b1,b2;
int blocknumber;
string blocknum;
string line;
string phsh;
string a;
string g="000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f";
string blkval;

cout<<"\nBlockchain Status:"<<endl;
cout<<"WHiCh bLoCk tO MiNe?: ";
cin>>blocknumber;


blocknum=to_string(blocknumber);
string blockname = "Data_blockchain" + blocknum;

bool blockexist=b2.fileExists(blockname);

try{
if(blockexist)
{

//Calculating Merkle Root
//ofstream filet("merkle.txt");
//filet.close();
create_even(6);
calculate_even();
create_odd();
create_even1(2);
calculate_even1();

cout<<"till here!!!";


ifstream file("merkle.txt");
if(!file)
{
cout<<"Error";
}
while(getline(file,line))
{
arr.push_back(line);
}
file.close();


/*genesis block
b1.insert_value(g,arr);
blkval=b1.calculate();

cout<<"\nblkval: "<<blkval<<endl;
ofstream fileD("Data_blockchain0",ios::app);  //Digitally sigining with the block values
fileD << blkval <<"\n";
fileD.close();
*/

//Must be new block and in recursive
//selects the recent value from below.
ifstream file2("blockchain.txt");
if(!file2)
{
cout<<"Error";
}
phsh=b2.lastHash(file2);
istringstream iss(phsh);
getline(iss, a, ' ');
file2.close();


cout<<"\nlast value in blockchain:"<<a<<endl;
b2.insert_value(a,arr);
blkval=b2.calculate();


ofstream fileD(blockname,ios::app);
if(!fileD)
{
cout<<"Error";
}
fileD << blkval <<"\n";
fileD.close();
}

else
{
cout<<"No such block\n";
exit(0);
}
}
catch(exception& e)
{
cout<<"Cannot Start Already Mined block\n";
}


return 0;
}
