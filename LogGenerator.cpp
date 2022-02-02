#include <iostream>
#include <algorithm>
#include <vector>
#include "LogGenerator.h"
#include <deque>
int main() {

	
	LogGenerator<BasicLogEntry,std::vector, SaveToFile> log1;
	BasicLogEntry log_entry1;
	log_entry1.message = "This is a log entry";
	log1.add(log_entry1);
	log1.output("filename.txt");

	
	LogGenerator<BasicLogEntry, std::deque, OutputToCout> log2;
	BasicLogEntry log_entry2;
	log_entry2.message = "Another log entry";
	log2.add(log_entry1);
	log2.output();
	
	

	
	return 0;
}