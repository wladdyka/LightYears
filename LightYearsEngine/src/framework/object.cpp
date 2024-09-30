#include "framework/object.h"
#include "framework/core.h"

namespace ly {
    Object::Object()
        : mIsPendingDestroy{false}
    { }

    Object::~Object() {
        LOG("Object destroyed");
    }

    void Object::Destroy() {
        mIsPendingDestroy = true;
    }
}
