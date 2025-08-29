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
}

// remove a random name
// throw the EmptyCollectionException on an empty bag
template <typename T>
T Bag<T>::remove()						
{	
	// rd is a uniformly-distributed integer random number generator seeded from clock
	auto rd = std::random_device {}; 
	// rng is a random number generator
	auto rng = std::default_random_engine { rd() };
	// call shuffle method in algorithm and pass in the bag
	// and the random number generator object to shuffle all names
	std::shuffle(std::begin(bag), std::end(bag), rng);

	// remaining code...
}

template <typename T>
int Bag<T>::size() const				// return number of items in bag
{	
}

template <typename T>
bool Bag<T>::empty() const				// return empty status of bag
{	
}

