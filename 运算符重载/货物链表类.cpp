//
//  货物链表类.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/20.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"

using namespace std;

class Goods
{
public:
    Goods(int w)
    {
        weight = w;
        total_Weight += w;
    }
    ~Goods(){}
    static int TotalWeight()
    {
        return total_Weight;
    }
    Goods *next;
protected:
private:
    int weight;
    static int total_Weight;
};

int Goods::total_Weight = 0;

void purchase(Goods * &f, Goods * &r, int w)
{
    Goods *p = new Goods(w);
    p->next = NULL;
    if (f == NULL) {
        f = r = p;
    }
    else{
        r->next = p;
        r = r->next;
    }
}

void sale(Goods * &f, Goods * &r)
{
    if (f == NULL) {
        cout << "No any goods!\n";
        return;
    }
    Goods *q = f;
    f = f->next;
    delete q;
    cout << "saled.\n";
}

int main()
{
    Goods * front = NULL, * rear = NULL;
    int w, choice;
    
    do
    {
        
        cout << "Please choice:\n";
        cout << "Key in 1 is purchase, \nKey int 2 is sale, \nKey in 0 is over.\n";
        cin >> choice;
        switch (choice) {
            case 1:
            {
                cout << "Input weight: ";
                cin >> w;
                purchase(front, rear, w);
                break;
            }
            case 2:
            {
                sale(front, rear);
                break;
            }
            case 0:
            {
                break;
            }
        }
        cout << "Now total weight is: " << Goods::TotalWeight() << endl;
    }while (choice);
    
    
    return 0;
}
