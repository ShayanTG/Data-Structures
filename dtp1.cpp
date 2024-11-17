#include <iostream>
using namespace std;

class dStruct {
private:
    static const int SIZE = 300;
    static int arr[SIZE];       
    static int count; 

public:

    static void insert(int index, int value) {
        if (index >= 0 && index < SIZE) {
            arr[index] = value;
            if (index >= count) count = index + 1; 
        } else {
            cout << "invalid index\n";
        }
    }

    static int deleteByValue(int value) {
        for (int i = 0; i < count; i++) {
            if (arr[i] == value) {
                for (int j = i; j < count - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                count--;
                return i;
            }
        }
        return -1; //not found
    }

    static void deleteByIndex(int index) {
        if (index >= 0 && index < count) {
            for (int i = index; i < count - 1; i++) {
                arr[i] = arr[i + 1];
            }
            count--;
        } else {
            cout << "invalid index\n";
        }
    }

    static void display() {
        for (int i = 0; i < count; i++) {
            cout << i << "->" << arr[i] << " ";
        }
        cout << endl;
    }

    static void append(int value) {
        if (count < SIZE) {
            arr[count++] = value;
        } else {
            cout << "array full\n";
        }
    }

    static void reverse() {
        for (int i = 0; i < count / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[count - i - 1];
            arr[count - i - 1] = temp;
        }
    }

    static int searchByValue(int value) {
        for (int i = 0; i < count; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1; //not found
    }
};

int dStruct::arr[dStruct::SIZE] = {0};
int dStruct::count = 0;

int main() {
    
    string method = "";
    while (true)
    {
        cout << "enter the method:\n";
        cin >> method;
        int index;
        int value;

        if (method == "insert")
        {
            cout << "enter the index and value:\n";
            cin >> index;
            cin >> value;
            dStruct::insert(index,value);
        } else if (method == "dValue"){
            cout << "enter the value:\n";
            cin >> value;
           dStruct::deleteByValue(value);
        } else if (method == "dIndex"){
            cout << "enter the value:\n";
            cin >> value;
           dStruct::deleteByIndex(value);
        } else if (method == "display"){
            dStruct::display();
        } else if (method == "append"){
            cout << "enter the value:\n";
            cin >> value;
            dStruct::append(value);
        } else if (method == "reverse"){
            dStruct::reverse();
        } else if (method == "search"){
            cout << "enter the value:\n";
            cin >> value;
            dStruct::searchByValue(value);
        } else { // exit
        cout << "operation done.";
        break;
        }
        
    }
    

    return 0;
}
