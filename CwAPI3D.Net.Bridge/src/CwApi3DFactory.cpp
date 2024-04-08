
#include "CwApi3DFactory.h"
#include "AttributeController.h"
#include "BimController.h"
#include "ElementController.h"
#include "UtilityController.h"
#include "VisualizationController.h"
#include <stdexcept>

#include "CameraData.h"

CwAPI3D::Net::Bridge::CwApi3DFactory::CwApi3DFactory(System::IntPtr aFactoryPtr)
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
}

CwAPI3D::Net::Bridge::IElementController ^ CwAPI3D::Net::Bridge::CwApi3DFactory::getElementController()
{
	if(!mElementController)
	{
		mElementController = gcnew ElementController(System::IntPtr(mControllerFactory));
	}
	return mElementController;
}

CwAPI3D::Net::Bridge::IAttributeController ^ CwAPI3D::Net::Bridge::CwApi3DFactory::getAttributeController()
{
	if(!mAttributeController)
	{
		mAttributeController = gcnew AttributeController(System::IntPtr(mControllerFactory));
	}
	return mAttributeController;
}

CwAPI3D::Net::Bridge::IUtilityController ^ CwAPI3D::Net::Bridge::CwApi3DFactory::getUtilityController()
{
	if(!mUtilityController)
	{
		mUtilityController = gcnew UtilityController(System::IntPtr(mControllerFactory));
	}
	return mUtilityController;
}

CwAPI3D::Net::Bridge::IVisualizationController ^ CwAPI3D::Net::Bridge::CwApi3DFactory::getVisualizationController()
{
	if(!mVisualizationController)
	{
		mVisualizationController = gcnew VisualizationController(System::IntPtr(mControllerFactory));
	}
	return mVisualizationController;
}

CwAPI3D::Net::Bridge::IBimController ^ CwAPI3D::Net::Bridge::CwApi3DFactory::getBimController()
{
	if(!mBimController)
	{
		mBimController = gcnew BimController(System::IntPtr(mControllerFactory));
	}
	return mBimController;
}

CwAPI3D::Net::Bridge::ICameraData ^ CwAPI3D::Net::Bridge::CwApi3DFactory::getCameraData()
{
	const auto lCameraData = mControllerFactory->createCameraData();
	if(!lCameraData)
	{
		throw std::runtime_error("Could not create camera data");
	}
	return gcnew CameraData(lCameraData);
}
