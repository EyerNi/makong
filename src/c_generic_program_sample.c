#include "c_generic_program_sample.h"

CGPS_CLASS(sample_name);

CGPS_FUNC_DEF_LOG_START(void,thefunc,void)
{
  cgps_print("there\n");
}
CGPS_FUNC_DEF_LOG_END(())

CGPS_FUNC_DEF_START(int, main, void)
{
  mtrace();

  /*mem*/
  cgps_ns(sample_name, pst) sample_obj = cgps_ns(sample_name, func, new_obj)();

  /*default construct*/
  cgps_ns(sample_name, func, def_construct_obj)(sample_obj);
  /*print constructed val*/
  cgps_ns(sample_name, func, get_obj)(sample_obj);
  /*using constructed ptr func*/
  (*sample_obj).cgps_ns(sample_name, func, mberp)();

  /*using func*/
  cgps_ns(sample_name, func, set_obj)(sample_obj, 19);
  cgps_ns(sample_name, func, get_obj)(sample_obj);

  /*reconstruct ptr func*/
  cgps_ns(sample_name, func, re_construct_obj)(sample_obj, thefunc);
  (*sample_obj).cgps_ns(sample_name, func, mberp)();

  /*mem*/
  cgps_ns(sample_name, func, del_obj)(sample_obj);

  muntrace();
}
CGPS_FUNC_DEF_END(())
