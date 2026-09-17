#pragma once
#include "hooks.h"

//Hooks
#include "command_hook/command_hook.h"
#include "item_enchants/item_enchants.h"
//
class Hook;
class HookManager {
private:
	static inline std::vector<Hook*> hooks;
public:
	static void initHooks();
	static void DeleteHooks() {
		hooks.clear();
	}
};