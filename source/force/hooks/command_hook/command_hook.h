#pragma once
#include "lib.hpp"
#include "../hooks.h"

HOOK_DEFINE_REPLACE(Command) {
    static bool Callback(int input, int low, int high, int64_t out) {
        return true;
    }
};

namespace CommandHook {
	class ValidRange : public Hook {
	public:
		bool Initialize() override {
			uintptr_t address = SigScan("ff 43 03 d1 fd 7b 07 a9 fb 43 00 f9 fa 67 09 a9 f8 5f 0a a9 f6 57 0b a9 f4 4f 0c a9 fd c3 01 91 68 e1");
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