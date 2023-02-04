#ifndef MATRIX_H
#  define MATRIX_H
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>
#include <numeric>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <shared_mutex>

using std::initializer_list;
using std::vector;
using std::lock_guard;
using std::ostream;
using std::ostringstream;
using std::shared_mutex;
using std::iostream;
using std::endl;


namespace mpcs51044 {
	template<typename T>
	class Stack {
	
	public:
		Stack() : data{} {}
		Stack(std::initializer_list<T> l) : data(l) {}

		T pop() {
			lock_guard guard(mtx);
			T result = data[data.size() - 1];
			data.pop_back();
			return result;
		}
		void push(T& ele) {
			lock_guard guard(mtx);
			data.push_back(ele);
		}
		void push(T ele) {
			lock_guard guard(mtx);
			data.push_back(ele);
		}
		void print() {
			lock_guard guard(mtx);
			//for (auto it = data.begin(); it != data.end(); ++it) { std::cout << *it <<", "; }
			for_each(data.begin(), data.end(), [](T ele) {std::cout << ele << ","; });
		}
	protected:
		vector<T> data;
		shared_mutex mtx;

	};

}
#endif