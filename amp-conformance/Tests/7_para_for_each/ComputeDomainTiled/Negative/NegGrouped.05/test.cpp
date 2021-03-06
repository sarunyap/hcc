//--------------------------------------------------------------------------------------
// File: test.cpp
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
// file except in compliance with the License.  You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OR
// CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
//
// See the Apache Version 2.0 License for specific language governing permissions
// and limitations under the License.
//
//--------------------------------------------------------------------------------------
//
/// <tags>P1</tags>
/// <summary>Test that tile extent dimension exceeding limit results in a compilation error. Test for 1D.</summary>
//#Expects: Error: error C3574
//#Expects: Error: test\.cpp\(37\).?:.*tiled_extent
//#Expects: Error: test\.cpp\(40\).?:.*tiled_extent

#include <amptest.h>
#include <climits>
using namespace Concurrency;

#define P_F_E(ext, D0) parallel_for_each(ext, [=](tiled_index<D0>) restrict(amp){int y = x;(void)y;})

int main()
{
	int x;

    tiled_extent<1025> ext1 = extent<1>(2050).tile<1025>();
	P_F_E(ext1, 1025);

	tiled_extent<INT_MAX> ext2 = extent<1>(INT_MAX).tile<INT_MAX>();
	P_F_E(ext2, INT_MAX);

    return runall_fail; // Should not have compiled.
}

