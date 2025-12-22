template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};



template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
    virtual ~Aggregate() = default;
};



#include <vector>

template <typename T>
class ConcreteAggregate : public Aggregate<T> {
public:
    void add(const T& value) {
        items_.push_back(value);
    }

    T get(size_t index) const {
        return items_[index];
    }

    size_t size() const {
        return items_.size();
    }

    Iterator<T>* createIterator() override;

private:
    std::vector<T> items_;
};



template <typename T>
class ConcreteIterator : public Iterator<T> {
public:
    explicit ConcreteIterator(const ConcreteAggregate<T>* aggregate)
        : aggregate_(aggregate), index_(0) {}

    bool hasNext() const override {
        return index_ < aggregate_->size();
    }

    T next() override {
        return aggregate_->get(index_++);
    }

private:
    const ConcreteAggregate<T>* aggregate_;
    size_t index_;
};



template <typename T>
Iterator<T>* ConcreteAggregate<T>::createIterator() {
    return new ConcreteIterator<T>(this);
}



#include <iostream>

int main() {
    ConcreteAggregate<int> collection;
    collection.add(10);
    collection.add(20);
    collection.add(30);

    Iterator<int>* iterator = collection.createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }

    delete iterator;
    return 0;
}
