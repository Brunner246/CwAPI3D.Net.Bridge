#include "cwapi3d.net.bim-controller.h"
#include "cwapi3d.net.ifc-type-mapper.h"
#include <stdexcept>
#include <msclr/marshal_cppstd.h>

CwAPI3D::Net::Bridge::BimController::BimController(System::IntPtr aFactoryPtr)
{
	if(aFactoryPtr == System::IntPtr::Zero)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	const auto lControllerFactory = static_cast<CwAPI3D::ControllerFactory*>(aFactoryPtr.ToPointer());
	mBimController = lControllerFactory->getBimController();
}

System::String ^ CwAPI3D::Net::Bridge::BimController::getIfcTypeDisplayString(const elementId aElementId)
{
	const auto lIfcType = mBimController->getIfc2x3ElementType(aElementId);
	const auto lIfcTypeString = mBimController->getIfc2x3ElementTypeDisplayString(lIfcType);
	return gcnew System::String(lIfcTypeString->data());
}

elementId CwAPI3D::Net::Bridge::BimController::getElementIdFromIfcBase64Guid(System::String ^ aIfcBase64Guid)
{
	const std::wstring lNativeString = msclr::interop::marshal_as<std::wstring>(aIfcBase64Guid);
	return static_cast<int>(mBimController->getElementIdFromIfcBase64Guid(lNativeString.c_str()));
}

System::String ^ CwAPI3D::Net::Bridge::BimController::getIfcBase64Guid(const elementId aElementId)
{
	const auto lIfcBase64Guid = mBimController->getIfcBase64Guid(aElementId);
	return gcnew System::String(lIfcBase64Guid->data());
}

CwAPI3D::Net::Bridge::EBimIfcType CwAPI3D::Net::Bridge::BimController::getIfcType(const elementId aElementId)
{
	const auto lIfcType = mBimController->getIfc2x3ElementType(aElementId);
	return CwAPI3D_Net::Utils::mapIfcType(lIfcType);
}
