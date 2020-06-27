#pragma once

namespace hooks {
	bool initialize();
	void release();

	inline unsigned int get_virtual(void* _class, unsigned int index) { return static_cast<unsigned int>((*reinterpret_cast<int**>(_class))[index]); }

	namespace create_move {
		using fn = bool(__stdcall*)(float, c_usercmd*);
		static bool __fastcall hook(void* ecx, void* edx, int input_sample_frametime, c_usercmd* cmd);
	};

	namespace paint_traverse {
		using fn = void(__thiscall*)(i_panel*, unsigned int, bool, bool);
		static void __stdcall hook(unsigned int panel, bool force_repaint, bool allow_force);
	}

	namespace scene_end {
		using fn = void(__thiscall*)(void*);
		void __stdcall hook();
	}
}
