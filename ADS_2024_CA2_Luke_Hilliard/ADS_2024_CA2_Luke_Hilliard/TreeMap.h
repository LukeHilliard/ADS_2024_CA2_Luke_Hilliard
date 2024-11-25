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

	void printTreeInOrder();
	void printTreePreOrder();
	void printTreePostOrder();
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

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{

}

template <class K, class V>
V& TreeMap<K, V>::get(K key)
{

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

template <class K, class V>
void TreeMap<K, V>::printTreeInOrder()
{
	this->tree.printInOrder();
}

template <class K, class V>
void TreeMap<K, V>::printTreePreOrder()
{
	this->tree.printPreOrder();
}

template <class K, class V>
void TreeMap<K, V>::printTreePostOrder()
{
	this->tree.printPostOrder();
}

