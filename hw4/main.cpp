#include <iostream>
#include <cstdlib>
#include "queue.h"
#include "stack.h"

struct Data{
    Queue q;
    Stack s;
    int amount;
    clock_t q_time;
    clock_t s_time;
};

void stress_test(Data & d){
    // destructured the struct;
    // auto[q, s, amount, q_time, s_time] = data;

    srand(time(0));
    bool random_bool;

    int push = 0;
    int remove = 0;
    d.q_time = clock();
    for(int i = 0; i < d.amount; i++){
        random_bool = remove >= d.amount * .49 || rand() % 100 < 50;
        if(random_bool){
            d.q.insert(i);
            push++;
        }
        else{
            d.q.remove();
            remove++;
        }
    }
    d.q_time = clock() - d.q_time;


    push = 0;
    int pop = 0;
    d.s_time = clock();
    for(int i = 0; i < d.amount; i++){
        random_bool = pop >= d.amount * .49 || rand() % 100 < 50;
        if(random_bool){
            d.s.push(i);
            push++;
        }
        else{
            d.s.pop();
            pop++;
        }
    }
    d.s_time = clock() - d.s_time;

    cout << "Stack run time: " << (double)d.s_time / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Queue run time: " << (double)d.q_time / CLOCKS_PER_SEC << " seconds" << endl << endl;
}


int main() {
    int arr[4] = {1000,10000,100000, 10000000};
    Data data;

    for(int i = 0; i < 4; i++){
        int curr_amount = arr[i];
        data.amount = curr_amount;
        stress_test(data);
    }

    return 0;
}
