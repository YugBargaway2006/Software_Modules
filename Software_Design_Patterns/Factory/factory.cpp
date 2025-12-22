class Product {
public:
    virtual void operation() = 0;
    virtual ~Product() = default;
};



class ConcreteProductA : public Product {
public:
    void operation() override {
        // Product A specific behavior
    }
};

class ConcreteProductB : public Product {
public:
    void operation() override {
        // Product B specific behavior
    }
};



class Creator {
public:
    virtual Product* createProduct() = 0;

    void someBusinessLogic() {
        Product* product = createProduct();
        product->operation();
        delete product;
    }

    virtual ~Creator() = default;
};



class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};



void clientCode(Creator* creator) {
    creator->someBusinessLogic();
}



int main() {
    Creator* creator = new ConcreteCreatorA();
    clientCode(creator);
    delete creator;

    creator = new ConcreteCreatorB();
    clientCode(creator);
    delete creator;

    return 0;
}
