//Assignment 1 Question 1

#include<iostream>
using namespace std;

int main() {
    int arr[100], n = 0, option;

    cout << "\n--MENU--\n";
    cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
    cout << "Enter option: ";
    cin >> option;

    while (option != 6) {
        if (option == 1) {
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }

        else if (option == 2) {
            if (n == 0) {
                cout << "Array is empty\n";
            } else {
                cout << "Array: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }

        else if (option == 3) {
            int pos, val;
            cout << "Enter position: ";
            cin >> pos;
            if (pos < 0 || pos > n) {
                cout << "Invalid position\n";
            } else {
                cout << "Enter value: ";
                cin >> val;
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = val;
                n++;
                cout << "Inserted\n";
            }
        }

        else if (option == 4) {
            int pos;
            if (n == 0) {
                cout << "Array is empty\n";
            } else {
                cout << "Enter position to delete: ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Invalid position\n";
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    cout << "Deleted\n";
                }
            }
        }

        else if (option == 5) {
            int key, found = 0;
            cout << "Enter value to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Found at index " << i << endl;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cout << "Not found\n";
            }
        }

        else {
            cout << "Invalid option\n";
        }

        cout << "\n--MENU--\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter option: ";
        cin >> option;
    }

    cout << "Exiting...\n";
    return 0;
}

