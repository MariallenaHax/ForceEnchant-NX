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
	int enchantResultType;
	int enchantId;
	int level;
};

HOOK_DEFINE_TRAMPOLINE(ItemEnch) {
    static void Callback(int64_t _this, EnchantResult* result, EnchantMentInstance* en, bool allowNonVanilla) {
        Orig(_this, result, en,true);
    }
};

//見つけ方
//Enchantment of type {} is not compatible with item.でsearchする。
//参照元へ飛ぶ。
//その上にあるもっとも浅いelseの下にある引数が4つある関数に飛ぶ。
//その関数がItemEnchants::canEnchant

namespace ItemEnchantsHook {
	class canEnchant : public Hook {
	public:
		bool Initialize() override {
			uintptr_t address = SigScan("FD 7B BA A9 FB 0B 00 F9 FA 67 02 A9 F8 5F 03 A9 F6 57 04 A9 F4 4F 05 A9 FD 03 00 91 F4 03 01 AA F3 03 08 AA"); //26.51
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
