// Function Definition/Implementation

// Maximum Func 
int max (int a,int b)
{
  if (a>b)
    return a;
  else
    return b;
}

// Minimum Func
/*
(Minimum Func is defined here , but the during the linking time it will check for func definition on all .cpp file in a directory,
so the func definition can be anywhere one time according to OneDefintionRule[ODR], but it must be declared on header file [".h"])

in this case min func is decalred on "compare.h" and defined on "some_other_file.cpp" 
*/ 
