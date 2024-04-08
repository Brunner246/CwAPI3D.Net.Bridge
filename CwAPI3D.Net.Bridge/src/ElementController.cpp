#include "ElementController.h"
#include "ApiUtils.h"
#include <stdexcept>

CwAPI3D::Net::Bridge::ElementController::ElementController(System::IntPtr aFactoryPtr)
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

CwAPI3D::Net::Bridge::ElementController::~ElementController()
{
	this->!ElementController();
}

CwAPI3D::Net::Bridge::ElementController::!ElementController() { }

List<elementId> ^ CwAPI3D::Net::Bridge::ElementController::getAllIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getAllIdentifiableElementIDs();
	return CwAPI3D_Net::Utils::elementVectorToList<elementId>(lElementIds);
}

List<elementId> ^ CwAPI3D::Net::Bridge::ElementController::getActiveIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getActiveIdentifiableElementIDs();
	return CwAPI3D_Net::Utils::elementVectorToList<elementId>(lElementIds);
}

List<elementId> ^ CwAPI3D::Net::Bridge::ElementController::getVisibleIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getVisibleIdentifiableElementIDs();
	return CwAPI3D_Net::Utils::elementVectorToList<elementId>(lElementIds);
}

void CwAPI3D::Net::Bridge::ElementController::addElementsToUndo(List<elementId> ^ aElementIDs, const CwAPI3D_Net::Utils::undoType aUndoType)
{
	const auto lElementIdList = mControllerFactory->createEmptyElementIDList();

	for each(auto lItem in aElementIDs)
	{
		lElementIdList->append(lItem);
	}
	mElementController->addElementsToUndo(lElementIdList, aUndoType == CwAPI3D_Net::Utils::undoType::add ? 1 : 2);
	lElementIdList->destroy();
}
