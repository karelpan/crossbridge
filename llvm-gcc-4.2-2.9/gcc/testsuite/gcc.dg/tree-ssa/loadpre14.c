/* { dg-do compile } */ 
/* { dg-options "-O2 -fdump-tree-pre-stats" } */
/* LLVM LOCAL test not applicable */
/* { dg-require-fdump "" } */
typedef int type[2];
int main(type *a, int argc)
{
  type c = {0, 1};
  int d, e;
  
  /* Should be able to eliminate the second load of *a along the main path. */
  d = (*a)[0];
  if (argc)
    {
      a = &c;
    }
  e = (*a)[0];
  return d + e;
}
/* { dg-final { scan-tree-dump-times "Eliminated: 1" 1 "pre" { xfail *-*-* } } } */
/* { dg-final { cleanup-tree-dump "pre" } } */
