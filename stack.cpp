#include <bits/stdc++.h>

using namespace std;

template <typename Object>
class Stack{
    private:
        int top;
        int maxSize;
        vector<Object> arr;
    public:
        explicit Stack(const int &size): maxSize{size}, top{-1}{
            arr.reserve(maxSize);
        }

        bool isEmpty() const{
            if(top==-1)
                return true;
            return false;
        }

        bool isFull() const{
            if(top==maxSize-1)
                return true;
            return false;
        }

        const int length() const{
            return top+1;
        }

        void push_back(const Object &val){
            try{
                if(isFull()){
                    throw string("Stack Overflow");
                } else{
                    ++top;
                    arr[top] = val;
                    cout << "Value " << val << " inserted in stack" << endl;
                }
            } catch(string e){
                cout << "ERROR:: " << e;
            }
        }

        const Object pop(){
            try{
                if(isEmpty()){
                    throw string("Stack Underflow");
                } else{
                    Object val = arr[top];
                    top--;
                    cout << "Value " << val << " removed from stack" << endl;
                    return val;
                }
            } catch(string e){
                cout << "ERROR:: " << e;
            }
        }

        const Object peek() const{
            try{
                if(isEmpty()){
                    throw string("Stack Underflow");
                } else{
                    return arr[top];
                }
            } catch(string e){
                cout << "ERROR:: " << e;
            }
        }

        void display() const{
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
            } else{
                cout << "Displaying Stack: " << endl;
                for(int i=top; i>=0; --i)
                    cout << arr[i] << endl;
            }
            cout << endl;
        }
};


int main(){
    Stack<int> s1(5);
    int option, val;

    do{
        cout << "\n\n";
        cout << "What operation do you want to perform: " << endl
        << "Select option number. Enter 0 to exit. " << endl;

        cout << "1. Push back" << endl;
        cout << "2. pop" << endl;
        cout << "3. length" << endl;
        cout << "4. peek" << endl;
        cout << "5. print stack" << endl;
        cout << "6. clear screen" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        switch(option){
            case 1:
                cout << "Enter a value: ";
                cin >> val;
                s1.push_back(val);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                int stack_len;
                stack_len = s1.length();
                cout << "Size of the stack is " << stack_len << endl;
                break;
            case 4:
                val = s1.peek();
                cout << "Peek value is " << val;
                break;
            case 5:
                s1.display();
                break;
            case 6:
                system("clear");
                break;
            case 0:
                break;
            default:
                cout << "Please enter correct number" << endl;
        }
    } while(option != 0);

}
