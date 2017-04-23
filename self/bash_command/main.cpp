#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>

using namespace std;

string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}

void get_filenames(string file, vector<string>& filenames) {
	string filename = "";
	for (unsigned int i = file.length() - 1; i > 0; i--) {
		if (file[i] == '\n') {
			filename = file.substr(i + 1, file.length() - 1);
			if (filename.length() > 0) {
				filenames.push_back(filename);
				filename = "";
				file.erase(file.begin()+i, file.end());
			}
		}
	}
	filename = file.substr(0);
	filenames.push_back(filename);
}

int main(int argc, char* argv[]) {
	string result = exec("find *.json");
	vector<string> filenames;
	get_filenames(result, filenames);
	for (int i = 0; i < filenames.size(); i++) {
		cout << "filenames No" << i << ": " << filenames[i] << endl;
	}

	return 0;
}


