#include "CmdQuest.h"

class SandboxGame : public CmdQuest::Game {
    public:
    void start() override {
        playerSprite = CmdQuest::Sprite("Player.txt");
    }

    void update() override {
        CmdQuest::Renderer::setColor(CmdQuest::Color::Green);
        CmdQuest::Renderer::drawSprite(playerSprite, t);

        if (key == CmdQuest::KeyCode::D) {
            t.moveBy(1);
        }

        if (key == CmdQuest::KeyCode::A) {
            t.moveBy(-1);
        }

        if (key == CmdQuest::KeyCode::W) {
            t.moveBy(0, -1);
        }

        if (key == CmdQuest::KeyCode::S) {
            t.moveBy(0, 1);
        }
    }

    CmdQuest::Transform t;
    CmdQuest::Sprite playerSprite;
};

int main() {
    SandboxGame sandbox;

    sandbox.run();

    sandbox.shutdown();

    return 0;
}