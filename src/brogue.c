#include "../../core/include/core.h"
#include "../../core/include/macros.h"

#include "Rogue.h"

#include "GlobalsBase.h"
#include "platform.h"
#include <limits.h>
#include <math.h>

struct brogueConsole currentConsole;
boolean serverMode = false;
boolean nonInteractivePlayback = false;
boolean hasGraphics = false;
enum graphicsModes graphicsMode = TEXT_GRAPHICS;
boolean isCsvFormat = false;

boolean tryParseUint64(char *str, uint64_t *num) {
    unsigned long long n;
    char buf[100];
    if (strlen(str)                // we need some input
        && sscanf(str, "%llu", &n) // try to convert to number
        && sprintf(buf, "%llu", n) // convert back to string
        && !strcmp(buf, str)) {    // compare (we need them equal)
        *num = (uint64_t)n;
        return true; // success
    } else {
        return false; // input was too large or not a decimal number
    }
}

extern struct brogueConsole webrogueConsole;

int brogueMain() {
    currentConsole = webrogueConsole;

    rogue.nextGame = NG_NOTHING;
    rogue.nextGamePath[0] = '\0';
    rogue.nextGameSeed = 0;
    rogue.wizard = false;
    rogue.displayStealthRangeMode = false;
    rogue.trueColorMode = false;

    enum graphicsModes initialGraphics = TEXT_GRAPHICS;

    int i;

    hasGraphics = (currentConsole.setGraphicsMode != NULL);
    // Now actually set graphics. We do this to ensure there is exactly one
    // call, whether true or false
    graphicsMode = setGraphicsMode(initialGraphics);

    loadKeymap();
    currentConsole.gameLoop();

    return 0;
}

void brogueInitializationStep() {
    brogueMain();
}

WR_EXPORTED(void, init_mod_brogue)() {
    webrogue_core_add_initialization_step(&brogueInitializationStep);
}