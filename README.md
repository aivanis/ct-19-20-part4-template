Build (it is recommended to place the build repository outside the src folder and add it to .gitignore):

    $ mkdir build-xxx
    $ cd build-xxx
    $ cmake ../src/llvm/llvm-pass-xxx
    $ make

Run pass:

    $ cd llvm-pass-xxx-dce
    $ opt -O0 -load build-xxx/skeleton/libSkeletonPass.so -mem2reg src/llvm/tests_llvm/multi_func.ll -mypass -S -o student_result.ll 2>student.stderr


This outputs a "student_result.ll" file with eliminated dead instructions and "student.stderr" with the liveness analysis output
