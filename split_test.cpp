#include <iostream>
#include "split.h"
using namespace std;
int main(){
	Node tail(66,nullptr);
	Node Fourth(12,&tail);
	Node Third(8,&Fourth);
	Node Second(45,&Third);
	Node head(22,&Second);
	Node *in = &head;
	Node *evens_list = nullptr;
	Node *odds_list = nullptr;
	Node array [5] = {head, Second, Third, Fourth, tail};
	cout << "Default List: ";
	for(int t = 0; t < 5; t++){
		cout << array[t].value << " ";
	}
	cout << endl;
	split(in, odds_list, evens_list);
	cout <<"Even List: ";
	while(evens_list != nullptr){
		cout << evens_list -> value << " ";
		evens_list = evens_list -> next;
	}
	cout << endl;
	cout << "Odd List: ";
	while(odds_list != nullptr){
		cout << odds_list -> value << " ";
		odds_list = odds_list -> next;
	}
	cout << endl;
	if(in == nullptr){
		cout << "Empty List." << endl;
	}
	return 0;
}