#include <Poco/ActiveMethod.h>
#include <Poco/ActiveResult.h>

#include <utility>
#include <iostream>

class ActiveAdder {

public:
    ActiveAdder() : add(this, &ActiveAdder::addImpl) {}
    Poco::ActiveMethod<int, std::pair<int, int>, ActiveAdder> add;

private:
    int addImpl(const std::pair<int, int> & args) {
        return args.first + args.second;
    }
};

int main() {
    ActiveAdder adder;

    Poco::ActiveResult<int> sum = adder.add(std::make_pair(1, 2));

    sum.wait();
    std::cout << sum.data() << std::endl;

    return 0;
}
