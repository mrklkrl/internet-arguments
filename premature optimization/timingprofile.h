//
//  timingprofile.h
//  noobs
//
//  Created by Michael Cole on 4/26/20.
//  Copyright © 2020 Michael Cole. All rights reserved.
//

#ifndef timingprofile_h
#define timingprofile_h

#include <stdint.h>
#include <inttypes.h>
#include <mach/mach_time.h>


void init_clock_frequency (void);
void get_ellapsed(uint64_t *time);
#endif /* timingprofile_h */
