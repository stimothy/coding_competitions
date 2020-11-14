#include <iostream>

unsigned long long calcDim(unsigned int dim, unsigned int stoneDim);

/**
 * Calculates the number of flag stones needed to fit the square.
 */
int main() {
  unsigned int width;
  unsigned int height;
  unsigned int stoneWidthHeight;
  unsigned long long numStonesWide;
  unsigned long long numStonesHigh;

  std::cin >> width;
  std::cin >> height;
  std::cin >> stoneWidthHeight;

  numStonesWide = calcDim(width, stoneWidthHeight);
  numStonesHigh = calcDim(height, stoneWidthHeight);

  std::cout << numStonesHigh * numStonesWide;

  return 0;
}

/**
 * Calculates the number of stones to fit a specific dimension.
 * @param dim The dimension to fit the stones.
 * @param stoneDim The dimension of the stone.
 * @return The number of stones needed to fit in the dimension given rounded up.
 */
unsigned long long calcDim(unsigned int dim, unsigned int stoneDim) {
  if (dim % stoneDim != 0) {
    return ((dim / stoneDim) + 1);
  }
  else {
    return dim / stoneDim;
  }
}