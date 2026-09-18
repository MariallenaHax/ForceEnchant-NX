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
//参照元のうち、引数が4つある関数に飛ぶ。
//その関数がCommand::ValidRange

namespace CommandHook {
	class ValidRange : public Hook {
	public:
		bool Initialize() override {
			uintptr_t address = SigScan("FF ? 03 D1 FD 7B ? A9 FB 43 00 F9 FA 67 ? A9 F8 5F ? A9 F6 57 ? A9 F4 4f ? A9 FD ? ? 91 68 E1"); //26.51
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
