//===-- driver/cl_options_instrumentation.h --------------------*-  C++ -*-===//
//
//                         LDC – the LLVM D compiler
//
// This file is distributed under the BSD-style LDC license. See the LICENSE
// file for details.
//
//===----------------------------------------------------------------------===//
//
// Defines the LDC command line options related to instrumentation, such as PGO
// -finstrument-functions, etc.
// Options for the instrumentation for the sanitizers is not part of this.
//
//===----------------------------------------------------------------------===//

#ifndef LDC_DRIVER_CL_OPTIONS_INSTRUMENTATION_H
#define LDC_DRIVER_CL_OPTIONS_INSTRUMENTATION_H

#include "gen/cl_helpers.h"

namespace opts {
namespace cl = llvm::cl;

extern cl::opt<bool> instrumentFunctions;

/// This initializes the instrumentation options, and checks the validity of the
/// commandline flags. targetTriple should be initialized before calling this.
/// It should be called only once.
void initializeInstrumentationOptionsFromCmdline();

enum PGOKind {
  PGO_None,
  PGO_ASTBasedInstr,
  PGO_ASTBasedUse,
  PGO_IRBasedInstr,
  PGO_IRBasedUse,
};
extern PGOKind pgoMode;
inline bool isInstrumentingForPGO() {
  return pgoMode == PGO_ASTBasedInstr || pgoMode == PGO_IRBasedInstr;
}
inline bool isUsingPGOProfile() {
  return pgoMode == PGO_ASTBasedUse || pgoMode == PGO_IRBasedUse;
}
inline bool isInstrumentingForASTBasedPGO() {
  return pgoMode == PGO_ASTBasedInstr;
}
inline bool isUsingASTBasedPGOProfile() { return pgoMode == PGO_ASTBasedUse; }
inline bool isInstrumentingForIRBasedPGO() {
  return pgoMode == PGO_IRBasedInstr;
}
inline bool isUsingIRBasedPGOProfile() { return pgoMode == PGO_IRBasedUse; }

} // namespace opts
#endif // LDC_DRIVER_CL_OPTIONS_INSTRUMENTATION_H
