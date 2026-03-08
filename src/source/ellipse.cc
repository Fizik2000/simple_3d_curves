#include "header/ellipse.h"
#include <stdexcept>

namespace curves {

Ellipse::Ellipse(double rx, double ry) : rx_(rx), ry_(ry) {
  if (rx_ <= 0.0 || ry_ <= 0.0) {
    throw std::invalid_argument("radius is negative");
  }
}

Point3D Ellipse::getPoint(double t) const {
  return {rx_ * std::cos(t), ry_ * std::sin(t), 0.0};
}

Vector3D Ellipse::getDerivative(double t) const {
  return {-rx_ * std::sin(t), ry_ * std::cos(t), 0.0};
}

} // namespace curves