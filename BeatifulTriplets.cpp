/* Author: Bruce Adams
# www.austingamestudios.com
# Hackerrank problem
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    int n; std::cin >> n; //the length of the sequence
    int d; std::cin >> d; //the beautiful difference
    std::vector<int> vec;
    vec.reserve(n);
    std::copy_n(std::istream_iterator<int>(std::cin),
            n, back_inserter(vec));

    int count = 0;
    for (int index = 0; index<=n-3; ++index)
        for (int j = index+1; j<=n-2; ++j)
            if(vec[j]-vec[index] == d)
                for (int h = j+1; h<n; ++h)
                    if(vec[h]-vec[j] == d)
                        ++count;
                    //std::cout << vec[index] <<" "<< vec[j]<<" "<< vec[h] <<std::endl;
    std::cout << count << std::endl;
    return 0;
}
