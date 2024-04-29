// Author: Michael Brunner

#include <format>
#include <string>
#include "CwAPI3D.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

public
ref class ManagedConstants sealed
{
	public:
		String ^ LibraryName = "examplelib";
		String ^ InitializerNamespace = "examplelib";
		//	String ^ InitializerName = String::Format("{0}.{1}", InitializerNamespace, "Initializer");
		String ^ InitializerHookName = "Initialize";

		property String ^ InitializerName {
				String ^ get() {
						return String::Format("{0}.{1}", InitializerNamespace, "Initializer");
				}
		}
};

ManagedConstants ^ readConfigsFromTxt(const char* aFilePath) {
		auto lConstants = gcnew ManagedConstants();
		try
		{
				const auto lFile = std::format("{}\\library.config", aFilePath);
				Console::WriteLine(String::Format(".config file path\t{0}", gcnew String(lFile.c_str())));
				auto lFilePath = gcnew String(lFile.c_str());
				StreamReader ^ lStreamReader = File::OpenText(lFilePath);
				String ^ lString;
				while((lString = lStreamReader->ReadLine()) != nullptr)
				{
						if(array<String ^> ^ lParts = lString->Split('='); lParts->Length == 2)
						{
								if(lParts[0] == "netLibraryName")
								{
										lConstants->LibraryName = lParts[1];
								}
								else if(lParts[0] == "initializerNamespace")
								{
										lConstants->InitializerNamespace = lParts[1];
								}
						}
				}
				return lConstants;
		}
		catch(FileNotFoundException ^ e)
		{
				Console::WriteLine(e->Message);
		}
		catch(DirectoryNotFoundException ^ e)
		{
				Console::WriteLine(e->Message);
		}
		return lConstants;
}

	Type
	^ loadAssemblyAndGetType(CwAPI3D::ControllerFactory* aFactory, ManagedConstants ^ % aConstants) {
				const auto lPluginPath = aFactory->getUtilityController()->getPluginPath()->data();

				auto lNativeString = static_cast<const wchar_t*>(Marshal::StringToHGlobalUni(aConstants->LibraryName).ToPointer());
				const std::wstring lNetLibrary = std::format(L"{}\\{}.dll", lPluginPath, lNativeString);
				Console::WriteLine(String::Format(".net library name\t{0}", gcnew String(lNetLibrary.c_str())));
				Marshal::FreeHGlobal(IntPtr((void*)lNativeString)); // StringToHGlobalUni allocates memory that has to bee freed

				try
				{
						Assembly ^ lAssembly = Assembly::LoadFrom(gcnew String(lNetLibrary.c_str()));
						return lAssembly->GetType(aConstants->InitializerName);
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

	bool invokePluginInitializer(Type ^ aPluginType, CwAPI3D::ControllerFactory* aFactory, ManagedConstants ^ % aConstants)
{
		Object ^ lPluginInstance = Activator::CreateInstance(aPluginType);
		auto lFactoryPointer = IntPtr(aFactory);
		auto lMethodArgs = gcnew array<Object ^>{lFactoryPointer};

		try
		{
				if(aPluginType->InvokeMember(aConstants->InitializerHookName,
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
				Console::WriteLine("CwAPI3D::ControllerFactory is null");
				return false;
		}
		auto lConstants = readConfigsFromTxt(aFactory->getUtilityController()->getPluginPath()->narrowData());
		if(auto lPluginType = loadAssemblyAndGetType(aFactory, lConstants);
			 lPluginType != nullptr)
		{
				return invokePluginInitializer(lPluginType, aFactory, lConstants);
		}
		Console::WriteLine("could not load library");
		return false;
}
