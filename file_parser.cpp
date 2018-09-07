#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>


int main(){

// stl containers
std::map<std::string, std::string> index;
std::pair<std::string, std::string> x;
std::vector<std::string> keys;

// file stream
std::ifstream file;
std::string line;
std::string f_name = "filename";
file.open(f_name);
if (file.is_open()){
    while (std::getline(file,line) ){
        // get the break points of the data
        std::size_t sub = line.find(",");
        std::size_t sub2 = line.find("\n");
        // insert the data into a map
        x.first = line.substr(0, sub);
        keys.push_back(line.substr(0, sub));
        x.second = line.substr(sub+1, sub2);
        index.insert(x);
    }
    file.close();
}
else{
    std::cout << "File could not be opned\n";
}

// output the contents of the map
std::for_each(keys.rbegin(), keys.rend(),
    [&index](std::string k){
        std::cout << index[k] << std::endl;
    });


    // store tabular data
    std::multimap<std::string, std::vector<std::string>> data_frame =   {{  "pluto", { "dog", "10", "male" } }};

    std::string file = "filename";
    
 return 0;   
}
