#pragma once

//-------------------------------------------------------------Random number Generation

class Rand_Num_Gen {
public:
	Rand_Num_Gen();
	int randomGenerator(int lower_limit, int upper_limit);
private:
	std::uniform_int_distribution<int> dist;
	std::mt19937_64 the_generator;
	std::random_device ran_dev;
};

//----------------------------------------------------------------Measure time


class Time_Measure {
private:
	std::vector<std::chrono::high_resolution_clock::time_point> time_table;
public:
	void now();		//Logs the time when it is called
	void print(int step);	//Prints on the screen the difference between measurements for every <step> steps, Ex: step=2, 1-0,3-2,4-3,etc; Step=3: 2-0,5-3,8-5, etc;
	void print(int a, int b);	//Prints on the screen the difference for 2 specific time point logs; bigger-smaller
	int get_size();
};

//---------------------------------------------------------------Thread-safe queue

template<typename T>
class Thread_Safe_Queue {
private:
	std::deque<T> queue;
	std::mutex queue_mutex;
	std::condition_variable condition;
public:
	void push_back(T&& data);
	T pop_back();
};
