// Author: Michael Brunner

#include <format>
#include <string>
#include "CwAPI3D.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;


CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
    if (!aFactory)
    {
        return false;
    }
    const auto lPluginPath = aFactory->getUtilityController()->getPluginPath()->data();
    constexpr auto lNetLibraryName = L"CWAPI3D_NET.dll";
    const std::wstring lNetLibrary = std::format(L"{}\\{}", lPluginPath, lNetLibraryName);

    try
    {
        Assembly^ lAssembly = Assembly::LoadFrom(gcnew String(lNetLibrary.c_str()));
        if (Type^ lPluginType = lAssembly->GetType("CwAPI3D_NET.Initializer");
            lPluginType != nullptr)
        {
            Object^ lPluginInstance = Activator::CreateInstance(lPluginType);
            auto lFactoryPointer = IntPtr(aFactory);
            auto lMethodArgs = gcnew array<Object^>{lFactoryPointer};
            if (const bool lResult = static_cast<bool>(lPluginType->InvokeMember("Initialize",
                    BindingFlags::InvokeMethod,
                    nullptr,
                    lPluginInstance,
                    lMethodArgs));
                lResult)
            {
                Console::WriteLine("Plugin initialization successful");
                return true;
            }
            aFactory->getUtilityController()->printMessage(L"Plugin initialization failed");
            return false;
        }
        aFactory->getUtilityController()->printMessage(L"Plugin initialization failed");
        return false;
    }
    catch (FileNotFoundException^ e)
    {
        Console::WriteLine(e->Message);
    }
    catch (FileLoadException^ e)
    {
        Console::WriteLine(e->Message);
    }
    catch (TargetInvocationException^ e)
    {
        Console::WriteLine(e->Message);
        return false;
    }

    Console::WriteLine("Failed to unblock file. Please ensure you have the necessary permissions.");
    
    return false;
}
