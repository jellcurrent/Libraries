#pragma once

/*
 * @file cxx20.hpp
 * @brief C++20 features
 */

#if __cplusplus <= 201703L

#if __has_include(<bit>)
#include <bit>
#endif

#include <vector>

namespace std {

/*
 * @fn erase_if
 * @brief Erase the elements of a container that do not satisfy the condition.
 * @param __cont Container.
 * @param __pred Predicate.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove_if(__cont.begin(), __cont.end(), __pred),
               __cont.end());
  return __osz - __cont.size();
}

/*
 * @fn erase
 * @brief Erase the elements of a container that are equal to the given value.
 * @param __cont Container.
 * @param __value Value.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove(__cont.begin(), __cont.end(), __value),
               __cont.end());
  return __osz - __cont.size();
}

}  // namespace std

#endif
