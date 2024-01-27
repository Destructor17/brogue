#pragma once

#include "../../core/include/common/events.h"

void webrogueBroguePushEvent(webrogue_event event);

webrogue_event webrogueBroguePullEvent();

char webrogueBrogueHasEvent();
