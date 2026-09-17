#include "hook_manager.h"
void HookManager::initHooks() {
	exl::hook::Initialize();
	hooks.push_back(new ItemEnchantsHook::canEnchant());
	hooks.push_back(new CommandHook::ValidRange());

	for (auto hook : hooks) {
		hook->Initialize();
	}
}