#include "StateMachine.h"

int main() {
    srand(time(NULL));
    StateMachine machine(1500.f, 720.f, 0.1f, 2.f, 3.f);
    machine.mainloop();

    return 0;
}