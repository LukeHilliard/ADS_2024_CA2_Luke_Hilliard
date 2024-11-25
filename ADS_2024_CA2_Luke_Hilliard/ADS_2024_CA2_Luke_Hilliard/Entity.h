#pragma once
template <typename K, typename V>
class Entity {
    K key;
    V value;

public:
    Entity(K key, V value);
    K& getKey();
    V& getValue();
    void setKey(K key);
    void setValue(V value);
    ~Entity();


    Entity::Entity(K key, V value)
    {
        this->key = key;
        this->value = value;
    }

  
    K& Entity::getKey() {
        return key;
    }

    V& Entity::getValue() {
        return value;
    }

    void Entity::setKey(K key) {
        this->key = key;
    }

    void Entity::setValue(V value) {
        this->value = value;
    }

    Entity::~Entity()
    {
        this->key = nullptr;
        this->value = nullptr;
    }
};
