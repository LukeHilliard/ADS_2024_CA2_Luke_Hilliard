#pragma once
#include "BinaryTree.h"
#include "Entity.h"


template <class K, class V>
class TreeMap
{
	BinaryTree<Entity<K, V>> tree;
	int _size;
public:
	TreeMap();
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	BinaryTree<Entity<K, V>>& getBTree();

};

template <class K, class V>
TreeMap<K, V>::TreeMap()
{
	this->_size = 0;
}

template <class K, class V>
void TreeMap<K, V>::clear()
{
	this->tree.clear();
	this->_size = 0;
}


/*
	Algorithm:
			start at root
			does node = key

	no, is key less than node, yes, move to left child
	does child = key
	no, is key greater than node, yes, move to right child
						does child = key
						yes, return, no repeat
*/
template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	//std::cout << "Looking for " << key << endl;
	Entity<K, V> target(key, V());
	// start at root key
	BSTNode<Entity<K, V>>* currentNode = this->tree.root;


	if (currentNode == nullptr) {
		return false; // if its nullptr then there is no root
	}

	while (currentNode != nullptr) {
		// does node = key
		if (currentNode->getItem() == target) 
			return true;
		
		// no, is key less than node
		if (target < currentNode->getItem())
			currentNode = currentNode->getLeft(); // yes, move to left child
	
		// is key greater than node
		else
			currentNode = currentNode->getRight(); // yes, move to right child

		// repeat on new child node from left/right
	}
	return false; // node = nullptr so key not within BinaryTree
}



/*
	Algorithm

	Same as containsKey()


*/
template <class K, class V>
V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> target(key, "Key not found.");
	BSTNode<Entity<K, V>>* currentNode = this->tree.root;

	while (currentNode != nullptr)
	{
		if (currentNode->getItem() == target)
			return currentNode->getItem().getValue();

		if (target < currentNode->getItem())
			currentNode = currentNode->getLeft();

		else
			currentNode = currentNode->getRight();
	}
	return target.getValue(); // TODO I think this part is incorrect


	
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{

}


/*
	Algorithm: 
	1) Create new Entity
	2) Use BinaryTree's put to add to BTree data structure
	3) Increment size by 1
*/
template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
	Entity<K, V> newNode(key, value);
	this->tree.add(newNode);
	this->_size += 1;
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return this->_size;
}

template <class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{

}


