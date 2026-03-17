/*===-- llvm-c/SplitModule.h - SplitModule C Interface -----------*- C++ -*-===*\
|*                                                                            *|
|* Part of the LLVM Project, under the Apache License v2.0 with LLVM          *|
|* Exceptions.                                                                *|
|* See https://llvm.org/LICENSE.txt for license information.                  *|
|* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception                    *|
|*                                                                            *|
|*===----------------------------------------------------------------------===*|
|*                                                                            *|
|* This header declares the C interface to module splitting.                  *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifndef LLVM_C_SPLITMODULE_H
#define LLVM_C_SPLITMODULE_H

#include "llvm-c/ExternC.h"
#include "llvm-c/Types.h"
#include "llvm-c/Visibility.h"

LLVM_C_EXTERN_C_BEGIN

/**
 * @defgroup LLVMCSplitModule Split Module
 * @ingroup LLVMC
 *
 * @{
 */

/**
 * Splits the given module into N linkable partitions. The Callback is called N
 * times, each time passing a new module partition. The module M is not modified
 * and each partition can be compiled independently.
 *
 * @param M            The module to split.
 * @param N            The number of partitions to split into.
 * @param Callback     Called for each partition with the partition module and
 *                     the user-provided UserData pointer.
 * @param UserData     Passed to each invocation of Callback.
 */
LLVM_C_ABI void LLVMSplitModule(LLVMModuleRef M, unsigned N,
                                 void (*Callback)(LLVMModuleRef MPart,
                                                  void *UserData),
                                 void *UserData);

/**
 * @}
 */

LLVM_C_EXTERN_C_END

#endif
