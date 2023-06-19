#include "common.h"

typedef struct {
  uint32_t time[100];
  uint32_t stacklevel;
} ocpp_profile_t;

typedef struct {
  uint32_t version;
  uint32_t size;
  uint32_t length;

  ocpp_profile_t *profile;

} ocpp_cp_t;

ocpp_cp_t      evar_cp;
ocpp_profile_t welpo_profile[2] = {
    [0] = {
           .time = {
            0,
        },
           .stacklevel = 3},
    [1] = {.time = {
               1,
           },
           .stacklevel = 4},
};

int main()
{
  warn("Start");

  info("welpo_profile[1].stacklevel=%d", welpo_profile[1].stacklevel);

  evar_cp.profile = welpo_profile;

  info("evar_cp[0].stacklevel=%d", evar_cp.profile[0].stacklevel);
  info("evar_cp[1].stacklevel=%d", evar_cp.profile[1].stacklevel);
  warn("End");
  return 0;
}
