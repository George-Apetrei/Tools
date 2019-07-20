#include <chrono>
#include <random>
#include <vector>
#include <iostream>

//-------------------------------------------------------------Random number Generation
//Class to hold all elements of the random generator
class Rand_Num_Gen {
public:
	Rand_Num_Gen();
	int randomGenerator(int lower_limit, int upper_limit);
private:
	std::uniform_int_distribution<int> dist;
	std::mt19937_64 the_generator;
	std::random_device ran_dev;
};

//Constructor for Rand_Num_Gen to create a seed for random generation when the function object is created
Rand_Num_Gen::Rand_Num_Gen() {
	the_generator.seed(ran_dev());
}

//The actual random generation function
int Rand_Num_Gen::randomGenerator(int lower_limit, int upper_limit) {
	std::uniform_int_distribution<int>::param_type parameters(lower_limit, upper_limit);
	dist.param(parameters);
	return dist(the_generator);
}
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



void Time_Measure::now()		
{
	time_table.push_back(std::chrono::high_resolution_clock::now());
}

void Time_Measure::print(int step) {
	if (step <= 1) {
		std::cout << "Step is smaller or equal to 1!\n";
		return;
	}
	if (step > time_table.size()) {
		std::cout << "Step is bigger than size of recorded time points array!\n";
		return;
	}
	if (time_table.size() % step != 0) {
		std::cout << "Not all pairs are displayed!\n";
	}
	std::cout << "Numbers: " << time_table.size() << "\n";
		for (int i = 0; i < (time_table.size() / step); ++i) {
			std::cout << "Pair " << (i*step) << " - " << step * (1 + i) - 1 << ": " << std::chrono::duration_cast<std::chrono::microseconds>(time_table[step*(1 + i) - 1] - time_table[(i*step)]).count() << std::endl;
		}
	
}

void Time_Measure::print(int a, int b)
{
	if (a<0 || a>time_table.size() || b<0 || b>time_table.size()) {
		std::cout << "Invalid request!\n";
		return;
	}
	if (a>b) {
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(time_table[a] - time_table[b]).count() << std::endl;
	}
	else {
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(time_table[b] - time_table[a]).count() << std::endl;
	}

}

int Time_Measure::get_size()
{
	return time_table.size();
}

int main()
{

	Time_Measure n;
	
	std::vector<int> m;
	n.now();
		for (int i = 0; i < 100000; ++i) {
			m.push_back(i);
	}
		n.now();
		n.print(2);
		n.print(0, n.get_size() - 1);
}

