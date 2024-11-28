#include <iostream>
using namespace std;

int linear_search(int ary[],int target,int size)
{
	
	
	for (int i=0;i<size;i++)
	{
		if(ary[i]==target)
		{
			//cout<<ary[i]<<" is present at the index: "<<i<<endl;
			return i;
		}
		
	}
	
	
	return -1;
}


int main()
{
	int ary[]={1,2,3,4,5,6};
	int size=sizeof(ary)/4;
	
	int key;
	cout<<"Enter the key you want to search: ";
	cin>>key;
	
	int result=linear_search(ary,key,size);
	
	if (result!=-1)
	{
		cout<<key<<" is found "<<endl;
		cout<<"At index: "<<result<<endl;
	}
	
	else 
	{
		cout<<key <<" is not found "<<endl;
	}
	
	return 0;
}


