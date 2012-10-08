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


#ifndef IASSETSYSTEM_INCLUDED
#define IASSETSYSTEM_INCLUDED

#include "Definitions.inl"

struct IAssetSystem
{
	virtual IAURenderableMesh* CreateRenderableMeshFromFile( const char* pFilename ) = 0;
	virtual void DestroyRenderableMesh(IAURenderableMesh* pMesh) = 0; // needed so memory allocation and deletion happens in same DLL

	virtual CalSound* CreateSoundFromFile( const char* pFilename, bool looping ) = 0;
	virtual void DestroySound( CalSound* pSound ) = 0;
    virtual const char* GetAssetDirectory() const = 0;
};

#endif //IASSETSYSTEM_INCLUDED