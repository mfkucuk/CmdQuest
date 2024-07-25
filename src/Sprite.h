#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Core.h"

namespace CmdQuest {
    class CMDQUEST_API Sprite {
        public:
        Sprite() {}
        Sprite(std::string src);
        std::vector<std::vector<char>> getTexture();

        private:
        std::string src;
        std::vector<std::vector<char>> texture;

        void readTexture(std::string src);
    };
}