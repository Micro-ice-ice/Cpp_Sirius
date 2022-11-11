#pragma once
#include <iostream>

//для рассчета числа сочетаний
template<int N, int K>
constexpr int C = C<N - 1, K - 1> + C<N - 1, K>;

template<int N>
constexpr int C<N, 0> = 1;

template<int N>
constexpr int C<N, N> = 1;

template<>
constexpr int C<0, 0> = 1;

//для определения минуса 
template<int I>
constexpr int mminus = -2 * (I % 2) +1;

//рассчет коэффициента
template<int Coeff, int T, int I>
constexpr int coeff_f = Coeff * mminus<I> * C<T, I>;

//при I > N - K
template<int Coeff, int N, int K, int I, int ... Tail>
constexpr auto coeffs2 = coeffs2<Coeff, N, K, I + 1, 0, Tail ...>;

//Выход 2
template<int Coeff, int N, int K, int ... Tail>
constexpr auto coeffs2<Coeff, N, K, N, Tail ...> = {0, Tail ...};

//при I <= N - K
template<int Coeff, int N, int K, int T, int I, int ... Tail>
constexpr auto coeffs = coeffs<Coeff, N, K, T, I + 1, coeff_f<Coeff, N - K, I>, Tail ...>;

//переход в I > N - K
template<int Coeff, int N, int K, int T, int ... Tail>
constexpr auto coeffs<Coeff, N, K, T, T, Tail ...> = coeffs2<Coeff, N, K, T + 1, coeff_f<Coeff, N - K, N - K>, Tail ...>;

//Выход 1
template<int Coeff, int N, int K, int ... Tail>
constexpr auto coeffs<Coeff, N, K, N, N, Tail ...> = {coeff_f<Coeff, N - K, N>, Tail ...};

//вход в рекурсию I = 0
template<int N, int K>
constexpr auto bern_v = coeffs< C<N, K> * mminus<N-K>, N, K, N - K, 0>;












