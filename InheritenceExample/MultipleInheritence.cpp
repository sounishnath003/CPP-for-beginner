#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

class Name
{
protected:
    string name ;
    string roll ;
public:
    Name() {};
};

class Address
{
protected:
    string address;
public:
    Address() {};
};

class Information : public Name, Address
{
private:
    map<string, string> stored;
    string key;
public:
    Information() {
        cout << "No information of student gathered" << endl;
    }
    Information(string &&key, string &&name, string &&roll, string &&address){
        this->key = key;
        this->name = name;
        this->roll = roll;
        this->address = address;

    }

    void print(map<string, string> &m){
        for (auto &&i : m)
        {
            cout << i.first << "  =>  " << i.second << endl;
        }
        cout << endl;
        
    }

    void display(){
        stored["key"] = key;
        stored["name"] = name;
        stored["roll"] = roll;
        stored["address"] = address;
        
        print(stored);
    }

};


int main(int argc, char const *argv[])
{
    Information info("001", "Sounish Nath", "56", "Ghatal IN");
    Information info2("00112", "Sudip Nath", "506", "Kolkata IN");
    Information info3("012", "Mainisha Nath", "182", "Mumbai IN");
    
    info.display();   
    info2.display();   
    info3.display();   

    return 0;
}

