//Assignment 1 Question 5

#include<iostream>
using namespace std;

int main() 
{
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int arr[r][c]; 

    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    //row sum
    cout << "\nRow sums:\n";
    for (int i = 0; i < r; i++) 
	{
        int sum = 0;
        for (int j = 0; j < c; j++) 
		{
            sum += arr[i][j];
        }
        cout << "Row " << i << " = " << sum << endl;
    }

    //column sum
    cout << "\nColumn sums:\n";
    for (int j = 0; j < c; j++) 
	{
        int sum = 0;
        for (int i = 0; i < r; i++) 
		{
            sum += arr[i][j];
        }
        cout << "Col " << j << " = " << sum << endl;
    }

    return 0;}
