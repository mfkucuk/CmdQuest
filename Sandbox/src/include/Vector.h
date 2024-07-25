#pragma once

#include <cmath>

namespace CmdQuest {
    struct Vector2 {
        public:
        Vector2() {
            this->x = 0;
            this->y = 0;
        }

        Vector2(float x, float y) {
            this->x = x;
            this->y = y;
        }
        
        float x;
        float y;

        bool operator==(const Vector2& other) {
            return this->x == other.x && this->y == other.y; 
        }

        bool operator!=(const Vector2& other) {
            return this->x != other.x || this->y != other.y;
        }

        Vector2 operator+(const Vector2& other) {
            return Vector2(this->x + other.x, this->y + other.y);
        }

        Vector2 operator-(const Vector2& other) {
            return Vector2(this->x - other.x, this->y - other.y);
        }

        Vector2& operator+=(const Vector2& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        Vector2& operator-=(const Vector2& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        float length() {
            return std::sqrt(this->x * this->x + this->y * this->y);
        }

        float lengthSquared() {
            return this->x * this->x + this->y * this->y;
        }

        // comparative operators
        bool operator>(Vector2& other) {
            return this->lengthSquared() > other.lengthSquared();
        }

        bool operator<(Vector2& other) {
            return this->lengthSquared() < other.lengthSquared();
        }
    };
}
