//===-- SplitModuleC.cpp - C Interface for SplitModule --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm-c/SplitModule.h"
#include "llvm/IR/Module.h"
#include "llvm/Transforms/Utils/SplitModule.h"

using namespace llvm;

void LLVMSplitModule(LLVMModuleRef M, unsigned N,
                     void (*Callback)(LLVMModuleRef MPart, void *UserData),
                     void *UserData) {
  SplitModule(*unwrap(M), N,
              [Callback, UserData](std::unique_ptr<Module> MPart) {
                Callback(wrap(MPart.release()), UserData);
              });
}
