#ifndef SDLCPPT_UTILS_H
#define SDLCPPT_UTILS_H

#include <cstdint>

/// \brief Finds the difference between two uint32_t values.
/// \param minuend The uint32_t value to be subtracted from.
/// \param subtrahend The uint32_t value being subtracted.
/// \returns The difference between two uint32_t values, respecting overflow.
inline uint32_t unsigned_subtraction(uint32_t minuend, uint32_t subtrahend)
{
  return minuend + (~subtrahend + 1);
}

#endif // SDLCPPT_UTILS_H
