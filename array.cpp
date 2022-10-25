
#include<iostream>
using namespace std;
class Array 
{
    private:
    int size;
    int length;
    int *items;

    public:
    Array(int arr_size)
    {
        size = arr_size;
        length = 0;
        items = new int [size];
    }
    void fill ()
    {
        int num_of_items;
        cout<< "How many items you want to add ? \n";
        cin>>num_of_items;
        if ( num_of_items > size)
        {
            cout<<" The number of items excced the limit \n";
            return;
        }
        else
        {
            for (int i = 0; i < num_of_items; i++)
            {
                cout<<"Enter the ( "<<i<< " ) item :  ";
                cin>>items[i];
                length++;
            }
            
        }
    }
    void Display()
    {
        cout<<" Array items :  \t";
        for (int i = 0; i < length; i++)
        {
            cout<<items[i] << "\t";
            
        }
         cout<<endl;
         
    }
    int Getsize()
    {
        return size;
    }
    int Getlength()
    {
        return length;
    }
    int search (int key)
    {
        int index = -1 ;
        for (int i = 0 ; i < length ; i++)
        {
            if(items[i] == key )
            {
            index = i;
            break;
            }
        }
        return index;
    }
    void insert(int index , int newitem)
    {
        if(index >= 0 && index < size)
        {
            for(int i = length;i > index ; i--)
            {
                items[i]= items[i-1];
            }
         items[index]= newitem ;
         length++;
        }
        else
        {
            cout<<"Index out of range \n";
        }
    }
    void remove (int index)
    {
        if(index >=0 && index < size)
        {
            for(int i = index ; i < length - 1 ; i++)
            {
                items[i] = items[i + 1];
                length--;
            }
        }
        else
        {
            cout<<"index out of array range !! ";
        }
    }
};
int main()
{
    cout<<"Hello to our array generator . \n";
    int arraysize;
    cout<<" Please enter array size ? \n";
    cin>>arraysize;
    Array myarray(arraysize);
    myarray.fill();
    myarray.Display();
    cout<<"The length of the array is "<<myarray.Getlength()<< " and the size is "<<myarray.Getsize()<<"\n";
    cout<<"What is the operation you want to do (insert - delete - search ) ? \n";
    string operation = "null"; 
    cin>> operation;
    if(operation == "search")
    {
        cout<<"Enter the value to search for ? \n";
        int key;
        cin >> key;
        int index = myarray.search(key);
        if(index == -1)
        {
            cout<<" Item not found !!";
        }
        else
        {
            cout<<" The item is found in " <<index<< "tr ";
        }
        cout<<"The length of the array is "<<myarray.Getlength()<< " and the size is "<<myarray.Getsize()<<"\n";

    }
    else if (operation == "insert")
    {
        cout<<"What is value you want to add ? \n";
        int newvalue = 0;
        cin>>newvalue;
        cout<<" where you want to add this value ? \n";
        int index = 0 ;
        cin>>index;
        myarray.insert(index,newvalue);
        myarray.Display();
        cout<<"The length of the array is "<<myarray.Getlength()<< " and the size is "<<myarray.Getsize()<<"\n";
    }
    else if (operation == "delete")
    {
        cout<<"What the index of the item you want to delet ? \n";
        int index = 0;
        cin>>index;
        myarray.remove(index);
        myarray.Display();
        cout<<"The length of the array is "<<myarray.Getlength()<< " and the size is "<<myarray.Getsize()<<"\n";

    }
    
}