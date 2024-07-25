#pragma once

#include <chrono>
#include <conio.h>
#include <thread>
#include <windows.h>


#include "Renderer.h"
#include "Input.h"
#include "Sprite.h"
#include "KeyCode.h"

namespace CmdQuest {

    class CMDQUEST_API Game {

        public:
        void run();
        void shutdown();

        virtual void start() = 0;
        virtual void update() = 0;

        protected:
        KeyCode key;

        private:
        void enableVirtualTerminalProcessing();
    };

}; 