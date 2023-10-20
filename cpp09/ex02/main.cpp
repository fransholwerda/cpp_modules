#include <iostream>
#include <chrono>
#include <thread>

int main(void)
{
	// Use high resolution clock to calculate the duration of the program

	// Sleep for 2 seconds
	std::cout << "Sleeping for 2 seconds..." << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Elapsed time: " << elapsed.count() << "s" << std::endl;
	return (EXIT_SUCCESS);
}
