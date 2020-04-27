#include "timingprofile.h"

////////////////////////////////////////////////////////////////////////////////
// Timing utils
////////////////////////////////////////////////////////////////////////////////

static uint64_t freq_num   = 0;
static uint64_t freq_denom = 0;

// gets system data to determine clock characteristics
void init_clock_frequency (void)
{
    mach_timebase_info_data_t tb;

    if (mach_timebase_info (&tb) == KERN_SUCCESS && tb.denom != 0) {
        freq_num   = (uint64_t) tb.numer;
        freq_denom = (uint64_t) tb.denom;
    }
}

// adjust measurement to system characteristics
void get_ellapsed(uint64_t *time)
{
    *time = mach_absolute_time() - *time;
    *time *= freq_num;
    *time /= freq_denom;
}
