#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Sprite.h"
#include "Color.h"
#include "Transform.h"

namespace CmdQuest {

    class Renderer {
        public:
        void static clear();
        void static drawChar(char c, Transform transform);
        void static drawSprite(Sprite sprite, Transform transform);
        void static flush();
        void static moveCursor(int x, int y);
        void static setColor(Color color);

        private:
        static std::vector<std::vector<char>> buffer;
        static std::vector<std::vector<int>> colorBuffer;

        static Color currentColor;
    };

}