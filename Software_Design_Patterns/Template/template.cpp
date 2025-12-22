#include <iostream>

class DataProcessor {
public:
    // Template method (defines algorithm skeleton)
    void process() {
        readData();
        processData();
        writeData();
    }

    virtual ~DataProcessor() = default;

protected:
    virtual void readData() = 0;
    virtual void processData() = 0;

    // Hook method (optional override)
    virtual void writeData() {
        std::cout << "Writing processed data\n";
    }
};



class CSVDataProcessor : public DataProcessor {
protected:
    void readData() override {
        std::cout << "Reading data from CSV file\n";
    }

    void processData() override {
        std::cout << "Processing CSV data\n";
    }
};

class JSONDataProcessor : public DataProcessor {
protected:
    void readData() override {
        std::cout << "Reading data from JSON file\n";
    }

    void processData() override {
        std::cout << "Processing JSON data\n";
    }

    void writeData() override {
        std::cout << "Writing processed JSON data\n";
    }
};



int main() {
    DataProcessor* csv = new CSVDataProcessor();
    DataProcessor* json = new JSONDataProcessor();

    csv->process();
    std::cout << "----\n";
    json->process();

    delete csv;
    delete json;

    return 0;
}
