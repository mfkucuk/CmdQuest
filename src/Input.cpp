#include <conio.h>

#include "Input.h"

namespace CmdQuest {
    KeyCode Input::GetKey() {
        if (_kbhit()) {
            return (KeyCode)_getch();
        }

        return KeyCode::None;
    }
}