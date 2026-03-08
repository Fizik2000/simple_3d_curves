#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

namespace curves {

class Circle : public Curve {
private:
  double radius_;

public:
  explicit Circle(double radius);

  double getRadius() const { return radius_; }

  Point3D getPoint(double t) const override;
  Vector3D getDerivative(double t) const override;

  ~Circle() = default;
};

} // namespace curves

#endif