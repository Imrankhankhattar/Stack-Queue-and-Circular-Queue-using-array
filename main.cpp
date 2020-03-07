

#include <iostream>
using namespace std;

class stack_array
{
private:
    int head=-1;
    int tail=-1;
    int size_array=4;
public:
    int Array[];
    void push_stack(int x)
    {
        if(size_array-1==tail)
        {
            cout<<"Array is full.............."<<endl;
            return;
        }
        if(head==-1&&tail==-1)
        {
            head++;
            tail++;
            Array[tail]=x;
            return;
        }
        tail++;
        Array[tail]=x;
    }
    void pop_stack()
    {
        if(tail==-1)
        {
            cout<<"NOTHING to pop..."<<endl;
            return;
        }
        Array[tail]=0;
        tail--;
    }
    void Display()
    {
        if(head==-1&&tail==-1)
        {
            cout<<"Stack is empty....."<<endl;
            return;
        }
        int i;
        for(i=0; i<size_array; i++)
        {
            cout<<Array[i]<<endl;
        }
    }
    void clear_stack()
    {
        head=-1;
        tail=-1;
    }
    void top_stack()
    {
        cout<<"TOP of STACK is: "<<Array[0]<<endl;
    }
};
class Queue
{
private:
    int head=-1;
    int tail=-1;
    int size_array=4;
public:
    int Array[];
    void Display()
    {

        if(head==-1&&tail==-1)
        {
            cout<<"Stack is empty....."<<endl;
            return;
        }
        int i;
        for(i=0; i<size_array; i++)
        {
            cout<<Array[i]<<endl;
        }
    }
    void swep()
    {
        int k=0,i;
        for(i=1; i<=size_array; i++)
        {
            Array[k]=Array[i];
            ++k;
        }
        Array[i]=0;
    }
    void enqueu(int x)
    {
        if(tail==size_array)
        {
            cout<<"Array is full..."<<endl;
            return;
        }
        if(head==-1&&tail==-1)
        {
            tail++;
            head++;
            Array[tail]=x;
            return;
        }

        tail++;
        Array[tail]=x;

    }
    void dequeue()
    {
        if(tail==-1)
        {
            cout<<"QUEUE IS ALREADY EMPTY"<<endl;
            return;
        }

        Array[head]=0;
        swep();
        tail--;
    }
    void clear_queue()
    {
        head=-1;
        tail=-1;
    }
    void top_queue()
    {
        cout<<"TOP of QUEUE is: "<<Array[0]<<endl;
    }
};
class Circular_queue
{
    int head=-1;
    int tail=-1;
    int size_array=4;
public:
    int Array[4]= {-1,-1,-1,-1};
    int Check()
    {
        int i,z=0;
        for(i=0;i<size_array;i++)
    {
        if(Array[i]==-1)
        {
            z++;
        }

    }

          return z;
    }
    void enqueue(int x)
    {   int check;
      check=Check();
      if(check==0)
      {
          cout<<"ÄRRAY IS FULL..."<<endl;
          return;
      }
        if(head==-1&&tail==-1)
        {
            head++;
            tail++;
            Array[tail]=x;
            return;
        }

        tail++;
        tail=tail%size_array;
        Array[tail]=x;
    }

    void Display()
    {
        if(head>tail)
        {
            int i;
            for(i=head;i<=size_array-1;i++)
            {
                if(Array[i]==-1)
                {
                    continue;
                }
                cout<<"|"<< Array[i]<<"| ";
            }
            for(i=0; i<head; i++)
            {
                if(Array[i]==-1)
                {
                    continue;
                }
                cout<<"|"<<Array[i]<<"| ";
            }
            return;
        }
        int i;
        for(i=0;i<size_array; i++)
        {

            if(Array[i]==-1)
            {
                continue;
            }
            cout<<"|"<<Array[i]<<"|  ";

        }
    }
    void dequeue()
    {
        if(tail==-1)
        {
            cout<<"QUEUE IS ALREADY EMPTY"<<endl;
            return;
        }
        head=head%size_array;
        if(head==tail+1)
        {
            cout<<"Nothing to dequeue"<<endl<<endl;
        }
        Array[head]=-1;
        head++;
    }
    void size_of_array()
    {   int z=size_array,i;
        for(i=0;i<size_array;i++)
        {
            if(Array[i]==-1)
            {
                z--;
            }

        }
        cout<<"Size of Array is: "<<z<<endl;
    }
};

int main()
{
    Circular_queue obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(4);
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
            obj.size_of_array();

    /*
    obj.enqueue(100);
    obj.enqueue(100);
    obj.enqueue(100);
    obj.enqueue(100);
    obj.enqueue(30);
    obj.enqueue(1);
    obj.enqueue(13);
    obj.enqueue(10);*/
    obj.Display();


    return 0;
}
