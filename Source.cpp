#include <iostream>
#include <vector>



void print_count(int, int);
template <class T>
void print_list(std::vector <T> L);
int main() {

	int start = 0;
	int stop = 10;

	for (int i = start; i < stop; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	print_count(start, stop);

	std::vector<int> li = { 0,1,2,3,4,5,6,8,9,10, };

	print_list<int>(li);

	return 0;
}

void print_count(int start_at, int stop_at) {
	if (start_at != stop_at) {
		std::cout << start_at << " ";
		print_count(start_at + 1, stop_at);
	}
	
}
template <class T>
void print_list(std::vector <T> L) {
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << L[i] << " ";
	}
	std::cout << std::endl;

}
template<class T>
void print_list_rec(/*?,?*/) {

}