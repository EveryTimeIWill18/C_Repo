#include<iostream>
#include<string>
#include<boost/filesystem.hpp>
//using namespace boost::filesystem;

int main() {

	// get the current path
	boost::filesystem::path current = boost::filesystem::current_path();

	std::cout << "CURRENT DIRECTORY: " << current << "\n";


	// crate a path: make sure to use '//' in path names
	boost::filesystem::path p1{ "C:\\Users\\murpwil\\Downloads" };
	
	// create a directory itertor and print out each file in the path
	boost::filesystem::directory_iterator it{ p1 };
	while (it != boost::filesystem::directory_iterator{}) {
		std::cout << *it++ << "\n";
	}
	


	return 0;
} 
