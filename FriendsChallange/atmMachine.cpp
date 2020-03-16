#include<bits/stdc++.h>
#define deb(x) {cout << #x << " " << x << endl ;}
using namespace std ;

// 10 1300 10 10 10 10

void learningNotes(int N, int ammount, int hunavaible, int twoavailble, int fyvavailable, int thouavailable) {
    int tmpAmmount = ammount ;
    int thouavailable2 = thouavailable ;
    int twoavailble2 = twoavailble ;
    if (N > 99) {cerr << "error" << endl ;}
    
    int totalAmmount = hunavaible*100 + twoavailble*200 + fyvavailable*500 + thouavailable*1000 ;

    while(totalAmmount > ammount and thouavailable != 0) {
        totalAmmount -= 1000 ;thouavailable--;
    }
    if (totalAmmount < ammount) {totalAmmount += 1000; thouavailable++;}

    while(totalAmmount > ammount and fyvavailable != 0) {
        totalAmmount -= 500 ; fyvavailable--;
    }if (totalAmmount < ammount) { totalAmmount += 500; fyvavailable++;}

    while(totalAmmount > ammount and twoavailble != 0) {
        totalAmmount -= 200 ;twoavailble-- ;
    }if (totalAmmount < ammount) { totalAmmount += 200; twoavailble++;}

    while(totalAmmount > ammount and hunavaible != 0)  {
        totalAmmount -= 100 ;hunavaible-- ;
    }
    if (totalAmmount < ammount) { totalAmmount += 100; hunavaible++;}

    int totalNOtes = hunavaible + twoavailble + fyvavailable + thouavailable ;

    if(totalNOtes > N) {
        while(totalNOtes > N  and hunavaible < thouavailable2) {
            fyvavailable -= 2 ;
            thouavailable2 += 1 ;
            totalNOtes--;
        }
        while(totalNOtes > N  and twoavailble < twoavailble2) {
            hunavaible -= 2 ;
            twoavailble += 1 ;
            totalNOtes--;
        }
    }

    deb(totalAmmount) ;
    deb(ammount) ;
    deb(totalNOtes) ;
}



int main(int argc, char const *argv[]){
    learningNotes(10, 1300, 10, 10, 10, 10) ;
    return 0;
}
