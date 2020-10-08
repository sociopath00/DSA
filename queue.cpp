#include <bits/stdc++.h>

using namespace std;

template <typename Object>
class Queue{
    private:
        int front;
        int rear;
        int maxSize;
        vector<Object> arr;

    public:
        explicit Queue(int size=0): maxSize{size}, front{-1}, rear{-1}{
            arr.reserve(maxSize);                // set capacity of Queue to maxSize
        }

        bool isEmpty() const{
            if(front==-1 && rear==-1)
                return true;
            return false;
        }

        bool isFull() const{
            if((rear-front+1) == maxSize)
                return true;
            return false;
        }

        const int length() const{
            if(isEmpty())
                return 0;
            return (rear-front+1);
        }

        void enqueue(const Object &val){
            try{
                if(isFull()){
                    throw string("Stack Overflow");
                } else if(isEmpty()){
                    ++front;
                    ++rear;
                    arr[rear] = val;
                    cout << "Value " << val << " inserted" << endl;
                } else{
                    ++rear;
                    arr[rear] = val;
                    cout << "Value " << val << " inserted" << endl;
                }
            } catch(string e){
                cout << "ERROR:: " << e << endl;
            }
        }

        const Object dequeue(){
            try{
                if(isEmpty()){
                    throw string("Stack Underflow");
                } else{
                    Object val;
                    val = arr[front];
                    ++front;
                    cout << "Value " << val << " removed" << endl;
                    return val;
                }
            } catch(string e){
                cout << "ERROR:: " << e << endl;
            }
        }

        const Object getFront() const{
            try{
                if(isEmpty()){
                    throw string("Stack Underflow");
                } else{
                    Object val;
                    val = arr[front];
                    return val;
                }
            } catch(string e){
                cout << "ERROR:: " << e << endl;
            }
        }

        void display() const{
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
            } else{

                cout << endl << "Displaying Queue: " << endl;
                for(int i=rear; i>=front; --i)
                    cout << arr[i] << endl;
            }
        }

};

int main(){
    Queue<int> s1(5);
    int option, val;

    do{
        cout << "\n\n";
        cout << "What operation do you want to perform: " << endl
        << "Select option number. Enter 0 to exit. " << endl;

        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Length" << endl;
        cout << "4. Get Front" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        switch(option){
            case 1:
                cout << "Enter a value: ";
                cin >> val;
                s1.enqueue(val);
                break;
            case 2:
                s1.dequeue();
                break;
            case 3:
                int stack_len;
                stack_len = s1.length();
                cout << "Size of the queue is " << stack_len << endl;
                break;
            case 4:
                val = s1.getFront();
                cout << "Front value is " << val;
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
