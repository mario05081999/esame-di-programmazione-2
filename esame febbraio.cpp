/******************************************************************************
Esame febbraio
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    Item* next;

public:
    Item() : next(nullptr) {}
    ~Item() {}

    Item* get_next() { return next; }
    void set_next(Item* n) { next = n; }

    virtual int score() = 0;
    virtual void show() =0;
};

class IntItem : public Item {
private:
    int data;
    Item* next;

public:
    IntItem(int val) : data(val) {}

    int get_data()  { return data; }
    void set_data(int val) { data = val; }
	~IntItem() {}

    int score() override { return data; }
    void show() override{/*non l'ho fatto causa tempo */}
};

class StringItem : public Item {
private:
    string data;
    Item* next;

public:
    StringItem(string& val) : data(val) {}

    string& get_data() { return data; }
    void set_data(string& val) { data = val; }
	~StringItem() {}

    int score() override { return data.length(); }
    void show() override{/*non l'ho fatto causa tempo */}
};

class MyStack {
private:
    Item* top;

public:
    MyStack() : top(nullptr) {}
    ~MyStack() {
        while (!isempty()) {
            pop();
        }
    }

    bool push(Item* item) {
        if (!top || item->score() > top->score()) {
            item->set_next(top);
            top = item;
            return true;
        }
        return false;
    }

    Item* pop() {
        if (!isempty()) {
            Item* temp = top;
            top = top->get_next();
            delete temp;
        }
    }//qui ho sbagliato perchè dovevo ritornare il puntatore

    void strong_push(Item* item) {
        while (top && item->score() <= top->score()) {
            pop();
        }

        if (!top || item->score() > top->score()) {
            item->set_next(top);
            top = item;
            
        }
    }

    bool isempty()  { return top == nullptr; }

    int top_score()  { return top->score() }
};

int main() {
    return 0;
}