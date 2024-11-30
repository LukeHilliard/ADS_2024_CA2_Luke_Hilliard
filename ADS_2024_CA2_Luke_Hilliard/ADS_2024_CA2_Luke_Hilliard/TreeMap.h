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
	TreeMap(K key);
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void keySetRecur(BSTNode<Entity<K, V>>* root, BinaryTree<K>& keys);
	void put(K key, V value);
	void put(K key);
	int size();
	bool removeKey(K key);
	V& operator[](K key) {
		if (containsKey(key))
			return get(key);
		else
			return V();
	}
};

template <class K, class V>
TreeMap<K, V>::TreeMap()
{
	this->_size = 0;
}
template <class K, class V>
TreeMap<K, V>::TreeMap(K key)
{
	this->key = key;
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
	Entity<K, V> target(key, V());
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


/*
	Algorithm

1)	start at root
2)	recursively call keySet to traverse the tree In Order
3)	add item to keyTree
4)	call until node == nullptr

	return keyTree

*/
template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> keyTree;
	this->keySetRecur(this->tree.root, keyTree);
	return keyTree;
}
template <class K, class V>
void TreeMap<K, V>::keySetRecur(BSTNode<Entity<K, V>>* node, BinaryTree<K>& keys)
{
	// traverse tree In Order and add items to keys
	if (node != nullptr)
	{
		keySetRecur(node->getLeft(), keys);
		keys.add(node->getItem().getKey());
		keySetRecur(node->getRight(), keys);
	}

}


/*
	Algorithm: 
1)  Create new Entity
2)  Use BinaryTree's put to add to BTree data structure
3) Increment size by 1
*/
template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
	if (!containsKey(key))
	{
		Entity<K, V> newNode(key, value);
		this->tree.add(newNode);
		this->_size += 1;
	}
	
}
template <class K, class V>
void TreeMap<K, V>::put(K key)
{
	if (!containsKey(key)) 
	{
		Entity<K, V> newNode(key);
		this->tree.add(newNode);
		this->_size += 1;
	}
	
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return this->_size;
}


/*
	Algorithm

	start at root

1)	does node = key
2)	no, is key less than node, yes, move to left child
3)	does child = key
4)	no, is key greater than node, yes, move to right child
5)	does child = key
6)	yes, remove node from tree and return true, no repeat
*/
template <class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	Entity<K, V> target(key, V());
	BSTNode<Entity<K, V>>* currentNode = this->tree.root;

	if (currentNode == nullptr) { 
		return false; 
	}

	while (currentNode != nullptr) {
		if (currentNode->getItem() == target) { 
			this->tree.remove(currentNode->getItem()); // remove node from tree
			this->_size -= 1;
			return true;
		}

		if (target < currentNode->getItem())
			currentNode = currentNode->getLeft();

		else
			currentNode = currentNode->getRight(); 
	}
	return false; // at the end of the tree so it was not found and not deleted
}