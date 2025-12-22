#include <string>


class House {
public:
    void setFoundation(const std::string& foundation) {
        foundation_ = foundation;
    }

    void setStructure(const std::string& structure) {
        structure_ = structure;
    }

    void setRoof(const std::string& roof) {
        roof_ = roof;
    }

    void setInterior(const std::string& interior) {
        interior_ = interior;
    }

private:
    std::string foundation_;
    std::string structure_;
    std::string roof_;
    std::string interior_;
};



class HouseBuilder {
public:
    virtual void buildFoundation() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual void buildInterior() = 0;

    virtual House* getHouse() = 0;

    virtual ~HouseBuilder() = default;
};



class ConcreteHouseBuilder : public HouseBuilder {
public:
    ConcreteHouseBuilder() {
        house_ = new House();
    }

    void buildFoundation() override {
        house_->setFoundation("Concrete Foundation");
    }

    void buildStructure() override {
        house_->setStructure("Concrete Structure");
    }

    void buildRoof() override {
        house_->setRoof("Concrete Roof");
    }

    void buildInterior() override {
        house_->setInterior("Modern Interior");
    }

    House* getHouse() override {
        return house_;
    }

private:
    House* house_;
};



class Director {
public:
    void setBuilder(HouseBuilder* builder) {
        builder_ = builder;
    }

    void constructHouse() {
        builder_->buildFoundation();
        builder_->buildStructure();
        builder_->buildRoof();
        builder_->buildInterior();
    }

private:
    HouseBuilder* builder_;
};



int main() {
    Director director;
    HouseBuilder* builder = new ConcreteHouseBuilder();

    director.setBuilder(builder);
    director.constructHouse();

    House* house = builder->getHouse();

    delete builder;
    delete house;

    return 0;
}




