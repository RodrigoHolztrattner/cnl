
//          Copyright John McFarlane 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CNL_IMPL_SCALED_INTEGER_IS_NUMBER_H)
#define CNL_IMPL_SCALED_INTEGER_IS_NUMBER_H

#include "../number/is_number.h"
#include "declaration.h"

/// compositional numeric library
namespace cnl {
    namespace _impl {
        template<typename Rep, class Scale>
        struct is_number<scaled_integer<Rep, Scale>>
            : public std::true_type {
        };
    }
}

#endif  // CNL_IMPL_SCALED_INTEGER_IS_NUMBER_H
