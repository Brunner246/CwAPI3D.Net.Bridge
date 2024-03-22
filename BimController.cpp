#include "BimController.h"

#include <stdexcept>

#include "IfcTypeMapper.h"
#include <msclr/marshal_cppstd.h>

CwAPI3D_CLI::BimController::BimController(System::IntPtr aFactoryPtr)
{
	if(aFactoryPtr == System::IntPtr::Zero)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	const auto lControllerFactory = static_cast<CwAPI3D::ControllerFactory*>(aFactoryPtr.ToPointer());
	mBimController = lControllerFactory->getBimController();
}

String ^ CwAPI3D_CLI::BimController::getIfcTypeDisplayString(const int aElementId)
{
	const auto lIfcType = mBimController->getIfc2x3ElementType(aElementId);
	const auto lIfcTypeString = mBimController->getIfc2x3ElementTypeDisplayString(lIfcType);
	return gcnew String(lIfcTypeString->data());
}

int CwAPI3D_CLI::BimController::getElementIdFromIfcBase64Guid(String ^ aIfcBase64Guid)
{
	const std::wstring lNativeString = msclr::interop::marshal_as<std::wstring>(aIfcBase64Guid);
	return static_cast<int>(mBimController->getElementIdFromIfcBase64Guid(lNativeString.c_str()));
}

String ^ CwAPI3D_CLI::BimController::getIfcBase64Guid(int aElementId)
{
	const auto lIfcBase64Guid = mBimController->getIfcBase64Guid(aElementId);
	return gcnew String(lIfcBase64Guid->data());
}

CwAPI3D_CLI::EBimIfcType CwAPI3D_CLI::BimController::getIfcType(const int aElementId)
{
	const auto lIfcType = mBimController->getIfc2x3ElementType(aElementId);
	return Utils::mapIfcType(lIfcType);
}
