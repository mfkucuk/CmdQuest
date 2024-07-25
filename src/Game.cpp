#include "Game.h"

namespace CmdQuest {
    KeyCode key = KeyCode::None;

    void Game::run() {

        enableVirtualTerminalProcessing();

        std::cout << "\033[?25l";
        system("cls");

        start();

        while (true) {
            key = Input::GetKey();
            if (key == KeyCode::Escape) {
                return;
            }

            update();

            Renderer::flush();

            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    };

    void Game::shutdown() {
        Renderer::clear();

        system("cls");
        system("pause");
        system("cls");
    }

    void Game::enableVirtualTerminalProcessing() {
#ifdef WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) {
            return;
        }

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode)) {
            return;
        }

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode)) {
            return;
        }
#endif
    };
}; 