#include "cwapi3d.net.attribute-ontroller.h"

#include <stdexcept>

CwAPI3D::Net::Bridge::AttributeController::AttributeController(System::IntPtr aFactoryPtr)
{
	if(aFactoryPtr == System::IntPtr::Zero)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	const auto lControllerFactory = static_cast<CwAPI3D::ControllerFactory*>(aFactoryPtr.ToPointer());
	if(!lControllerFactory)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	mAttributeController = lControllerFactory->getAttributeController();
}

CwAPI3D::Net::Bridge::AttributeController::~AttributeController()
{
	this->!AttributeController();
}

CwAPI3D::Net::Bridge::AttributeController::!AttributeController() { }

System::String ^ CwAPI3D::Net::Bridge::AttributeController::getName(elementId aElementId)
{
	const auto lName = mAttributeController->getName(static_cast<uint64_t>(aElementId));
	return gcnew System::String(lName->data());
}
