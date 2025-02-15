/*
Copyright 2021 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_FUNCTIONAL_IDENTITY_HPP
#define BOOST_FUNCTIONAL_IDENTITY_HPP

#include <boost/config.hpp>
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#include <utility>
#endif

namespace boost {

struct identity {
    typedef void is_transparent;

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template<class T>
    BOOST_CONSTEXPR T&& operator()(T&& value) const BOOST_NOEXCEPT {
        return std::forward<T>(value);
    }
#else
    template<class T>
    BOOST_CONSTEXPR const T& operator()(const T& value) const BOOST_NOEXCEPT {
        return value;
    }

    template<class T>
    BOOST_CONSTEXPR T& operator()(T& value) const BOOST_NOEXCEPT {
        return value;
    }
#endif
};

} // boost

#endif
