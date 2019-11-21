Build:

    $ cd llvm-pass-xxx-dce
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ cd ..

Run simple pass:

    $ cd llvm-pass-simple-dce
    $ opt -O0 -load build/skeleton/libSkeletonPass.so -mem2reg ../tests_llvm/multi_func.ll -skeletonpass -S -o student_result.ll 2>student.stderr

Run liveness DCE pass:

    $ cd llvm-pass-my-dce
    $ opt -O0 -load build/skeleton/libSkeletonPass.so -mem2reg ../tests_llvm/multi_func.ll -live -S -o student_result.ll 2>student.stderr

This outputs a "student_result.ll" file with eliminated dead instructions and "student.stderr" with the liveness analysis output
