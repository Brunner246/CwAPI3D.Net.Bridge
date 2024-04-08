#include "VisualizationController.h"

#include <stdexcept>

#include "CameraData.h"

CwAPI3D_Net::VisualizationController::VisualizationController(System::IntPtr aFactoryPtr)
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
	mVisualizationController = mControllerFactory->getVisualizationController();
}

CwAPI3D_Net::VisualizationController::~VisualizationController()
{
	this->!VisualizationController();
}

CwAPI3D_Net::VisualizationController::!VisualizationController()
{
}

bool CwAPI3D_Net::VisualizationController::isActive(int aElementID)
{
	return mVisualizationController->isActive(aElementID);
}

void CwAPI3D_Net::VisualizationController::setActive(List<int> ^ aElementIDs)
{
	const auto lElementIDList = mControllerFactory->createEmptyElementIDList();
	for each(int aElementID in aElementIDs)
	{
		lElementIDList->append(aElementID);
	}
	mVisualizationController->setActive(lElementIDList);
}

void CwAPI3D_Net::VisualizationController::setInActive(List<int> ^ aElementIDs)
{
	const auto lElementIDList = mControllerFactory->createEmptyElementIDList();
	for each(int aElementID in aElementIDs)
	{
		lElementIDList->append(aElementID);
	}
	mVisualizationController->setInactive(lElementIDList);
}

bool CwAPI3D_Net::VisualizationController::isVisible(int aElementID)
{
	return mVisualizationController->isVisible(aElementID);
}

void CwAPI3D_Net::VisualizationController::setVisible(List<int> ^ aElementIDs)
{
	const auto lElementIDList = mControllerFactory->createEmptyElementIDList();
	for each(int aElementID in aElementIDs)
	{
		lElementIDList->append(aElementID);
	}
	mVisualizationController->setVisible(lElementIDList);
}

void CwAPI3D_Net::VisualizationController::hideAllElements()
{
	mVisualizationController->hideAllElements();
}

void CwAPI3D_Net::VisualizationController::showAllElements()
{
	mVisualizationController->showAllElements();
}

bool CwAPI3D_Net::VisualizationController::isPlane2D()
{
	return mVisualizationController->isPlane2d();
}

void CwAPI3D_Net::VisualizationController::setCamera(ICameraData ^ aCameraData)
{
	const auto lCameraData = mControllerFactory->createCameraData();

	lCameraData->setPosition(aCameraData->getPosition()->toVector3D());
	lCameraData->setTarget(aCameraData->getTarget()->toVector3D());
	lCameraData->setUpVector(aCameraData->getUp()->toVector3D());
	lCameraData->setProjectionType(static_cast<CwAPI3D::Interfaces::ICwAPI3DCameraData::ProjectionType>(aCameraData->getProjectionType()));
	lCameraData->setFieldWidth(aCameraData->getFieldWidth());
	lCameraData->setFieldHeight(aCameraData->getFieldHeight());
	lCameraData->setFieldOfView(aCameraData->getFieldOfView());

	mVisualizationController->setCameraData(lCameraData);
}

CwAPI3D_Net::ICameraData ^ CwAPI3D_Net::VisualizationController::getCamera()
{
	return gcnew CameraData(mVisualizationController->getCameraData());
}

void CwAPI3D_Net::VisualizationController::refresh()
{
	mVisualizationController->refresh();
}
