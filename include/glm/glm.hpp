#ifndef THIRD_PARTY_TINYNURBS_INCLUDE_GLM_GLM_H
#define THIRD_PARTY_TINYNURBS_INCLUDE_GLM_GLM_H

#include "third_party/skia/include/core/SkPoint3.h"
#include "third_party/skia/include/core/SkPoint.h"
#include "third_party/skia/include/core/SkScalar.h"

namespace glm {

template<int dim, typename T>
class vec;

template<>
class vec<3, SkScalar> {
 public:
  vec(SkVector3 const& v) : sk_vector{v} {}
  vec(SkVector3&& v) : sk_vector{v} {}
  vec<3, SkScalar>& operator=(SkVector3 const& v) {
    sk_vector = v;
    return *this;
  }
  vec<3, SkScalar>& operator=(SkVector3&& v) {
    sk_vector = v;
    return *this;
  }

  vec(SkVector const& v) : sk_vector{v.fX, v.fY, 0} {}
  vec<3, SkScalar>& operator=(SkVector const& v) {
    sk_vector = SkVector3::Make(v.fX, v.fY, 0);
    return *this;
  }

  vec(SkScalar s) : sk_vector{s, s, s} {}
  vec<3, SkScalar>& operator=(SkScalar s) {
    sk_vector = SkVector3::Make(s, s, s);
    return *this;
  }

  void operator+=(const vec<3, SkScalar>& v) {
    return sk_vector += v.sk_vector;
  }

  SkVector3 sk_vector;
};

vec<3, SkScalar> operator*(SkScalar t, vec<3, SkScalar> p) {
  return t * p.sk_vector;
}

template<typename v>
SkScalar length(v const& a);

template<>
SkScalar length<vec<3, SkScalar>>(vec<3, SkScalar> const& a) {
  return a.sk_vector.length();
}

template<typename v>
v cross(v const& a, v const& b);

template<>
vec<3, SkScalar> cross<vec<3, SkScalar>>(vec<3, SkScalar> const& a, vec<3, SkScalar> const& b) {
  return SkVector3::CrossProduct(a.sk_vector, b.sk_vector);
}


}

#endif  // THIRD_PARTY_TINYNURBS_INCLUDE_GLM_GLM_H