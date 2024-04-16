#include "cwapi3d.net.visualization-controller.h"

#include <stdexcept>

#include "cwapi3d.net.camera-data.h"

CwAPI3D::Net::Bridge::VisualizationController::VisualizationController(System::IntPtr aFactoryPtr)
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

CwAPI3D::Net::Bridge::VisualizationController::~VisualizationController()
{
	this->!VisualizationController();
}

CwAPI3D::Net::Bridge::VisualizationController::!VisualizationController()
{
}

bool CwAPI3D::Net::Bridge::VisualizationController::isActive(elementId aElementID)
{
	return mVisualizationController->isActive(aElementID);
}

void CwAPI3D::Net::Bridge::VisualizationController::setActive(List<elementId> ^ aElementIDs)
{
	const auto lElementIDList = mControllerFactory->createEmptyElementIDList();
	for each(int aElementID in aElementIDs)
	{
		lElementIDList->append(aElementID);
	}
	mVisualizationController->setActive(lElementIDList);
}

void CwAPI3D::Net::Bridge::VisualizationController::setInActive(List<elementId> ^ aElementIDs)
{
	const auto lElementIDList = mControllerFactory->createEmptyElementIDList();
	for each(int aElementID in aElementIDs)
	{
		lElementIDList->append(aElementID);
	}
	mVisualizationController->setInactive(lElementIDList);
}

bool CwAPI3D::Net::Bridge::VisualizationController::isVisible(elementId aElementID)
{
	return mVisualizationController->isVisible(aElementID);
}

void CwAPI3D::Net::Bridge::VisualizationController::setVisible(List<elementId> ^ aElementIDs)
{
	const auto lElementIDList = mControllerFactory->createEmptyElementIDList();
	for each(int aElementID in aElementIDs)
	{
		lElementIDList->append(aElementID);
	}
	mVisualizationController->setVisible(lElementIDList);
}

void CwAPI3D::Net::Bridge::VisualizationController::hideAllElements()
{
	mVisualizationController->hideAllElements();
}

void CwAPI3D::Net::Bridge::VisualizationController::showAllElements()
{
	mVisualizationController->showAllElements();
}

bool CwAPI3D::Net::Bridge::VisualizationController::isPlane2D()
{
	return mVisualizationController->isPlane2d();
}

void CwAPI3D::Net::Bridge::VisualizationController::setCamera(ICameraData ^ aCameraData)
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

CwAPI3D::Net::Bridge::ICameraData ^ CwAPI3D::Net::Bridge::VisualizationController::getCamera()
{
	return gcnew CameraData(mVisualizationController->getCameraData());
}

void CwAPI3D::Net::Bridge::VisualizationController::refresh()
{
	mVisualizationController->refresh();
}
