//
// Created by Cuong Nguyen on 24/9/22.
//

#ifndef RE_CHECK_H
#define RE_CHECK_H

#include <assert.h>

#define check_null(e) assert((e) == NULL)
#define check_not_null(e) assert((e) != NULL)
#define check_eq(a, b) assert((a) == (b))
#define check_ineq(a, b) assert((a) != (b))

#endif //RE_CHECK_H
