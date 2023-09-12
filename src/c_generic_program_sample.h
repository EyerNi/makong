#ifdef __GNUC__

#ifndef __CGPS_H__
#define __CGPS_H__

#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

/**/
#define cgps_form(x) form(x)
#define form(x) #x
#define CGPS_LOG cgps:%s

/**/
#define cgps_print(a, b...) printf(cgps_form(CGPS_LOG) a, "->", ##b)

/*?why mtrace shows "printf" cause mem leak?*/
#if /*1 fix mtrace shows mem leak*/ 0
#define printf(a, b...)
#endif

/**/
#define cgps_ns(name, mberType, mberName...) cgps_##name##_##mberType##_##mberName

/**/
#define CGPS_FUNC_DEF_START(output, funcname, input, arg...) \
  output funcname(input, ##arg)                              \
  {
#define CGPS_FUNC_DEF_END(x) }

/**/
#define CGPS_DEF(name)                        \
  typedef struct                              \
  {                                           \
    unsigned cgps_ns(name, starg, id);        \
    void (*cgps_ns(name, func, mberp))(void); \
  } cgps_ns(name, st), *cgps_ns(name, pst);

#define CGPS_IMPL(name)                                           \
  CGPS_FUNC_DEF_START(cgps_ns(name, pst),                         \
                      cgps_ns(name, func, new_obj),               \
                      void)                                       \
  return (cgps_ns(name, pst))malloc(sizeof(cgps_ns(name, st)));   \
  CGPS_FUNC_DEF_END(())                                           \
  CGPS_FUNC_DEF_START(void,                                       \
                      cgps_ns(name, func, del_obj),               \
                      cgps_ns(name, pst) obj)                     \
  return (void)free(obj);                                         \
  CGPS_FUNC_DEF_END(())                                           \
  CGPS_FUNC_DEF_START(void,                                       \
                      cgps_ns(name, func, set_obj),               \
                      cgps_ns(name, pst) obj, int val)            \
  cgps_print("obj seting...\n");                                  \
  (*obj).cgps_ns(name, starg, id) = val;                          \
  CGPS_FUNC_DEF_END(())                                           \
  CGPS_FUNC_DEF_START(void,                                       \
                      cgps_ns(name, func, get_obj),               \
                      cgps_ns(name, pst) obj)                     \
  cgps_print("%d\n", (*obj).cgps_ns(name, starg, id));            \
  CGPS_FUNC_DEF_END(())                                           \
  void cgps_ns(name, func, mberp)(void)                           \
  {                                                               \
    cgps_print("here\n");                                         \
  }                                                               \
  CGPS_FUNC_DEF_START(void,                                       \
                      cgps_ns(name, func, def_construct_obj),     \
                      cgps_ns(name, pst) obj)                     \
  cgps_print("default constructing...\n");                        \
  (*obj).cgps_ns(name, func, mberp) = cgps_ns(name, func, mberp); \
  (*obj).cgps_ns(name, starg, id) = 16;                           \
  CGPS_FUNC_DEF_END(())                                           \
  CGPS_FUNC_DEF_START(void,                                       \
                      cgps_ns(name, func, re_construct_obj),      \
                      cgps_ns(name, pst) obj, void (*p)(void))    \
  cgps_print("re constructing...\n");                             \
  (*obj).cgps_ns(name, func, mberp) = p;                          \
  CGPS_FUNC_DEF_END(())

#define CGPS_CLASS(name) \
  CGPS_DEF(name)         \
  CGPS_IMPL(name)

#endif
#endif
