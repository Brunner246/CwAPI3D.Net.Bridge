#include "ElementController.h"
#include "ApiUtils.h"
#include <stdexcept>

CwAPI3D_Net::ElementController::ElementController(System::IntPtr aFactoryPtr)
{
	if(aFactoryPtr == System::IntPtr::Zero)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	mControllerFactory = static_cast<CwAPI3D::ControllerFactory*>(aFactoryPtr.ToPointer());
	if(!mControllerFactory)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	mElementController = mControllerFactory->getElementController();
}

CwAPI3D_Net::ElementController::~ElementController()
{
	this->!ElementController();
}

CwAPI3D_Net::ElementController::!ElementController() { }

List<elementId> ^ CwAPI3D_Net::ElementController::getAllIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getAllIdentifiableElementIDs();
	return Utils::elementVectorToList<elementId>(lElementIds);
}

List<elementId> ^ CwAPI3D_Net::ElementController::getActiveIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getActiveIdentifiableElementIDs();
	return Utils::elementVectorToList<elementId>(lElementIds);
}

List<elementId> ^ CwAPI3D_Net::ElementController::getVisibleIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getVisibleIdentifiableElementIDs();
	return Utils::elementVectorToList<elementId>(lElementIds);
}

void CwAPI3D_Net::ElementController::addElementsToUndo(List<elementId> ^ aElementIDs, const Utils::undoType aUndoType)
{
	const auto lElementIdList = mControllerFactory->createEmptyElementIDList();

	for each(auto lItem in aElementIDs)
	{
		lElementIdList->append(lItem);
	}
	mElementController->addElementsToUndo(lElementIdList, aUndoType == Utils::undoType::add ? 1 : 2);
	lElementIdList->destroy();
}
