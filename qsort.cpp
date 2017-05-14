#include <iostream>

using namespace std;

bool myless(int a, int b)
{
	return (a<b)?true:false;
}
void exch(int a[],int m,int n)
{
	int temp = a[m];
	a[m] = a[n];
	a[n] = temp;
}
int partition(int a[],int lo,int hi)
{
	int i = lo,j = hi+1;
	int v = a[lo];
	while(true)
	{
		while(myless(a[++i],v)) if(i  == hi) break;
		while(myless(v,a[--j])) if(j == lo) break;
		if(i>=j) break;
		exch(a,i,j);

	}
	exch(a,lo,j);
	return j;
}

void qsort(int a[],int lo,int hi)
{
	if(hi<=lo) return;
	int j = partition(a,lo,hi);
	qsort(a,lo,j-1);
	qsort(a,j+1,hi);
}

int main()
{
	int a[10] = {4,3,8,1,2,9,0,7,5,6};
	qsort( a ,0,9);
	for(int i = 0;i<10;i++) cout<<a[i]<<endl;
}
