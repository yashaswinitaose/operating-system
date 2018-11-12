#include<iostream>
using namespace std;
int main()
{
	int b[20],p[20],wt[20],t[20],pr[20],i,j,n,total=0,pos,temp,avgw,avgt;
	cout<<"Enter total no. of processes: ";
	cin>>n;
	cout<<"\n Enter the burst time and priority of the processes:\n";
	for(i=0;i<n;i++)
	{
		cout<<"For process "<<i+1;
		cout<<"\n Burst time: ";
		cin>>b[i];
		cout<<"\n Priority: ";
		cin>>pr[i];
	}
	
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
			pos=j;
		}
		
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
		
		temp=b[i];
		b[i]=b[pos];
		b[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	
	for(i=0;i<n;i++)
	{
		total=total+b[i];
		t[i]=total;
		cout<<"\n Turn around time of process "<<i+1<<" is: "<<t[i];
	}
	
	total=0;
	for(i=0;i<n;i++)
	total=total+t[i];
	
	avgt=total/n;
	
	for(i=0;i<n;i++)
	{
		wt[i]=t[i]-b[i];
		cout<<"\n waiting time of process "<<i+1<<" is: "<<wt[i];
	}
	
	total=0;
	for(i=0;i<n;i++)
	total=total+wt[i];
	
	avgw=total/n;
	
	cout<<"\n Average turn around time is: "<<avgt;
	cout<<"\n Average waiting time is: "<<avgw;
	
	int d;
	cin>>d;
	return 0;
}
