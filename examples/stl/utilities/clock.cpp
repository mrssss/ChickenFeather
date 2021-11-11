#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>

template <typename C>
void printClockData() {
    using namespace std;

    cout << "- precision: ";

    typedef typename C::period P;

    if(ratio_less_equal<P, milli>::value) {
        typedef typename ratio_multiply<P, kilo>::type TT;
        cout << fixed << double(TT::num)/TT::den
             << " milliseconds" << endl;
    } else {
        cout << fixed << double(P::num/P::den) << " seconds"<< endl;
    }
    cout << "- is_steady: " << boolalpha << C::is_steady << endl;
}

int main() {
    std::cout << "system_clock: " << std::endl;
    printClockData<std::chrono::system_clock>();

    std::cout << "\nhigh_resolution_clock: " << std::endl;
    printClockData<std::chrono::high_resolution_clock>();

    std::cout << "\nsteady_clock: " << std::endl;
    printClockData<std::chrono::steady_clock>();

    auto start_time = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time);
    std::cout << "Sleep for: " << millisec.count() << " milliseconds" << std::endl;

    return 0;
}