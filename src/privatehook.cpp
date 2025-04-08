#include <metahook.h>
//#include <capstone.h>
#include <vector>
#include <set>
#include "plugins.h"
#include "privatehook.h"

private_funcs_t gPrivateFuncs = { 0 };

static hook_t* g_phook_R_ScaleColor = nullptr;
static hook_t* g_phook_R_CalcDamageDirection = nullptr;

void Engine_FillAddress(const mh_dll_info_t& DllInfo, const mh_dll_info_t& RealDllInfo)
{
	//do nothing
}

void Engine_InstallHooks()
{
	
}

void Engine_UninstallHooks()
{

}

void Client_FillAddress(const mh_dll_info_t& DllInfo, const mh_dll_info_t& RealDllInfo)
{
	//Thank god they don't change since 5.25
#define R_SCALE_COLOR "\x66\x0F\x6E\x4C\x24\x10\x8B\x4C\x24\x04\x0F\x5B\xC9\x66\x0F\x6E\x01\xF3\x0F\x5E\x0D\x2A\x2A\x2A\x2A\x0F\x5B\xC0\xF3\x0F\x59\xC1\xF3\x0F\x2C\xC0\x89\x01\x8B\x4C\x24\x08\x66\x0F\x6E\x01\x0F\x5B\xC0\xF3\x0F\x59\xC1\xF3\x0F\x2C\xC0\x89\x01\x8B\x4C\x24\x0C\x66\x0F\x6E\x01\x0F\x5B\xC0\xF3\x0F\x59\xC1\xF3\x0F\x2C\xC0\x89\x01\xC3"
#define R_CALCDAMAGE_DIRECTION "\x55\x8B\xEC\x83\xE4\xF8\xF3\x0F\x10\x65\x08\x83\xEC\x44\xF3\x0F\x10\x55\x10\x0F\x57\xC0\xF3\x0F\x10\x5D\x0C"

	if (g_iEngineType == ENGINE_SVENGINE)
	{
		auto pfnClientFactory = g_pMetaHookAPI->GetClientFactory();

		if (pfnClientFactory)
		{
			auto SCClient001 = pfnClientFactory("SCClientDLL001", 0);

			if (SCClient001)
			{
				gPrivateFuncs.R_ScaleColor = (decltype(gPrivateFuncs.R_ScaleColor))Search_Pattern(R_SCALE_COLOR, DllInfo);
				Sig_FuncNotFound(R_ScaleColor);

				gPrivateFuncs.R_CalcDamageDirection = (decltype(gPrivateFuncs.R_CalcDamageDirection))Search_Pattern(R_CALCDAMAGE_DIRECTION, DllInfo);
				Sig_FuncNotFound(R_CalcDamageDirection);
			}
		}
		else
		{
			Sig_NotFound("SCClientDLL001");
		}
	}
	else
	{
		Sig_NotFound("Sven Co-op");
	}
}

void Client_InstallHooks()
{
	//do nothing
	Install_InlineHook(R_ScaleColor);
	Install_InlineHook(R_CalcDamageDirection);
}

void Client_UninstallHooks()
{

}