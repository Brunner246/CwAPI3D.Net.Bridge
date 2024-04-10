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
	// The name of the .NET library (DLL) that contains the plugin
	const std::wstring NetLibraryName = L"examplelib";
} // namespace Constants

public
ref class ManagedConstants abstract sealed // abstract sealed makes it static
{
public:
	static String ^ InitializerNamespace = "examplelib";
	static String ^ InitializerName = String::Format("{0}.{1}", InitializerNamespace, "Initializer");
	static String ^ InitializerHookName = "Initialize";
};

Type ^ loadAssemblyAndGetType(CwAPI3D::ControllerFactory* aFactory) {
	const auto lPluginPath = aFactory->getUtilityController()->getPluginPath()->data();
	const std::wstring lNetLibrary = std::format(L"{}\\{}.dll", lPluginPath, Constants::NetLibraryName);

	try
	{
		Assembly ^ lAssembly = Assembly::LoadFrom(gcnew String(lNetLibrary.c_str()));
		return lAssembly->GetType(ManagedConstants::InitializerName);
	}
	catch(FileNotFoundException ^ e)
	{
		Console::WriteLine(e->Message);
	}
	catch(FileLoadException ^ e)
	{
		Console::WriteLine(e->Message);
	}

	return nullptr;
}

	bool invokePluginInitializer(Type ^ aPluginType, CwAPI3D::ControllerFactory* aFactory)
{
	Object ^ lPluginInstance = Activator::CreateInstance(aPluginType);
	auto lFactoryPointer = IntPtr(aFactory);
	auto lMethodArgs = gcnew array<Object ^>{lFactoryPointer};

	try
	{
		if(aPluginType->InvokeMember(ManagedConstants::InitializerHookName,
									 BindingFlags::InvokeMethod,
									 nullptr,
									 lPluginInstance,
									 lMethodArgs))
		{
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

	if(auto lPluginType = loadAssemblyAndGetType(aFactory);
	   lPluginType != nullptr)
	{
		return invokePluginInitializer(lPluginType, aFactory);
	}
	return false;
}
