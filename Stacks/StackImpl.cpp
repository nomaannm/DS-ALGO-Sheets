//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  private:
    int arr[1000];
    int top;

  public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};


// } Driver Code Ends
// Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int topIndex;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
    void top();
    int size();
};
*/

void MyStack ::push(int x) {
    if(topIndex > 1000) cout << "Stack size exceeded!\n";
    topIndex += 1;
    arr[topIndex] = x ;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top == -1) return -1;
    int elem = 
}

void MyStack::top() const {
    if(topIndex == -1) cout << "Stack empty";
    cout << arr[topIndex] << "\n";
}

int MyStack::size {
      return topIndex + 1;
}



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Flush the newline character left by cin
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
    return 0;
}

// } Driver Code Ends
