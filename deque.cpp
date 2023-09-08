#include <iostream>
#include <deque>

void print(std::deque<int>& result);
int main() {
    std::deque<int> dq = {11,22,33,44,55,66,77};

    std::cout << "Initial deque" << std::endl;
    print(dq);
    
    //push
    dq.push_front(99);
    dq.push_back(100);
    print(dq);

    //pop
    dq.pop_front();
    print(dq);
    dq.pop_back();
    print(dq);

    //access using index
    for(int ix=0; ix<dq.size(); ix++) {
        std::cout << dq[ix] << ",";
    }
    return 0;
}

void print(std::deque<int>& result) {
    for(int x: result) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}