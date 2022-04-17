#include <chrono>
#include <iostream>

#include <Eigen/Dense>

using namespace std;
using namespace std::chrono;

EIGEN_DONT_INLINE
double simple_function(Eigen::VectorXd& va, Eigen::VectorXd& vb)
{
    double d = va.dot(vb);
    return d;
}

int main() {
    int len = 1000000;
    int num_repetitions = 100;

    Eigen::VectorXd va = Eigen::VectorXd::Random(len);
    Eigen::VectorXd vb = Eigen::VectorXd::Random(len);

    double result{};
    auto start = system_clock::now();
    for (auto i = 0; i < num_repetitions; i++)
    {
        result = simple_function(va, vb);
    }

    auto end = system_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);

    cout << "result: " << result << endl;
    cout << "elapsed microseconds: " << elapsed.count() << endl;
}