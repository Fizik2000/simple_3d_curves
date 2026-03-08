#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

namespace curves {

class Helix : public Curve {
private:
  double r_;
  double step_;

public:
  explicit Helix(double r, double step);

  double getR() const { return r_; }
  double getStep() const { return step_; }

  Point3D getPoint(double t) const override;
  Vector3D getDerivative(double t) const override;
};

} // namespace curves

#endif