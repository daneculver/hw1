#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#define ARRSIZE 10
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/////////////////////////////////////////////////////////
//START OF CODE

void ULListStr::pop_back() {
	//checks item for remaining element
	if(tail_->last == 1){
		//moves index and deletes previous
		tail_= tail_->prev;
		delete tail_->next;
		tail_->next = NULL;
	}
	//checks list for element
	else if(size_ == 1){
		delete tail_;
		tail_ = NULL;
		head_ = NULL;
	}
	//checks if list is empty
	else if(size_ == 0){
		return;
	}
	//else is more than 1 element in item
	else{
		tail_->last--;
	}
	size_--;
}
void ULListStr::pop_front() {
	//one element left in item
	if(head_->last == 1){
		//sets head and deletes previous index
		head_= head_->next;
		delete head_->prev;
		head_->prev = NULL;
	}
	//one element left in list
	else if(size_ == 1){
		//deletes index and sets head/tail to null
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	}
	//empty list
	else if(size_ == 0){
		return;
	}
	//more than one element left in item
	else{
		//moves head to the next index
		head_->first++;
	}
	size_--;
}
void ULListStr::push_back(const std::string& val) {
	//purpose adds a new value to back of list
	if(ARRSIZE == tail_->last){
		//creates an item list
		Item* list = new Item();
		tail_->next = list;
		list->prev = tail_;
		tail_ = list;
		//sets the value of the index
		list->val[0]=val;
		list->last++;
	}
	else if(empty()){
		//create an item list
		Item* list = new Item();
		//sets head and tail
		head_ = list, tail_ = list;
		//sets the value of the index
		list->val[0]=val;
		list->last++;
	}
	//checks that tail is not filled
	else if(tail_->last != ARRSIZE){
		tail_->val[tail_->last] = val;
		tail_->last++;
	}
	size_++;
}
void ULListStr::push_front(const std::string& val) {
	//conditional for max amount of elements in list
	if(head_->first == 0){
		/*creates a new item that will then link to the-
		-previous item adding the arraylist to the new item
		as shown in the video.
		*/
		Item* list = new Item();
		list->next = head_;
		head_->prev = list;
		head_ = list;
		list->first = (ARRSIZE + 1);
		list->last = ARRSIZE;
		list->val[ARRSIZE - 1] = val;
	}
	//no items are in the list
	else if(empty()){
		/* creates a new list and sets there head,
		tail, and values then increments the last index
		*/
		Item* list = new Item();
		head_ = list, tail_ = list;
		list->val[0] = val;
		list->last++;
	}
	//checks that head is not full but not empty
	else if(!empty() && (head_->first != 0)){
		//moves the list so that the first index will be the first value
		head_->val[head_->first-1] = val;
		head_->first--;
	}
	size_++;
}
std::string const & ULListStr::front() const{
	return head_->val[head_->first];
}
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
	if(loc < 0){
		return NULL;
	}
	size_t tempval = head_->first;
	Item* tempitem = head_;
	size_t i;
	//runs until original loc is equal to i
	for(i = 0; i < loc; i++){
		tempval++;
		if(tempitem->last == tempval){
			tempval = 0;
			tempitem = tempitem->next;
		}
	}
	return &tempitem->val[tempval];
}
//END OF CODE
/////////////////////////////////////////////////////////
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
