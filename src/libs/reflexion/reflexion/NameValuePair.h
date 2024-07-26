#pragma once
#include <utility>

namespace ad {
namespace reflex {

template <class T_type>
using Nvp = std::pair<const char *, T_type *>;

} // namespace reflex
} // namespace ad

#define NVP(name)                                                              \
    ad::reflex::Nvp<std::decay_t<decltype(name)>> { #name, &name }
#define NVP_NAMED(name, value)                                                 \
    ad::reflex::Nvp<std::decay_t<decltype(name)>> { #name, &value }
#define NVP_FN(name)                                                           \
    ad::reflex::Nvp<std::decay_t<decltype(name())>> { #name, &name() }
