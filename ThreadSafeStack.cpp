//Compile with ISO C++20 Standards/std:c++20

#include "ThreadSafeStack.h"
#include<iostream>
#include<shared_mutex>
#include<algorithm>

using namespace std;
using namespace mpcs51044;

int main(){
	Stack<int> stack = {1, 2, 3, 4};
	stack.push(5);
	stack.push(7);
	stack.pop();
	stack.print();
	return 0;
}