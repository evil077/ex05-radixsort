#ifndef EX05_RADIXSORT_RADIXSORT_H
#define EX05_RADIXSORT_RADIXSORT_H

#include <cstdint>
#include <math.h>
#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                template<class Radix>
                void radixsort(Radix array[], size_t size) {
                    Radix buckets[10000][10];
                    size_t subBuckets[10];
                    Radix biggestVal = 0;
                    int64_t digits = 0;
                    for (uint64_t m = 0; m < size; m++) {
                        if (array[m] > biggestVal) {
                            biggestVal = array[m];
                        }
                    }
                    std::cout << "The largest value is: " << biggestVal << std::endl;
                    while (biggestVal != 0){
                        biggestVal /= 10;
                        digits++;
                        std::cout << "Number of digits: " << digits << std::endl;
                    }


                    for (uint64_t k = 1; k <= pow(10, digits); k *= 10 ){

                        for(uint64_t j = 0; j < size; j++){
                            size_t bin = (array[j] / k) % 10;
                            buckets[bin][subBuckets[bin]] = array[j];
                            subBuckets[bin]++;
                        }
                        uint64_t c = 0;
                        for(uint64_t b = 0; b < 10; b++){
                            for (uint64_t n = 0; n < subBuckets[b]; n++) {
                                array[c] = buckets[b][n];
                                c++;
                            }
                            subBuckets[b] = 0;
                        }
                    }
                }

            }}}}

#endif //EX05_RADIXSORT_RADIXSORT_H
