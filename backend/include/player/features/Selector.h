#pragma once
#include <variant>
#include <string>
#include <vector>
#include "Ability.h"
#include "TraitModification.h"
#include "../../serdes/JsonDeserializer.h"
#include "../../serdes/JsonSerializer.h"
#include "../../Utils.h"

using namespace std;

typedef string Formula;

template <typename T> 
class Selector {
private:
	vector<T> currentList; //the current <T>s that we have
	vector<T> newList; //the <T>s that we can select from

	vector<string> hookIDs; //lv up, long rest, etc, etc

	//when you make a selection, what are the min and max selections you can make.
	Formula minCount;
	Formula maxCount;


public:
	inline static const string SRC_DIR = "data/resources/features/selectors/";
	class Builder {
	private:
		vector<T> _currentList;
		vector<T> _newList;
		vector<string> _hookIDs;
		Formula _minCount;
		Formula _maxCount;

	public:
		Builder() = default;
		Builder& currentList(const vector<T>& List) {this->_currentList = List; return *this;}
		Builder& newList(const vector<T>& newList) {this->_newList = newList; return *this;}
		Builder& hookIDs(const vector<string>& hookIDs) {this->_hookIDs = hookIDs; return *this;}
		Builder& minCount(const Formula& minCount) {this->_minCount = minCount; return *this;}
		Builder& maxCount(const Formula& maxCount) {this->_maxCount = maxCount; return *this;}
		Selector<T> build(){return Selector<T>(this);}
		friend class Selector<T>;
	};

private:
	Selector(Builder* builder) {
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
	const Formula& getMinCount() const {return this->minCount;}
	const Formula& getMaxCount() const {return this->maxCount;}

	void Add();
	void Replace();

	string serialize() const;

	Selector() = default;
	Selector(const string& jsonPath);
	~Selector() = default;
};
