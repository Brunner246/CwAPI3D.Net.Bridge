#include "AttributeController.h"

#include <stdexcept>

CwAPI3D_CLI::AttributeController::AttributeController(System::IntPtr aFactoryPtr)
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

CwAPI3D_CLI::AttributeController::~AttributeController() { this->!AttributeController(); }

CwAPI3D_CLI::AttributeController::!AttributeController() { }

String ^ CwAPI3D_CLI::AttributeController::getName(int aElementID)
{
	const auto lName = mAttributeController->getName(static_cast<uint64_t>(aElementID));
	return gcnew String(lName->data());
}
