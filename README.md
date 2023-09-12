# makong
--rec C macro learning
  for fun...

# 12/9/2023 
  disabled the printf in .h the mem leak msg will gone...but why?
#  
--make
  gcc src/c_generic_program_sample.c -c -Wall -g -o c_generic_program_sample.o
  gcc c_generic_program_sample.o -g -o a.o
--./a.o
  default constructing...
  -> 16
  -> here
  obj seting...
  -> 19
  re constructing...
  -> there
--mtrace a.o mtrace.log
  Memory not freed:
  -----------------
  Address     Size     Caller
  0x0000000000bc0470    0x400  at 0x7f07bdb631e5

