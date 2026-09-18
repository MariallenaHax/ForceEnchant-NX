#pragma once
#include "lib.hpp"
#include "../hooks.h"

HOOK_DEFINE_INLINE(ItemEnch) {
	static void Callback(exl::hook::InlineCtx* ctx) {
		ctx->W[2] = 1;
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
