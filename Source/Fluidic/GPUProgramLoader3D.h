/*
Copyright (c) 2010 Steven Leigh

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#include "GPUProgram.h"
#include <string>

namespace Fluidic
{
	/**
	 * Abstraction for GPU Programs. Loads program from a file, and sets params.
	 * This is more for convenience than speed - it's actually somewhat slower in the param lookups.
	 */
	class GPUProgramLoader3D
	{
	public:
		GPUProgramLoader3D(const std::string &cgHomeDir, CGcontext context, CGprofile vertexProfile, CGprofile fragmentProfile);
		GPUProgram *Advect();
		GPUProgram *Vorticity();
		GPUProgram *Inject();
		GPUProgram *Perturb();
		GPUProgram *F1Boundary();
		GPUProgram *F4Boundary();
		GPUProgram *Offset();
		GPUProgram *F1Jacobi();
		GPUProgram *F4Jacobi();
		GPUProgram *DivField();
		GPUProgram *SubtractPressureGradient();
		GPUProgram *ZCull();
		GPUProgram *Render();

		GPUProgram *RayCastVertex();
		GPUProgram *RayCastFragment();

	protected:
		const char *GetPathTo(char *program);
	private:
		std::string mCgHomeDir;
		CGcontext mCgContext;
		CGprofile mCgVertexProfile;
		CGprofile mCgFragmentProfile;
	};

}