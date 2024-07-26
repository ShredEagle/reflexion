#pragma once

namespace ad {
namespace reflex {

template <class T_data, class T_witness>
concept can_be_described_to =
    requires(T_witness w, T_data d) { d.describeTo(w); };

template <class T_data, class T_witness>
concept can_be_described_to_by_fn =
    requires(T_witness w, T_data d) { describeTo(w, d); };

template <class T_witness, class T_data>
concept can_witness =
    requires(T_witness w, T_data d) { d.describeTo(w); };

template <class T_witness, class T_data>
concept can_witness_by_fn =
    requires(T_witness w, T_data d) { describeTo(w, d); };

} // namespace reflex
} // namespace ad
