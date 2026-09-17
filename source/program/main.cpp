#include "lib.hpp"
#include "force/hooks/hook_manager.h"

extern "C" void exl_main(void* x0, void* x1) {
    HookManager::initHooks();
}

extern "C" NORETURN void exl_exception_entry() {
    EXL_ABORT("DAMN");
}