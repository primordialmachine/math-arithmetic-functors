///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Arithmetic Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <type_traits>

namespace primordialmachine {

template<typename OPERAND, typename ENABLED = void>
struct square_root_functor;

template<typename OPERAND>
auto
square_root(const OPERAND& operand)
  -> decltype(square_root_functor<OPERAND>()(operand))
{
  return square_root_functor<OPERAND>()(operand);
}

template<typename T, typename ENABLED = void>
struct has_square_root_functor
{
  static constexpr bool value = false;
}; // struct has_square_root_functor

template<typename A>
constexpr bool has_square_root_functor_v =
  has_square_root_functor<square_root_functor<A>>::value;

template<typename A>
struct has_square_root_functor<square_root_functor<A>,
                               decltype(typeid(square_root_functor<A>), void())>
{
  static constexpr bool value = true;
}; // struct has_square_root_functor

} // namespace primordialmachine