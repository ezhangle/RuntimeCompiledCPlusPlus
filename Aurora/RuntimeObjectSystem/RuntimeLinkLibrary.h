//
// Copyright (c) 2010-2011 Matthew Jack and Doug Binks
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#pragma once

#ifndef RUNTIMELINKLIBRARY_INCLUDED
#define RUNTIMELINKLIBRARY_INCLUDED


#ifndef RCCPPOFF

#include "RuntimeTracking.h"

namespace
{


#define RUNTIME_COMPILER_LINKLIBRARY_BASE( LIBRARY, N ) \
	template<> struct RuntimeTracking< N + 1 >  : RuntimeTracking< N >\
	{ \
		RuntimeTracking( size_t max ) : RuntimeTracking<N>( max ) {} \
		RuntimeTracking< N + 1 >() : RuntimeTracking<N>( N + 1 ) {} \
		virtual RuntimeTackingInfo GetTrackingInfo( size_t Num_ ) const \
		{ \
			if( Num_ <= N ) \
			{ \
				if( Num_ == N ) \
				{ \
					RuntimeTackingInfo info = RuntimeTackingInfo::GetNULL(); \
					info.linkLibrary = LIBRARY; \
					return info; \
				} \
				else return this->RuntimeTracking< N >::GetTrackingInfo( Num_ ); \
			} \
			else return RuntimeTackingInfo::GetNULL(); \
		} \
	}; \

#define RUNTIME_COMPILER_LINKLIBRARY( LIBRARY ) namespace { RUNTIME_COMPILER_LINKLIBRARY_BASE( LIBRARY, __COUNTER__ - COUNTER_OFFSET ) }

}
#else
#define RUNTIME_COMPILER_LINKLIBRARY( LIBRARY )
#endif //RCCPPOFF


#endif //RUNTIMELINKLIBRARY_INCLUDED
