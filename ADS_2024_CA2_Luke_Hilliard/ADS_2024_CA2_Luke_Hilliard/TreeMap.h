#pragma once
#include "BinaryTree.h"
#include "Entity.h"


template <class K, class V>
class TreeMap
{
	BinaryTree<Entity<K, V>> tree;
	int size;
public:
	TreeMap();
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	
};

template <class K, class V>
TreeMap<K, V>::TreeMap()
{
	this->size = 0;
}

template <class K, class V>
void TreeMap<K, V>::clear()
{
	this->tree.clear();
	this->size = 0;
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

template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{

}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return this->size;
}

template <class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{

}
