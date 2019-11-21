#define DEBUG_TYPE "opCounter"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instructions.h"
#include <vector>
#include <set>
using namespace llvm;
using namespace std;
namespace
{
struct MyDCE : public FunctionPass
{
  static char ID;
  MyDCE() : FunctionPass(ID) {}
  // sets used in LVA
  std::map<Value *, std::set<Value *>> succ;
  std::map<Value *, std::set<Value *>> use;
  std::map<Value *, std::set<Value *>> def;
  std::map<Value *, std::set<Value *>> in;
  std::map<Value *, std::set<Value *>> out;
  // these sets map from a memory address (pointer) of the instructions to memory addresses of the instructions in the set   
  // "in" set will be used for printing the results of liveness analysis
  // if you use iterators you need to dereference the iterator using * operator and get the address of the instruction using & operator
  // example to initalise "in" and "out" sets to empty for every instruction in the block:
  /*
  for (BasicBlock::iterator i = bb->begin(), e = bb->end(); i != e; i++)
  {
    // initialise in and out sets
    std::set<Value *> emptyInSet, emptyOutSet;
    in[&*i] = emptyInSet;
    out[&*i] = emptyOutSet;
  }
  */


  void performLivenessAnalysis(Function &F)
  {
    // ADD CODE HERE
    // modify "in" set as well as other sets
  }

  

  void recursivelyEliminateDeadCode(Function &F)
  {
    // ADD CODE HERE
    // you may need to run liveness analisis here as well
    // remember to clear the sets
  }

  virtual bool runOnFunction(Function &F)
  {
    // implementation of LVA
    performLivenessAnalysis(F);


    /// print liveness set 
    for (Function::iterator bb = F.begin(), end = F.end(); bb != end; bb++)
    {
      for (BasicBlock::iterator i = bb->begin(), e = bb->end(); i != e; i++)
      {
        // skip phi
        if (dyn_cast<PHINode>(i)) continue;
        auto operatorSet = in[&*i];
        errs() << "{";
        for (auto oper = operatorSet.begin(); oper != operatorSet.end(); oper++)
        {
          auto op = *oper;
          if (oper != operatorSet.begin())
          {
            errs() << ", ";
          }
          (*oper)->printAsOperand(errs(), false);
        }
        errs() << "}\n";
      }
    }
    errs() << "{}\n";


    // eliminate dead code
    recursivelyEliminateDeadCode(F);

    return true;
  }
};
} // namespace

char MyDCE::ID = 0;
static RegisterPass<MyDCE> X("live", "My dead code elimination");
