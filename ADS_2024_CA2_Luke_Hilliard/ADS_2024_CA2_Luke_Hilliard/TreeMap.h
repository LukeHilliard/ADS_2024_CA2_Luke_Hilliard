#pragma once
#include "BinaryTree.h"
template <class K, class V>
class TreeMap
{
	BinaryTree<K, V> tree;

public:
	TreeMap();
	TreeMap();
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	V& operator[K key];
};