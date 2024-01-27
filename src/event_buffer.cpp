#include <queue>
extern "C" {
#include "event_buffer.h"
}

static std::queue<webrogue_event> webrogueBrogueEventBuffer;
extern "C" {
void webrogueBroguePushEvent(webrogue_event event) {
    webrogueBrogueEventBuffer.push(event);
}

webrogue_event webrogueBroguePullEvent() {
    webrogue_event result = webrogueBrogueEventBuffer.back();
    webrogueBrogueEventBuffer.pop();
    return result;
}

char webrogueBrogueHasEvent() {
    return !webrogueBrogueEventBuffer.empty();
}
}
