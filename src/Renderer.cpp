#include "Renderer.h"

namespace CmdQuest {
    std::vector<std::vector<char>> Renderer::buffer(25, std::vector<char>(80, ' '));
    std::vector<std::vector<int>> Renderer::colorBuffer(25, std::vector<int>(80, 39));
    Color Renderer::currentColor(Color::Default);

    void Renderer::clear() {
        std::cout << "\033[J";
        moveCursor(0, 0);
        setColor(Color::Default);

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                Renderer::buffer[i][j] = ' ';
            }
        }

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                Renderer::colorBuffer[i][j] = 39;
            }
        }
    };

    void Renderer::drawChar(char c, Transform transform) {
        int x = transform.position.x;
        int y = transform.position.y;

        if (!isInBounds(x, y)) {
            return;
        }

        Renderer::buffer[y][x] = c;
        Renderer::colorBuffer[y][x] = (int)currentColor;
    }

    void Renderer::drawSprite(Sprite sprite, Transform transform) {
        int x = transform.position.x;
        int y = transform.position.y;

        auto texture = sprite.getTexture();

        for (int i = 0; i < texture.size(); i++) {
            for (int j = 0; j < texture[i].size(); j++) {
                if (texture[i][j] != ' ' && isInBounds(x + j, y + i)) {
                    Renderer::buffer[y + i][x + j] = texture[i][j];
                    Renderer::colorBuffer[y + i][x + j] = (int)currentColor;
                }

            }
        }
    }

    void Renderer::flush() {
        std::string output = "";
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                std::string color = "\033[" + std::to_string(Renderer::colorBuffer[i][j]) + "m";

                output += color + Renderer::buffer[i][j];
            }

            output += '\n';
        }

        std::cout << output;

        clear();
    }

    void Renderer::moveCursor(int x, int y) {
        std::cout << "\033[" << y + 1 << ";" << x + 1 << "H";
    }

    void Renderer::setColor(Color color) {
        currentColor = color;
    }

    bool Renderer::isInBounds(int x, int y) {
        return x >= 0 && x < 80 && y >= 0 && y < 25;
    }
}