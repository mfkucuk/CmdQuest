#include "Sprite.h"

namespace CmdQuest {
    Sprite::Sprite(std::string src) {
        std::ifstream myFile(src);
        std::string line;

        int i = 0;
        while (std::getline(myFile, line)) {
            texture.push_back({});
            for (int j = 0; j < line.length(); j++) {
                texture[i].push_back(line[j]);
            }

            i++;
        }
    }
    std::vector<std::vector<char>> Sprite::getTexture() {
        return texture;
    }
}