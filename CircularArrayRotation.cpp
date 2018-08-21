/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 C++ program from a Hackerrank problem.

 It should return an array of integers representing the values at the specified indices.
 CircularArrayRotation has the following parameter(s):

    n: an array of integers to rotate
    k: an integer, the rotation count
    q: an array of integers, the queries
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    int n; std::cin >> n; // array size
    int k; std::cin >> k; //no of rotations
    int q; std::cin >> q;

    std::vector<int> vec;
    vec.reserve(n);
    std::copy_n(std::istream_iterator<int>(std::cin), 
                n, back_inserter(vec));
    k %= n;
    k = n-k;
    std::rotate(vec.begin(), vec.begin()+k,vec.end());

    while(q--)
    {
        int index; std::cin >> index;
        std::cout << vec[index]  << std::endl;
    }
    return 0;
}
