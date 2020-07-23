#include<bits/stdc++.h>
using namespace std;

struct rangeSet{
    set<int>values;
    int delta = 0;
    
    // returns the minimum from the set
    int get_min(){
        return (*values.begin()) + delta;
    }

    // updating all values
    int update_all(int x){
        delta += x;
    }

    // insert a new value
    int add(int x){
        values.insert(x - delta);
    }

    // removing an element
    void remove(int x){
        values.erase(x-delta);
    }

    // checking if value is present
    bool is_present(int x){
        return values.count(x-delta);
    }

    // size of container
    int size(){
        return values.size();
    }

    // display the container
    void display(){
        for(auto x: values)
            cout << x + delta << " ";
        cout << endl;
    }
};

int main(){


    // below is just the simulation to show how container works
    rangeSet myset;
    cout << "1: getmin\t2: update\n3: add\t4: remove\n5: present\t6:size\n7: display\n";
    while(true){
        int k, x;
        cin >> k;
        switch (k){
        case 1:
            cout << myset.get_min() << endl;
            break;
        case 2:
            cout << "enter inc value: ";
            cin >> x;
            myset.update_all(x);
            break;
        case 3:
            cout << "enter value to insert: ";
            cin >> x;
            myset.add(x);
            break;
        case 4:
            cout << "enter value to remove: ";
            cin >> x;
            myset.remove(x);
            break;
        case 5:
            cout << "enter value to check: ";
            cin >> x;
            cout << myset.is_present(x) << endl;
            break;
        case 6:
            cout << myset.size() << endl;
            break;
        case 7:
            myset.display();
            break;
        default:
            exit(0);
        }
    }

    return 0;
}