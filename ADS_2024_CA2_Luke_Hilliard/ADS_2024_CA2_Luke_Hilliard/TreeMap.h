#pragma once
#include "BinaryTree.h"
#include "Entity.h"


template <class K, class V>
class TreeMap
{
	BinaryTree<Entity<K, V>> tree;

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