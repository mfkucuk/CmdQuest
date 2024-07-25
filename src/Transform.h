#pragma once

#include "Vector.h"

namespace CmdQuest {
    struct CMDQUEST_API Transform {
        public:
        Transform() {}

        Vector2 position;

        void moveBy(int x = 0, int y = 0) {
            position.x += x;
            position.y += y;
        }
    };
}
