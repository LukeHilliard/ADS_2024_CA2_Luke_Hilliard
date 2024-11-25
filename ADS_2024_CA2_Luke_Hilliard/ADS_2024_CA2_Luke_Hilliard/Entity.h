#pragma once
template <typename K, typename V>
class Entity {
    K key;
    V value;
public:
   
    Entity(K key, V value)
    {
        this->key = key;
        this->value = value;
    }
    Entity()
    {
        this->key = K();
        this->value = V();
    }

  
    K& getKey() {
        return key;
    }

    V& getValue() {
        return value;
    }

    void setKey(K key) {
        this->key = key;
    }

    void setValue(V value) {
        this->value = value;
    }

    ~Entity() {}


    // >
    bool operator>(const Entity& other)
    {
        return value > other.value;
    }

    // <
    bool operator<(const Entity& other)
    {
        return value < other.value;
    }

    // ==
    bool operator==(const Entity& other)
    {
        return this->key == other.key;
    }

    // >>
    friend std::ostream& operator<<(std::ostream& os, const Entity& e)
    {
        os << "{ " << e.key << ", " << e.value << " }";
        return os;
    }
};
