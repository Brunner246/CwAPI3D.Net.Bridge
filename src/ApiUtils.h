#pragma once
#include "typedefs.h"

using namespace System::Collections::Generic;

namespace CwAPI3D_CLI::Utils
{
	template<typename T>
		List<elementId> ^
		elementVectorToList(CwAPI3D::Interfaces::ICwAPI3DElementIDList* aElementIds) {
			auto lIds = gcnew List<T>();
			for(decltype(aElementIds->count()) lIt{0}; lIt < aElementIds->count(); ++lIt)
			{
				lIds->Add(static_cast<T>(aElementIds->at(lIt)));
			}
			return lIds;
		}

		public enum class undoType {
			add,
			modify,
		};

	// generic<class ItemType> where ItemType : CwAPI3D::Interfaces::ICwAPI3DElementIDList
	// List<int>^ elementVectorToList(ItemType* aElementIds)
	// {
	//     auto lIds = gcnew List<int>();
	//     for (decltype(aElementIds->count()) lIt{0}; lIt < aElementIds->count(); ++lIt)
	//     {
	//         lIds->Add(static_cast<int>(aElementIds->at(lIt)));
	//     }
	//     return lIds;
	// }

} // namespace CwAPI3D_CLI::Utils
