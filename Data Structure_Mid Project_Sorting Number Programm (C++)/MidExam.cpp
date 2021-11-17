#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates2(int arr[30], int n)
{
    if (n==0 || n==1)
        return n;

    int temp[n];
    int j = 0;
    for (int i=0; i<n-1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];

    temp[j++] = arr[n-1];
    for (int i=0; i<j; i++)
        arr[i] = temp[i];

return j;
}
int insertionSort(int ar[30], int n)
{
    int i,j,temp;

    for(i=1;i<=n-1;i++) {
        temp=ar[i];
        j=i-1;
        while((temp<ar[j])&&(j>=0)){
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=temp;
    }
    cout<<"\nSorted list is as follows =>\n";
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
}

int LinearSearch(int arr[30], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;

}

BinarySearch(int arr[30], int n, int x)
{
	int first, last, middle;

	cout<<"Enter the number you want to search => ";
        cin>>x;
	first = 0;
	last = n-1;
	middle = (first+last)/2;
	while (first <= last)
	{
	   if(arr[middle] < x){
            first = middle + 1;
        }
	    else if(arr[middle] == x) {
		cout <<endl <<"Number "<<x <<" Has Founded in the location "<<middle<<" (Binary Search)\n";
		break;
           }
        else {
            last = middle - 1;
        }
           middle = (first + last)/2;
    }
    if(first > last)
	{
	   cout <<"\nNumber "<<x<<" is NOT Found in the array (Binary Search)\n";
	}
}

int InterpolationSearch(int arr[], int n, int x)
{
    int low = 0, hi = (n - 1);int loc;
    cout<<"\nEnter the Element to be searched => ";
	cin>>x;
    while (low <= hi && x >= arr[low] && x <= arr[hi])
    {
        if (low == hi){
            if (arr[low] == x) {
                cout << "\nElement Found at index " << low <<" (Interpolation Search)"<<endl;
                break;
            }
            else if (arr[low] != x){
                cout << "\nNOTHING element is Found. (Interpolation Search)\n";
            }
        }
        loc = low + (((double)(hi - low) / (arr[hi] - arr[low])) * (x - arr[low]));
        if (arr[loc] == x){
            cout << "\nElement Founded at index " << loc <<" (Interpolation Search)"<<endl;
            break;
        }
        if (arr[loc] < x)
            low = loc + 1;
        else
            hi = loc - 1;
    }
    if(!(low <= hi && x >= arr[low] && x <= arr[hi])){
        cout << "\nNOTHING element is Found. (Interpolation Search)\n";
    }
}
int main(void)
{cout<<"     Marcel Valeran \n";
 cout<<"       IS Class 2 \n";
 cout<<"      012201800029 \n";
 cout<<"'SEARCHING NUMBER PROGRAM'\n";
 cout<<"___________________________\n";
    int i, n, x, l, ar[30], choices, index;
    while(choices !=4){
            cout<<" \nYour Choices ? \n";
            cout<<" 1. Linear Search"<<endl;
            cout<<" 2. Binary Search"<<endl;
            cout<<" 3. Interpolation Search"<<endl;
            cout<<" 4. Close The Program"<<endl;
            cout<<" Enter Your Choice => ";
            cin>>choices;
            cout<<endl;
            switch(choices){
                case 1:
                cout<<"Enter the number of elements: ";
                    cin>>n;
                    cout<<"\nEnter the elements !\n";
                    for(i=0;i<n;i++) {
                        cin>>ar[i];
                    }
                    insertionSort(ar,n);
                    n = removeDuplicates2(ar, n);
                    cout << "\nChecked Numbers From Duplication: \n";
                    for (int i=0; i<n; i++){
                        cout << ar[i] << " ";}
                    cout<<endl;
                    cout<<"Enter the number you want to search => ";
                    cin>>x;cout<<endl;
                    l = LinearSearch(ar,n,x);
                    (l == -1)? cout<<"Number "<<x<<" is NOT found in the array (Linear Search)\n"
                                    : cout<<"Element "<<x<<" is Founded at index " <<l <<" (Linear Search)" <<endl;
                    break;
                case 2:
                    cout<<"Enter the number of elements: ";
                    cin>>n;
                    cout<<"\nEnter the elements !\n";
                    for(i=0;i<n;i++) {
                        cin>>ar[i];
                    }
                    insertionSort(ar, n);
                    n = removeDuplicates2(ar, n);
                    cout << "\nChecked Numbers From Duplication: \n";
                    for (int i=0; i<n; i++)
                        cout << ar[i] << " ";
                    cout<<endl;
                    BinarySearch(ar,n,x);
                    break;
                case 3:
                cout<<"Enter the number of elements: ";
                    cin>>n;
                    cout<<"\nEnter the elements !\n";
                    for(i=0;i<n;i++) {
                        cin>>ar[i];
                    }
                    insertionSort(ar,n);
                    n = removeDuplicates2(ar, n);
                    cout << "\nChecked Numbers From Duplication: \n";
                    for (int i=0; i<n; i++)
                        cout << ar[i] << " ";
                    cout<<endl;
                    InterpolationSearch(ar,n,x);
                    break;
                case 4:
                cout<<"\nProgram Terminated\n"<<endl;
                    break;
                default: {
                    cout<<"Invalid Choice"<<endl;
                }
            }
        }
   return 0;
}
