/*Name: Amara Datta Dola
**Roll: 19MA20003
**Assignment 2
*/

#include <iostream>
using namespace std;

void print(int vc[], int C[], int p, int v)
{
	int coalition_vc= 0; //coalition vote count

	for(int i=0; i<p; i++)
	{
		coalition_vc += vc[i]*C[i];
	}

	if(coalition_vc <= v/2)
		return;   //It is not a winning distribution

	for(int i=0; i<p; i++)
	{
		cout<< i+1 << ": " << vc[i] <<"  ";
	}

	cout<<"  Total votes for the coalition: "<< coalition_vc;

	cout<<"\n";
}

int* copy_of_Array(int arr[], int n)
{
	int *copy= new int[n];

	for(int i=0; i<n; i++)
	{
		copy[i]= arr[i];
	}
	return copy;
}

void vote_dist(int start, int vc[], int C[] ,int p, int v, int vl)
//start->starting party, vc->vc_distr,C->Coalition_parties, p->totalno_of_Parties, v->total_no of voters,
//vl-> no of votes left to be distributed
{
	if(vl==0) //no of votes left are zero
	{
		print(vc,C,p,v);
		return;
	}

	if(start== p-1) //the last party
	{
		vc[start]= vl;
		print(vc,C,p,v);
		return;
	}

	//Case that the first party under consideration is given a vote
	int* vc_copy= copy_of_Array(vc,p);
	vc_copy[start]++; 
	vote_dist(start,vc_copy,C,p,v,vl-1);

	//Case that the first party under consideration is not given a vote
	vote_dist(start+1,vc,C,p,v,vl);
}

int main()
{
	int v,p;   //v-> no of voters , p-> no of parties  

	cout<<"#Voters: "; 
	cin>>v;
	while(v>30){
		cout<<"Enter v such that v<=30\n";
		cout<<"#Voters: "; 
		cin>>v;
	}

	cout<<"#Parties: ";
	cin>>p;
	while(p>30){
		cout<<"Enter p such that p<=10\n";
		cout<<"#Parties: "; 
		cin>>p;
	}


	cout<<"\nCoalition:\n";

	int* C= new int[p];      //to store whether a party is in the coalition or not
						    // 1 indicates it is in coalition and 0 not
	for(int i=0; i<p; i++)
		C[i]= 0;

	int x;
	cin>>x;
	while(x!=-1)
	{
		C[x-1]= 1;
		cin>>x;
	}
	
	int* vc= new int[p]; //vc stores the vote_count for each party 
	for(int i=0; i<p; i++)
		vc[i]= 0;

	vote_dist(0,vc,C,p,v,v);
	
	return 0;
}
