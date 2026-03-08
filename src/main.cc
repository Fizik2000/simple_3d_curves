#include <iostream>
#include <vector>
#include <memory>
#include <random>   // randomDouble
#include <algorithm>
#include <numeric>

#include "header/circle.h"
#include "header/ellipse.h"
#include "header/helix.h"

// I took this function from my work. We use it for Monte Carlo algorithms.
double randomDouble(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

int main() {

    // Task 2
    std::vector<std::unique_ptr<curves::Curve>> curves;
    const int numCurves = 15;
    for (int i = 0; i < numCurves; ++i) {
        int type = (int)(randomDouble(0, 3));
            if (type == 0) { // Circle
                double r = randomDouble(0.5, 5.0);
                curves.push_back(std::unique_ptr<curves::Circle>(new curves::Circle(r)));
            } else if (type == 1) { // Ellipse
                double rx = randomDouble(0.5, 5.0);
                double ry = randomDouble(0.5, 5.0);
                curves.push_back(std::unique_ptr<curves::Ellipse>(new curves::Ellipse(rx, ry)));
            } else if (type == 2) { // Helix
                double r = randomDouble(0.5, 5.0);
                double step = randomDouble(0.2, 3.0);
                curves.push_back(std::unique_ptr<curves::Helix>(new curves::Helix(r, step)));
            }
    }
    std::cout << "Created " << curves.size() << " random curves.\n";

    // Task 3
    const double t = M_PI / 4.0;
    std::cout << "\nPoints and derivatives at t = PI/4\n";
    int index = 1;
    for (const auto& curve_ptr : curves) {
        curves::Point3D p = curve_ptr->getPoint(t);
        curves::Vector3D d = curve_ptr->getDerivative(t);
        std::cout << "Curve " << index++ << ": Point("
                  << p[0] << ", " << p[1] << ", " << p[2] << "), Derivative("
                  << d[0] << ", " << d[1] << ", " << d[2] << ")\n";
    }

    // Task 4
    std::vector<curves::Circle*> circles;

    for (const auto& curve_ptr : curves) {
        auto* circle_ptr = dynamic_cast<curves::Circle*>(curve_ptr.get());
        // I really don't like dynamic_cast, but it works very well here and it seems like there shouldn't be any problems with it.
        if (circle_ptr) {
            circles.push_back(circle_ptr);
        }
    }
    std::cout << "\nFound " << circles.size() << " circles in the first container." << std::endl;

    // Task 5
    std::sort(circles.begin(), circles.end(),
              [](const curves::Circle* a, const curves::Circle* b) {
                  return a->getRadius() < b->getRadius();
              });

    std::cout << "Circles sorted by radius:" << std::endl;
    for (const auto* c : circles) {
        std::cout << "Radius: " << c->getRadius() << std::endl;
    }

    // Task 6
    double sum_of_radiuses = std::accumulate(circles.begin(), circles.end(), 0.0,
                                          [](double sum, const curves::Circle* c) {
                                              return sum + c->getRadius();
                                          });
    std::cout << "\nTotal sum of radiuses of all circles: " << sum_of_radiuses << std::endl;

    return 0;
}