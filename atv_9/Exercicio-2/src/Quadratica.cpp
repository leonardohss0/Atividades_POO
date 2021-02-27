#include "../include/Quadratica.hpp"

double Quadratica::func(double input) {
    return this->a * (input * input) + this->b * input + this->c;
}