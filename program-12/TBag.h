#pragma once
#include <vector>						// for the vector class
#include <algorithm>					// for the shuffle algorithm
#include <random>						// for the random number generator
#include "EmptyCollectionException.h"   // for the EmptyCollectionException class



template <typename T>
class Bag
{	public:
		Bag ();							// empty bag
		~Bag();							// destructor
		void insert (T item);			// insert item into bag
		T remove ( );					// remove random item from bag
		int size() const;				// return number of items in bag
		bool empty () const;			// return empty status of bag
	private:
		std::vector<T> bag;				// class composition used here
};

template <typename T>
Bag<T>::Bag()							// empty bag
{										// vector default constructor is called
}

template <typename T>
Bag<T>::~Bag()							// destructor
{										// vector destructor is called
}

template <typename T>
void Bag<T>::insert(T item)				// insert item into bag
{	

	bag.push_back(item);
}

// remove a random name
// throw the EmptyCollectionException on an empty bag
template <typename T>
T Bag<T>::remove()						
{	
    
	
	//check if bag is empty and throw exception if it is. 

	 if(bag.empty()){

		throw EmptyCollectionException("bag is empty");
	 }




	// rd is a uniformly-distributed integer random number generator seeded from clock
	 std::random_device rd;
	// rng is a random number generator
	std::default_random_engine rng(rd());
	// call shuffle method in algorithm and pass in the bag
	// and the random number generator object to shuffle all names
	std::shuffle(std::begin(bag), std::end(bag), rng);

	// remaining code...


	// get the last item from the shuffled bag.

	T item = bag.back();
    
	// remove the last item from the bag. 
	bag.pop_back();

	return item;


}

template <typename T>
int Bag<T>::size() const				// return number of items in bag
{	
    return bag.size();
	
}

template <typename T>
bool Bag<T>::empty() const				// return empty status of bag
{	


	return bag.empty();

}

