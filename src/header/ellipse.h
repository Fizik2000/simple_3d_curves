#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

namespace curves {

class Ellipse : public Curve {
private:
  double rx_;
  double ry_;

public:
  explicit Ellipse(double rx, double ry);

  double getRx() const { return rx_; }
  double getRy() const { return ry_; }

  Point3D getPoint(double t) const override;
  Vector3D getDerivative(double t) const override;
};

} // namespace curves

#endif