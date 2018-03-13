//Edited


#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <chrono>
#include <ctime>
#include<cstdlib>
#include "hash_sha.h"
//#include "merkel.h"

using namespace std;

//vector< pair <string,string> > vect1;
//vector< pair <string,string> > vect2;
//vector< pair <string,string> > vect3;
//vector<string> arr1;
//vector<string> arr2;
//vector<string> arr3;
//vector<string> temp;

string nv;
int a,b,c=0;

class Usrt
{
	time_t end_time;
	double elapsed_seconds;
	string name;
	char vote;
	string num;
	char v;
public:
	string getInfo()
	{
		auto start = chrono::system_clock::now();
		cout<<"\nEnter name: ";
		cin>>name;
		cout<<endl;
		cout<<"Enter vote(a,b,c): ";
		cin>>v;
		auto end = chrono::system_clock::now();
		end_time = std::chrono::system_clock::to_time_t(end);
		if(v=='a'||v=='b'||v=='c')
		{
			vote=v;
		}
		else
		{	
			cout<<"\nInvalid vote";
			exit(0);
		}
		nv=name+vote;
		return nv;
	}

	void printInfo(int k)
	{
	
	string file_name="Data_blockchain";
	num=to_string(k);
	string fin_name=file_name+num;

	if(vote=='a'){a++;}
	else if(vote=='b'){b++;}
	else if(vote=='c'){c++;}

	cout<<"\nVote "<<v<<" given by "<<name<<endl;
	cout<<nv;
	cout<<"\n Total vote of a "<<a<<" b "<<b<<" c "<<c<<endl;
	ofstream file2(fin_name,ios::app);
	if(!file2)
	{
		cout<<"Error";
	}
	file2 << "Time: " <<ctime(&end_time)<<"\n";
	file2 << "Name: " << name <<"\n";
	file2 << "vote: " << v <<"\n";
	file2<<"Total vote of a "<<a<<" b "<<b<<" c "<<c<<"\n";
	file2.close();

	}

	string hash(string str)
	{
	string val;
	val=calculate_sha(str);
	return val;
	}

	void insert_merkle_txt(string h,int k)
	{	
		string file_name="Data_blockchain";
		num = to_string(k);
		string fin_name=file_name+num;
		
		ofstream file("merkle.txt",ios::app);
		ofstream file2(fin_name,ios::app);
		if(!file && !file2)
		{
			cout<<"Error";
		}
		file2 <<"Hash: "<< h <<"\n\n\n";
		file << h <<"\n";
		
		file.close();
		file2.close();
	}

};



int main()
{
int k;
int cal;
string s;
string hval;


//ofstream file2("Data_blockchain.txt");
//file2.close();

cout<<"\n\nWelcome to Blockchain based Voting System(6 vote at a time)"<<endl;
cout<<"Enter Block No.: "<<endl;
cin>>k;
cout<<"Enter Data into Blocks\n";

//CHANGES
	for(int i=0;i<6;i++)
	{
		Usrt *u=new Usrt();
		s=u->getInfo();
		u->printInfo(k);
		hval=u->hash(s);
		cout<<"\nTx_Hash: "<<hval<<endl;
		u->insert_merkle_txt(hval,k);

	}
	//create_even(6);
	//calculate_even();
	//create_odd();
	//create_even1(2);
	//calculate_even1();
	//system("./mine");



return 0;
}


