#pragma once

namespace CwAPI3D::Net::Bridge
{
public
	enum class EBimIfcType
	{
		none,
		ifcBeam,
		ifcColumn,
		ifcCurtainWall,
		ifcDoor,
		ifcMember,
		ifcPlate,
		ifcRailing,
		ifcRamp,
		ifcRampFlight,
		ifcRoof,
		ifcSlab,
		ifcStair,
		ifcStairFlight,
		ifcWall,
		ifcWallStandardCase,
		ifcWindow,
		ifcBuildingElementProxy,
		ifcChimney,
		ifcCovering,
		ifcFooting,
		ifcFurnishingElement,
		ifcOpeningElement,
		ifcSpace,
		ifcFlowSegment,
		ifcBuildingElementPart,
		ifcDiscreteAccessory,
		ifcFastener,
		ifcMechanicalFastener,
	};
} // namespace CwAPI3D_Net
