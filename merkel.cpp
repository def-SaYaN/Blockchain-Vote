// C++ to generate merkle root hash from 6 transaction only(HardCoded)

#include "merkel.h"
#include "hash_sha.h"
using namespace std;





void create_even(int n)
{
string line;
int i=0;

	ifstream file1("merkle.txt");
	if(!file1)
	{
	cout<<"Error";
	}	

	while(getline(file1,line))
	{
	arr1.push_back(line);
	}
	while(i<n)
	{	
		vect1.push_back( make_pair(arr1[i],arr1[i+1]) );
		i=i+2;
	}
file1.close();
}

void calculate_even()
{
ofstream file2("merkle.txt");
string message="";
string str;
// Printing the vector

if(!file2)
{
cout<<"Error";
}
for (int k=0; k<3; k++)
{
	//cout << vect1[k].first << " "<< vect1[k].second << endl;
	message=vect1[k].first+vect1[k].second;
	cout<<"combined hash: "<<message<<endl;
	str=calculate_sha(message);
	cout<<"\ncalculated hash: "<<str<<endl;	
	if(file2.is_open())
	{
		file2 << str <<"\n";
	}
	else
	{
		cout<<"Unable to open"<<endl;
	}
}
file2.close();
}





void create_odd()
{
string message="";
string str;
string line;
int i=0;
	ifstream file4("merkle.txt");
	if(!file4)
	{
	cout<<"Error";
	}	

	while(getline(file4,line))
	{
	arr2.push_back(line);
	}
	temp.push_back(arr2[2]);
	//cout<<"success"<<endl;
	vect2.push_back( make_pair(arr2[i],arr2[i+1]) );
file4.close();

ofstream file("merkle.txt");
for (int k=0; k<1; k++)
{
	//cout << vect2[k].first << " "<< vect2[k].second << endl;
	message=vect2[k].first+vect2[k].second;
	cout<<"combined hash: "<<message<<endl;
	str=calculate_sha(message);
	cout<<"\ncalculated hash: "<<str<<endl;	
	file << str <<"\n";
	file << temp[0] <<"\n";
}
file.close();

}


void create_even1(int n)
{
string line;
int i=0;

	ifstream file0("merkle.txt");
	if(!file0)
	{
	cout<<"Error";
	}	

	while(getline(file0,line))
	{
	arr3.push_back(line);
	}
	while(i<n)
	{	
		//cout<<"success"<<endl;
		vect3.push_back( make_pair(arr3[i],arr3[i+1]) );
		i=i+2;
	}
file0.close();
}

void calculate_even1()
{

ofstream file5("merkle.txt");
string message;
string str;
// Printing the vector

if(!file5)
{
cout<<"Error";
}
for (int k=0; k<1; k++)
{
	//cout << vect3[k].first << " "<< vect3[k].second << endl;
	message=vect3[k].first+vect3[k].second;
	cout<<"combined hash: "<<message<<endl;
	str=calculate_sha(message);
	cout<<" final SHA: "<<str<<endl;	
	if(file5.is_open())
	{
		file5 << str <<"\n";
	}
	else
	{
		cout<<"Unable to open"<<endl;
	}
}
file5.close();
}


/*int main()
{
cout<<"\nCalculating Merkle Root:"<<endl;

create_even(6);
calculate_even();

create_odd();

create_even1(2);
calculate_even1();

return 0;
}*/
