#include "header/helix.h"
#include <stdexcept>

namespace curves {

Helix::Helix(double r, double step) : r_(r), step_(step) {
  if (r_ <= 0.0 || step_ <= 0.0) {
    throw std::invalid_argument("Helix radius is negative");
  }
}

Point3D Helix::getPoint(double t) const {
  return {r_ * std::cos(t), r_ * std::sin(t), (step_ * t) / (2 * M_PI)};
}

Vector3D Helix::getDerivative(double t) const {
  return {-r_ * std::sin(t), r_ * std::cos(t), step_ / (2 * M_PI)};
}

} // namespace curves