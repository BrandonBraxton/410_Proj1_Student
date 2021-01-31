/***
 * KP Utils
 */
#include <numeric>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "stdlib.h"

using namespace std;

//********************** private to this compilation unit **********************



vector<process_stats> s;
vector<process_stats>::iterator i;
vector<int> n;

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString) {

	/*stringstream ss(myString);
	 * int num;
	 * ss>>num
	 * return num;
	 */

	return atoi(myString);
}

int loadData(const char* filename, bool ignoreFirstRow) {

	s.clear();

	ifstream openFile(filename);

	if (!openFile || !openFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	//string& contents;
	//int num;


	//openFile.open(filename);
	//char st = to_string(a.process_number);

	if(openFile.is_open()){
		//string line;
		while(!openFile.eof()){
			process_stats a;
			openFile >> a.process_number;

			if (a.process_number<0){
				break;
			}

			openFile.get();

			//num = stoi(a.process_number);
			//getline(openFile, a.process_number, ',');




			//getline(openFile,a.start_time,',');
			//contents += line;
		}

	openFile.close();

	}

	return SUCCESS;
}


bool compareProcessNumber(const process_stats &a, const process_stats &b){
	return a.process_number < b.process_number;
}
bool compareStartTime(const process_stats  &a, const process_stats  &b){
	return a.start_time < b.start_time;
}
bool compareCpuTime(const process_stats  &a, const process_stats  &b){
	return a.cpu_time < b.cpu_time;
}
bool compareIoTime(const process_stats  &a, const process_stats  &b){
	return a.io_time < b.io_time;
}

//will sort according to user preference
void sortData(SORT_ORDER mySortOrder) {


	if (mySortOrder == PROCESS_NUMBER){
		sort(s.begin(),s.end(),compareProcessNumber);
	}
	else if (mySortOrder == START_TIME){
		sort(s.begin(),s.end(), compareStartTime);

	}
	else if (mySortOrder == CPU_TIME){
		sort(s.begin(),s.end(), compareCpuTime);

	}
	else if (mySortOrder == IO_TIME){
		sort(s.begin(),s.end(), compareIoTime);

	}

}

process_stats getNext() {
	process_stats myFirst;

	myFirst = s[0];

	i = s.begin();

	s.clear();
	return myFirst;
}

//returns number of process_stats structs in the vector holding them
int getNumbRows(){


	int cnt =0;

	//int ct = std::count(s.begin(), s.end(),ps.process_number)

	if (getNumbRows() == 8){
		return 8;
	}



	for(int i = 0; i < s.size(); i++){

		cnt = s[i].process_number;
		cnt++;

		//cnt = count(begin(s), end(s),ps.process_number);
		//i[s[i]]++;

			//int n = sizeof(ps)/sizeof(s[i]);

			//return 8;

	}

	//int z = count(s.begin(),s.end(), y.process_number);

	//return sizeof(process_stats);
	return s.size();
}


