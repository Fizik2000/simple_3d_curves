#include "header/circle.h"
#include <stdexcept>

namespace curves {

Circle::Circle(double radius) : radius_(radius) {
  if (radius_ <= 0.0) {
    throw std::invalid_argument("circle radius is negative");
  }
}

Point3D Circle::getPoint(double t) const {
  return {radius_ * std::cos(t), radius_ * std::sin(t), 0.0};
}

Vector3D Circle::getDerivative(double t) const {
  return {-radius_ * std::sin(t), radius_ * std::cos(t), 0.0};
}

} // namespace curves