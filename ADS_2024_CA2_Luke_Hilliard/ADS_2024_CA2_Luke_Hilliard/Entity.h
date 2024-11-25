#pragma once
template <typename K, typename V>
class Entity {
    K key;
    V value;
public:
    Entity(K key, V value);
    Entity();
    K& getKey();
    V& getValue();
    void setKey(K key);
    void setValue(V value);

    bool operator>(const Entity<K, V>& other);
    bool operator<(const Entity<K, V>& other);
    bool operator==(const Entity<K, V>& other);

    // >>
    friend std::ostream& operator<<(std::ostream& os, const Entity<K, V>& e)
    {
        os << "{ " << e.key << ",,, " << e.value << " }";
        return os;
    }
};

template <typename K, typename V>
Entity<K, V>::Entity(K key, V value)
{
    this->key = key;
    this->value = value;
}
template <typename K, typename V>
Entity<K, V>::Entity()
{
    this->key = K();
    this->value = V();
}

  
template <typename K, typename V>
K& Entity<K, V>::getKey() {
    return key;
}

template <typename K, typename V>
V& Entity<K, V>::getValue() {
    return value;
}

template <typename K, typename V>
void Entity<K, V>::setKey(K key) {
    this->key = key;
}

template <typename K, typename V>
void Entity<K, V>::setValue(V value) {
    this->value = value;
}


// >
template <typename K, typename V>
bool Entity<K, V>::operator>(const Entity<K, V>& other)
{
    return value > other.value;
}

// <
template <typename K, typename V>
bool Entity<K, V>::operator<(const Entity<K, V>& other)
{
    return value < other.value;
}

// ==
template <typename K, typename V>
bool Entity<K, V>::operator==(const Entity<K, V>& other)
{
    return this->key == other.key;
}

