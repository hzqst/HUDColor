#pragma once

#include "enginedef.h"

typedef struct walk_context_s
{
	walk_context_s(void* a, size_t l, int d) : address(a), len(l), depth(d)
	{

	}
	void* address;
	size_t len;
	int depth;
}walk_context_t;

typedef struct
{
	void(*R_ScaleColor)(int* r, int* g, int* b, int a);
	void(__fastcall* R_CalcDamageDirection)(void* pthis, int dummy, int x, float y, float z);
}private_funcs_t;

extern private_funcs_t gPrivateFuncs;

void Engine_FillAddress(const mh_dll_info_t& DllInfo, const mh_dll_info_t& RealDllInfo);
void Engine_InstallHooks();
void Engine_UninstallHooks();
void Client_FillAddress(const mh_dll_info_t& DllInfo, const mh_dll_info_t& RealDllInfo);
void Client_InstallHooks();
void Client_UninstallHooks();

void R_ScaleColor(int* r, int* g, int* b, int a);
void __fastcall R_CalcDamageDirection(void* pThis, int dummy, int x, float y, float z);