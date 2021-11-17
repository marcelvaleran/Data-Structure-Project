#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
int cnt = 1;

/* SHELL SORTING */

void printShellSort(int ar[], int step)
{
	for(int i = 0; i < SIZE; ++i) {
		if(((i + 1) % step) != 0)
			cout << setw(3) << ar[i];
		else
			cout << setw(3) << ar[i] << endl;
	}
	cout << endl;
}

void printInsertedShellSort(int ar[], int step)
{
	for(int i = 0; i < SIZE; ++i) {
        cout << setw(3) << ar[i] << " ";
	}
	cout << endl;
}

void ShellSort(int a[])
{
	int i, j;
	int step, temp, iteration = 0;
	step = (SIZE / 2) ;
	while(step) {
	    iteration++;
	    printShellSort(a, step);
		cout << "==>" << endl;
		for (i = step; i < SIZE; i++) {
			temp = a[i];
			j = i;
			while (j >= step && a[j - step] > temp) {
                cout<< a[j - step] <<" compare to " << temp <<endl;
                cout<<"Item Swapped to = " << temp <<", "<< a[j - step] <<endl<<endl;
				a[j] = a[j - step];
				j = j - step;

			}
			a[j] = temp;
		}
		printShellSort(a, step);
		cout << "\nIteration #" << iteration << endl;
		printShellSort(a, SIZE);
		cout << "----------------" << endl;

		step = step / 2;
	}
}

/* QUICK SORTING */

void swap(int a[], int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void printQuickSort(const int arr[])
{
    cout << endl;
    cout << "Iteration #" << cnt <<" : \n";
	for(int i=0;i < SIZE; i++) {
		cout << setw(3) << arr[i];
	}
	cout << endl;
}

void printResult(const int arr[])
{
    cout << endl;
	for(int i=0;i < SIZE; i++) {
		cout << setw(3) << arr[i] <<" ";
	}
	cout << endl;
}

void qsort(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;
        /* pivot selection */
	pivot = a[right];
        /* partition */
	while(left <= right) {

		while(a[left] < pivot){
        cout<<"  " << a[left] << " < " <<pivot <<"(left)"<<endl;
        left++;
		}

		while(right>0 && a[right] > pivot){
        cout<<"  " << a[right] << " > " <<pivot <<"(right)"<<endl;
        right--;
		}

		if(left <= right) {
            cout<<"  " <<"Item Swap : "<<a[left] <<", " <<a[right] <<endl;
			swap(a,left,right);
			left++; right--;
		}
	}
    cnt++;
	cout<<"  pivot = "<<pivot <<endl;
	printQuickSort(a);
	qsort(a,left_index,right);
	qsort(a,left,right_index);
}
int removeDuplicates(int arr[], int n)
{
    vector<int> v(arr, arr + n);
    vector<int>::iterator it;

    it = unique(v.begin(), v.end());

    v.resize(distance(v.begin(), it));

    cout << "\nChecked Elements From Duplication : \n";
    for (it = v.begin(); it != v.end(); ++it)
        cout <<"  " << *it << "";
        cout<<endl;
}

int main(void)
{cout<<"     Marcel Valeran \n";
 cout<<"       IS Class 2 \n";
 cout<<"      012201800029 \n";
 cout<<" 'SORTING NUMBER PROGRAM'\n";
 //cout<<"___________________________\n";

    int a[SIZE], choices, n = 10;

    while(choices !=3){
            cout<<"_________________________________________________________________________________________________________________\n";
            cout<<" \nYour Choices ? \n";
            cout<<" 1. Shell Sort"<<endl;
            cout<<" 2. Quick Sort"<<endl;
            cout<<" 3. Close The Program"<<endl;
            cout<<" Enter Your Choice => ";
            cin>>choices;
            cout<<endl;
            switch(choices){
                case 1:
                    cout<< " ' SHELL SORT ' \n\n";
                    cout<<"Insert 10 Array Elements : \n";
                        for(int i=0; i<SIZE; i++){
                            cin>> a[i];
                        }
                                cout << "\nInserted Array" <<endl;
                                printInsertedShellSort(a, SIZE);
                                cout<<"______________________________________________\n\n";
                                cout << "\nIteration #0\n";
                                printInsertedShellSort(a, SIZE);
                                cout << "\n----------------\n";
                                ShellSort(a);
                                cout<<"______________________________________________\n\n";
                                cout << "Shell Sorted Array :"  << endl;
                                printInsertedShellSort(a, SIZE);
                                removeDuplicates(a, n);
                    break;
                case 2:
                    cout<< " ' QUICK SORT ' \n\n";
                    cout<< " Insert 10 Array Elements : \n";
                        for(int i=0; i<SIZE; i++){
                            cin>> a[i];
                        }
                                cout<<"\n______________________________________________";
                                cout<< endl;

                                printQuickSort(a);
                                qsort(a,0,SIZE-1);
                                cout<<"\n______________________________________________\n";
                                cout<< "\nQuick Sorted Array : ";
                                printResult(a);
                                removeDuplicates(a, n);
                                cnt = 1;
                    break;
                case 3:
                    cout<<"Program Is Terminated\n";
                    break;
                default: {
                    cout<<"Invalid Choice"<<endl;
                    }
            }
        }
   return 0;
}
