#pragma once

namespace IL2CPP
{
	namespace Domain
	{
		static void* Get()
		{
			return reinterpret_cast<void*(IL2CPP_CALLING_CONVENTION)()>(Data.Functions.m_pDomainGet)();
		}

		static Unity::il2cppAssembly* GetNextAssembly(void** iter) {
			return reinterpret_cast<Unity::il2cppAssembly*(*)(void*, void**)>(Data.Functions.m_pDomainGetAssemblies)(Get(), iter);
		}
	}
}