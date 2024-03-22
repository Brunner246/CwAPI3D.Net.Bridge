#include "ElementController.h"
#include "ApiUtils.h"
#include <stdexcept>

CwAPI3D_CLI::ElementController::ElementController(System::IntPtr aFactoryPtr)
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

CwAPI3D_CLI::ElementController::~ElementController() { this->!ElementController(); }

CwAPI3D_CLI::ElementController::!ElementController() { }

List<int> ^ CwAPI3D_CLI::ElementController::getAllIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getAllIdentifiableElementIDs();
	return Utils::elementVectorToList<int>(lElementIds);
}

List<int> ^ CwAPI3D_CLI::ElementController::getActiveIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getActiveIdentifiableElementIDs();
	return Utils::elementVectorToList<int>(lElementIds);
}

List<int> ^ CwAPI3D_CLI::ElementController::getVisibleIdentifiableElementIDs()
{
	const auto lElementIds = mElementController->getVisibleIdentifiableElementIDs();
	return Utils::elementVectorToList<int>(lElementIds);
}

void CwAPI3D_CLI::ElementController::addElementsToUndo(List<int> ^ aElementIDs, Utils::undoType aUndoType)
{
	const auto lElementIdList = mControllerFactory->createEmptyElementIDList();

	for each(auto item in aElementIDs)
	{
		lElementIdList->append(item);
	}
	mElementController->addElementsToUndo(lElementIdList, aUndoType == Utils::undoType::add ? 1 : 2);
	lElementIdList->destroy();
}
