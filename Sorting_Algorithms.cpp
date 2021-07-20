#include<iostream>
using namespace std;

//Any algorithm that does not take any extra memory or space is called as inplace algorithm!


void bubbleSort(int arr[],int n)
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		flag = 1;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag = 0;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(flag == 1) break;
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

/*
Bubble sort: Used whenever we want to find max element! It is not stable sort.

	Time Complexity : O(n^2) but if array is already sorted takes only O(n)
	Space Complexity : O(1) 
*/
void insertionSort(int arr[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

/*
	Insertion sort: whenever some elements are sorted, we need to insert an element in sorted array
	Time Complexity : O(n^2)
	Space Complexity : O(1)

*/

void selectionSort(int arr[],int n)
{
	int i,j,min_index,temp;
	for(i=0;i<n;i++)
	{
		min_index = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

/*
	Selection sort: Whenever we want to find the minimum index, we can use selection sort!
	Time Complexity : O(n^2)
	Space Complexity : O(1)
*/

void merger(int p[],int start,int mid,int end)
{
	int la = mid-start+1;		
	int ra = end-mid;			
	int arr1[la];
	int arr2[ra];
	int i,j,k;
	
	for(i=0;i<la;i=i+1)			//Copying the values 
		arr1[i] = p[i+start];
		
	for(j=0;j<ra;j++)
		arr2[j] = p[mid+1+j];
	i=0;
	j=0;
	k = start;
	while((i<la)&&(j<ra))		//Over writing the original array with sorted arrays 
	{
		if(arr1[i] < arr2[j])
			p[k++] = arr1[i++];
		else
			p[k++] = arr2[j++];
	}
	while(i<la)	p[k++] = arr1[i++];	//If any one of the sorted array is empty, populate all the remaining elements into the array
	while(j<ra) p[k++] = arr2[j++];
}

void mergeSort(int a[],int start, int end)
{
	if(start<end)
	{
		int mid;
		mid = (start+end)/2;
		mergeSort(a,start,mid);		//Divide and Conquer
		mergeSort(a,mid+1,end);
		merger(a,start,mid,end);
	}
}

/*
	Merge Sort: It is the most stable sorting algorithm. 
	
	Time Complexity :  O(n*logn)
	Space Complexity : O(n)

*/

void display(int arr[],int n)
{
	int p;
	for(p=0;p<n;p++)
		cout<<arr[p]<<" ";
}

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int start,int end)
{
	int pivot = arr[end];
	int pi = start-1;
	int i;
	for(i=start;i<end;i++)
	{
		if(arr[i]<pivot)
		{
			swap(&arr[i],&arr[++pi]);
		}
	}
	swap(&arr[++pi],&arr[end]);
	return pi;
}

void quickSort(int arr[],int start,int end)
{
	if(start<end)
	{
		int pi;
		pi = partition(arr,start,end);
		quickSort(arr,start,pi-1);
		quickSort(arr,pi+1,end);
	}
}

/*
	Quick Sort : It divides based on the pivot element. It is not a stable sorting algorithm and it follows divide and conquer
	
	Best Case Time Complexity: omega(n*logn)
	Best Case Space Complexity: omega(n)
	
	Worst Case Time Complexity: O(n^2)
	Worst Case space Complexity: O(n)
*/


int main()
{
	int n;
	cout<<"Enter Array Size : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the Array Elements : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cout<<"Bubble sort\n";
	bubbleSort(arr,n);
	
	cout<<"\nInsertion sort\n";
	insertionSort(arr,n);
	
	cout<<"\nSelection sort\n";
	selectionSort(arr,n);
	
	cout<<"\n2-way Merge sort\n";
	mergeSort(arr,0,n-1);
	display(arr,n);

	//Merge and Quick sort are outplace algorithm!s
	
	cout<<"\nQuick sort\n";
	quickSort(arr,0,n-1);
	display(arr,n);
	
	return 0;
}
