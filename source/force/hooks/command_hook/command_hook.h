#pragma once
#include "lib.hpp"
#include "../hooks.h"

HOOK_DEFINE_REPLACE(Command) {
    static bool Callback(int input, int low, int high, int64_t out) {
        return true;
    }
};

//見つけ方
//commands.generic.num.tooSmallでsearchする。
//参照元へ飛ぶ。
//その関数がCommand::ValidRange

namespace CommandHook {
	class ValidRange : public Hook {
	public:
		bool Initialize() override {
			uintptr_t address = SigScan("FF 83 01 D1 FD 7B ? A9 ? ? ? A9 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? C3 ? ? ? ? ? ? ? ? ? ? ? ? 00 ? ? ? 00"); //26.51
			if(address)
			{
				Command::InstallAtPtr(address);
				return true;
			}
			else 
			{
				return false;
			}
		}
	};
}
