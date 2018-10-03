#ifndef FCL_TRAC_COLLISION_OBJECT_H
#define FCL_TRAC_COLLISION_OBJECT_H

#include <memory>

#include "fcl/narrowphase/collision_object.h"

namespace fcl {

  template <typename S>
    class FCL_EXPORT TRACCollisionObject : public CollisionObject<S> {
    
  public:
    TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom);
    
    TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom,
			const Transform3<S>& tf);
    
    TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom,
			const Matrix3<S>& R,
			const Vector3<S>& T);
    
    ~TRACCollisionObject();

    virtual void computeAABB();
    
    void set_margin( S _margin );
    S get_margin();
    void add_margin_AABB();
    
  protected:
    S margin_;

  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  
  };
  
} // namespace fcl

#include "fcl/narrowphase/trac_collision_object-inl.h"

#endif
