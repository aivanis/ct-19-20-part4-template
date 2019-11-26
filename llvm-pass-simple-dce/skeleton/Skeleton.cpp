#define DEBUG_TYPE "opCounter"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/Local.h"
#include <vector>
using namespace llvm;
using namespace std;
namespace {
   struct SimpleDCE : public FunctionPass {
     static char ID;
     SimpleDCE() : FunctionPass(ID) {}
     std::map<std::string, int> instrCounter;
      // map mapping an opcode to the instruction count 
      // for example if "i" is a pointer to a instructions or iterator use:
      // instrCounter[i->getOpcodeName()] = 1;
      // to set count for that instruction opcode to 1

     void countInstructions(Function &F) {
       // ADD YOUR CODE (task 2)
       // update instrCounter
     }

     void printInstructionsCount() {
       std::map<std::string, int>::iterator i = instrCounter.begin();
       std::map<std::string, int>::iterator e = instrCounter.end();
       while (i != e) {
         errs() << i->first << ": " << i->second << "\n";
         i++;
       }
     }

     void recursivelyEliminateDeadCode(Function &F) {
       // ADD YOUR CODE (task 3)
       // eliminate dead code
     }

     virtual bool runOnFunction(Function &F) {
       errs() << "BEFORE DCE\n";
       //Count before dead code elimination here
       countInstructions(F);
       printInstructionsCount();
       instrCounter.clear();
       errs() << "DCE START\n";
       //Eliminate dead code and produce counts here
       //(You can use is instruction trivially dead)
       recursivelyEliminateDeadCode(F);
       countInstructions(F);
       printInstructionsCount();
       errs() << "DCE END\n";
       instrCounter.clear();
       return true;
     }
   };
}

char SimpleDCE::ID = 0;
static RegisterPass<SimpleDCE> X("mypass", "Simple dead code elimination");
