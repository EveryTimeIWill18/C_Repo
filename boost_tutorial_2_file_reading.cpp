#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<boost/filesystem.hpp>
//using namespace boost::filesystem;

int main() {

	// get the current path
	boost::filesystem::path current = boost::filesystem::current_path();

	std::cout << "CURRENT DIRECTORY: " << current << "\n";


	// crate a path
	boost::filesystem::path p1{ "C:\\Users\\murpwil\\Downloads" };
	boost::filesystem::path project_path{ "C:\\Users\\murpwil\\source\\repos\\boost_example\\boost_example" };
	
	// full path to Amazon reviews data set
	boost::filesystem::path data_set{ "C:\\Users\\murpwil\\source\\repos\\boost_example\\boost_example\\data_set\\amazon_reviews_sample.csv" };
	// get last write time of data set
	std::time_t t = boost::filesystem::last_write_time(data_set);
	
	// file status
	boost::filesystem::file_status data_set_status = boost::filesystem::status(data_set);

	// Create a fstream
	std::fstream data_set_stream;
	data_set_stream.open(data_set.string(), std::ios::out | std::ios::in);
  // create a vector to store the lines of the file
	std::vector<std::string> lines;
	// create a string to store each line of the file
  std::string line;
  
  // iterate through the file and store each line in the string vector
	while (std::getline(data_set_stream, line)) {
		/*std::cout << "LINE: " << line << "\n";*/
		lines.push_back(line);
	}
  // close the file
	data_set_stream.close();

  // print out the lines of the vector
	for (const auto& i : lines) {
		std::cout << "LINE: " << i << "\n";
	}




	// file size
	boost::system::error_code ec;
	boost::uintmax_t data_set_filesize = boost::filesystem::file_size(data_set, ec);
	if (!ec) {
		std::cout << "FILESIZE: " << data_set_filesize << "\n";
	}
	else { std::cout << "ERROR CODE: " << ec << "\n"; }

	// get file information
	std::cout << "IS DIR? : " << boost::filesystem::is_directory(data_set_status) << "\n"; // 0=>false : 1=>true
	std::cout << "FILE EXISTS?: " << boost::filesystem::exists(data_set_status) << "\n";
	if (boost::filesystem::exists(data_set_status)) {
		std::cout << "LAST WRTIE TIME: " << t << "\n";
	}

	// get path information
	std::cout << "PATH ROOT NAME: " << p1.root_name() << "\n";
	std::cout << "PATH ROOT DIRECTORY: " << p1.root_directory() << "\n";
	std::cout << "ROOT PATH: " << p1.root_path() << "\n";
	std::cout << "RELATIVE PATH: " << p1.relative_path( ) << "\n";
	std::cout << "PARENT PATH: " << p1.parent_path() << "\n";
	std::cout << "FILENAME: " << p1.filename() << "\n";


	// File information
	std::cout << "STEM: " << data_set.stem() << "\n"; // returns the file name w/o extension
	std::cout << "EXTENSION: " << data_set.extension() << "\n"; // returns the file's extension type (i.e. .csv)

	// Open the data set for reading
	






	// Iterate over components of a path
	for (const boost::filesystem::path& pp : p1) {
		std::cout << "COMPONENT: " << pp << "\n";
	}

	// Using the '/=' operator on paths
	boost::filesystem::path c_path{ "C:\\" };
	c_path /= "Windows\\System";  // use the /= operator to build the file path
	std::cout << "C_PATH := " << c_path.string() << "\n";

	



	// create a directory itertor
	/*boost::filesystem::directory_iterator it{ p1 };
	while (it != boost::filesystem::directory_iterator{}) {

		std::cout << "CURRENT FILE: " << *it++ << "\n";
	}*/
	



	std::cout << "END BOOST\n";


	return 0;
} 
