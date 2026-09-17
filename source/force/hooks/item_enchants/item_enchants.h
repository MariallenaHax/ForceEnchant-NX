#pragma once
#include "lib.hpp"
#include "../hooks.h"

class EnchantMentInstance {
public:
	int enchantType;
	int level;
};

class EnchantResult {
public:
	int enchantResultType;;
	int enchantId;
	int level;
};

HOOK_DEFINE_TRAMPOLINE(ItemEnch) {
    static EnchantResult* Callback(int64_t _this, EnchantResult* result, EnchantMentInstance* en, bool allowNonVanilla) {
        return Orig(_this, result, en,true);
    }
};

namespace ItemEnchantsHook {
	class canEnchant : public Hook {
	public:
		bool Initialize() override {
			uintptr_t address = SigScan("fd 7b ba a9 fb 0b 00 f9 fa 67 02 a9 f8 5f 03 a9 f6 57 04 a9 f4 4f 05 a9 fd 03 00 91 f4 03 01 aa f3 03 08");
			if(address)
			{
				ItemEnch::InstallAtPtr(address);
				return true;
			}
			else 
			{
				return false;
			}
		}
	};
}