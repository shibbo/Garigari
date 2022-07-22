#include "Game/NameObj/NameObj.h"
#include "Game/NameObj/NameObjRegister.h"
#include "Game/SingletonHolder.h"

NameObj::NameObj(const char *pName) : mLinkInfo() {
    mName = NULL;
    mFlags = 0;
    mExecutionIdx = -1;
    mLinkInfo.reset();
    mName = pName;
    SingletonHolder<NameObjRegister>::sInstance->add(this);
}

NameObj::~NameObj() {

}

void NameObj::init(const JMapInfoIter &) {

}

void NameObj::initAfterPlacement() {

}

void NameObj::movement() {

}

void NameObj::draw() const {

}

void NameObj::calcAnim() {

}

void NameObj::calcViewAndEntry() {

}

void NameObj::initWithoutIter() {
    JMapInfoIter iter;
    iter.mInfo = 0;
    iter._4 = -1;
    init(iter);
}

void NameObj::setName(const char *pName) {
    mName = pName;
}

void NameObj::setLinkedInfo(const JMapInfoIter &rIter) {
    mLinkInfo.setLinkedInfo(rIter);
}

void NameObj::executeMovement() {
    if ((mFlags & 0x1) != 1) {
        movement();
    }
}

void NameObj::requestSuspend() {
    if ((mFlags & 4) == 4) {
        mFlags &= 0xFFFB;
    }

    mFlags |= 2;
}

void NameObj::requestResume() {
    if ((mFlags & 2) == 2) {
        mFlags &= 0xFFFD;
    }

    mFlags |= 4;
}

void NameObj::syncWithFlags() {
    if ((mFlags & 2) == 2) {
        mFlags = mFlags & 0xFFFD | 1;
    }

    if ((mFlags & 4) == 4) {
        mFlags &= 0xFFFA;
    }
}