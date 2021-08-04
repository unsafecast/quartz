#define BuildFileC(_X) Compile(_X)
#define BuildFileAsm(_X) Assemble(_X)
#include "./sources.h"
#undef BuildFileC
#undef BuildFileAsm

#define BuildFileC(_X) printf("build/" _X ".o ")
#define BuildFileAsm BuildFileC
Link(Target);
#include "./sources.h"
printf("\n");
#undef BuildFileC
#undef BuildFileAsm

