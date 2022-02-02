#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

// a baisic log entry
struct BasicLogEntry {
	std::string message;
};

 ///  I just cant sad
/*
// for sacing to a file
template <template<class,class> class T, class B>
class SaveToFile {
public:
	void output(std::string filename,T<B,std::allocator<B>> &data) {
		std::ofstream myfile(filename + ".txt");
		if (myfile.is_open()) {
			myfile << data.at(0).message;
		}
	}
};

// for out puting
template <class T, class B>
class OutputToCout {
public: 
	void output(T& t) { std::cout << t.message; };
};
*/

// for sacing to a file
template <class T>
class SaveToFile {
public:
	void output(std::string filename, T &data) {
		std::ofstream myfile(filename + ".txt");
		if (myfile.is_open()) {
			myfile << data.message;
		}
	}
};

// for out puting
template <class T>
class OutputToCout {
public:
	void output(T& t) { std::cout << t.message; };
};


// Non Specialised Class
template <class Type, template <class, class> class Storage, template <class> class File_Managment_Policy >
class LogGenerator : public File_Managment_Policy<Type> {
public:
	Storage<Type, std::allocator<Type>> data;
	void add(Type newobject) { data.push_back(newobject); };

};
 
// Specialised for Saving
template <class Type, template <class, class> class Storage>
class LogGenerator<Type,Storage,SaveToFile> : public SaveToFile<Type> {
public:
	Storage<Type, std::allocator<Type>> data;
	void add(Type newobject) { data.push_back(newobject); };

	void output(std::string filename) { SaveToFile<Type>::output(filename, data.at(0)); };
};

// Specialised for Outputing
template <class Type, template <class, class> class Storage>
class LogGenerator<Type, Storage, OutputToCout> : public OutputToCout<Type> {
public:
	Storage<Type, std::allocator<Type>> data;
	void add(Type newobject) { data.push_back(newobject); };

	void output() { OutputToCout<Type>::output(data.at(0));}
};
