#pragma once
#include <variant>
#include <string>
#include <vector>

using namespace std;

typedef string Formula;
typedef variant<Formula, int, vector<int>> SelectionCount;

template <typename T> 
class Selector {
private:
	vector<T> currentList; //the current <T>s that we have
	vector<T> newList; //the <T>s that we can select from

	vector<string> hookIDs; //lv up, long rest, etc, etc

	//when you make a selection, what are the min and max selections you can make.
	SelectionCount minCount;
	SelectionCount maxCount;


public:
	class Builder {
	private:
		vector<T> _currentList;
		vector<T> _newList;
		vector<string> _hookIDs;
		SelectionCount _minCount;
		SelectionCount _maxCount;

	public:
		Builder() = default;
		Builder& currentList(const string& List) {this->_currentList = List; return *this;}
		Builder& newList(const string& newList) {this->_newList = newList; return *this;}
		Builder& hookIDs(const vector<string>& hookIDs) {this->_hookIDs = hookIDs; return *this;}
		Builder& minCount(const SelectionCount& minCount) {this->_minCount = minCount; return *this;}
		Builder& maxCount(const SelectionCount& maxCount) {this->_maxCount = maxCount; return *this;}
		Selector<T> build(){return Selector<T>(this);}
		friend class Selector<T>;
	};

private:
	Selector() = default;
	Selector<T>(Builder* builder) {
		this->currentList = builder->_currentList;
		this->newList = builder->_newList;
		this->hookIDs = builder->_hookIDs;
		this->minCount = builder->_minCount;
		this->maxCount = builder->_maxCount;
	}

public:
	const vector<T>& getCurrentList() const {return this->currentList;}
	const vector<T>& getNewList() const {return this->newList;}
	const vector<string>& getHookIDs() const {return this->hookIDs;}
	const SelectionCount& getMinCount() const {return this->minCount;}
	const SelectionCount& getMaxCount() const {return this->maxCount;}

	void Add();
	void Replace();

	~Selector();
};
