#ifndef SDLCPPT_UTILS_H
#define SDLCPPT_UTILS_H

#include <cstdint>

/// \brief Find the unsigned delta of two uint32_t values.
/// \param value_a One of the uint32_t values to be evaluated.
/// \param value_b The other uint32_t value to be evaluated.
/// \returns The unsigned delta of the two uint32_t values.
inline uint32_t unsigned_delta(uint32_t value_a, uint32_t value_b)
{
  return (value_a > value_b) ? value_a - value_b : value_b - value_a;
}

#endif // SDLCPPT_UTILS_H
