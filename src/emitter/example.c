#include <unistd.h>

#include "ac_controller.h"

int main(int argc, char ** argv) {
    ac_state state;
    init_state(&state, 17);

    // generate command to set temp
    turn_on(&state);
    sleep(8);

    turn_sixth_sense_on(&state);
    sleep(8);

    turn_sixth_sense_dehumidify(&state);
    sleep(8);

    while (1) {
        set_temp(&state, 16);
        sleep(5);

        set_temp(&state, 23);
        sleep(5);
    }

    // won't run in this case, just as an example
    turn_off(&state);

    return 0;
}
