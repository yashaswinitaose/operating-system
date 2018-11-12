#include<iostream>
using namespace std;
#include<conio.h>

int main()
{


    int p,f,i,count=0;
    cout<<"\nEnter the No. of Pages: ";
    cin>>p;  
    
	int page[p]; 
    cout<<"\nEnter the Reference String:\n";

    for(i=0;i<p;i++)

          {
          cin>>page[i]; 
          }

          cout<<"\nEnter the No of frames: ";
          cin>>f;

          int frame[f],fcount[f];

          for(i=0;i<f;i++)
          {
          frame[i]=-1; 
          fcount[i]=0; 
          }

          i=0;
          while(i<p)
          {
            int j=0,flag=0;
            while(j<f)
            {
               if(page[i]==frame[j]){  
               flag=1;
               fcount[j]=i+1;
               }
               j++;
           }   

            j=0;  
            cout<<"\n-----------------------------------\n";
            cout<<"\n \nRef string  |  Page Frames\n";
            
            cout<<"\t"<<page[i]<<"   |";   

            if(flag==0)

            {
             int min=0,k=0;
              while(k<(f-1))
                {
                  if(fcount[min]>fcount[k+1]) 
                    min=k+1;
                  k++;
                }

               frame[min]=page[i]; 
               fcount[min]=i+1;   
               count++;           

            while(j<f)
            {
               cout<<"\t|"<<frame[j]<<"|";
               j++;

            }
             }
           i++; 
          }

          cout<<"\n-----------------------------------\n";
          cout<<"\nTotal Page Fault is: "<<count;

          return 0;

}      
