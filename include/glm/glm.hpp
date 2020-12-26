#ifndef THIRD_PARTY_TINYNURBS_INCLUDE_GLM_GLM_H
#define THIRD_PARTY_TINYNURBS_INCLUDE_GLM_GLM_H

#include "third_party/skia/include/core/SkPoint3.h"
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
 
  SkVector3 sk_vector;
};

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