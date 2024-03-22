// Author: Michael Brunner

#include <format>
#include <string>
#include "CwAPI3D.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

namespace Constants
{
	const std::wstring NetLibraryName = L"CWAPI3D_NET";
}

public
ref class ManagedConstants abstract sealed // abstract sealed makes it static
{
public:
	static String ^ InitializerName = "CwAPI3D_NET.Initializer";
};

bool loadAssemblyAndGetType(CwAPI3D::ControllerFactory* aFactory, Assembly ^ &aAssembly, Type ^ &aPluginType)
{
	const auto lPluginPath = aFactory->getUtilityController()->getPluginPath()->data();
	const std::wstring lNetLibrary = std::format(L"{}\\{}.dll", lPluginPath, Constants::NetLibraryName);

	try
	{
		aAssembly = Assembly::LoadFrom(gcnew String(lNetLibrary.c_str()));
		aPluginType = aAssembly->GetType(ManagedConstants::InitializerName);
	}
	catch(FileNotFoundException ^ e)
	{
		Console::WriteLine(e->Message);
		return false;
	}
	catch(FileLoadException ^ e)
	{
		Console::WriteLine(e->Message);
		return false;
	}

	return aPluginType != nullptr;
}

bool invokePluginInitializer(Type ^ aPluginType, CwAPI3D::ControllerFactory* aFactory)
{
	Object ^ lPluginInstance = Activator::CreateInstance(aPluginType);
	auto lFactoryPointer = IntPtr(aFactory);
	auto lMethodArgs = gcnew array<Object ^>{lFactoryPointer};

	try
	{
		if(aPluginType->InvokeMember("Initialize",
									 BindingFlags::InvokeMethod,
									 nullptr,
									 lPluginInstance,
									 lMethodArgs))
		{
			Console::WriteLine("Plugin initialization successful");
			return true;
		}
	}
	catch(TargetInvocationException ^ e)
	{
		Console::WriteLine(e->Message);
	}

	aFactory->getUtilityController()->printMessage(L"Plugin initialization failed");
	return false;
}

auto plugin_x64_init(CwAPI3D::ControllerFactory* aFactory) -> bool
{
	if(!aFactory)
	{
		return false;
	}

	Assembly ^ lAssembly;
	Type ^ lPluginType;

	if(!loadAssemblyAndGetType(aFactory, lAssembly, lPluginType))
	{
		aFactory->getUtilityController()->printMessage(L"Plugin initialization failed");
		return false;
	}

	return invokePluginInitializer(lPluginType, aFactory);
}
