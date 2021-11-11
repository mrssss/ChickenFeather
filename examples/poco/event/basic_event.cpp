#include <Poco/BasicEvent.h>
#include <Poco/Delegate.h>

#include <iostream>
#include <memory>

class MyData {

public:
    Poco::BasicEvent<int> dataChanged;

    MyData() {};

    void setData(int i);

    void print() const;

private:
    int data;
};

void MyData::setData(int i) {
    this->data = i;
    /// The same as dataChanged(this, this->data);
    dataChanged.notify(this, this->data);
}

void MyData::print() const {
    std::cout << "MyData data: " << this->data << std::endl;
}

class MyController {

public:
    MyController(std::shared_ptr<MyData> data);
    ~MyController();
protected:
    std::weak_ptr<MyData> data;
    void onDataChanged([[maybe_unused]] const void * pSender, int & d);
    void print() const { std::cout << "MyController print()" << std::endl; }
};

MyController::MyController(std::shared_ptr<MyData> d) : data(d) {
    data.lock()->dataChanged += Poco::delegate(this, &MyController::onDataChanged);
}

MyController::~MyController() {
    data.lock()->dataChanged -= Poco::delegate(this, &MyController::onDataChanged);
}

void MyController::onDataChanged([[maybe_unused]] const void * pSender, int & d) {
    std::cout << "MyController d: " << d << std::endl;
    this->print();
}

int main() {
    auto d = std::make_shared<MyData>();
    auto controller = std::make_shared<MyController>(d);
    d->setData(1);
    return 0;
}
