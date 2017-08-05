#include "stdafx.h"
using namespace std;

//http://blog.csdn.net/shinanhualiu/article/details/49004921
//http://blog.csdn.net/wutingyehe/article/details/46882181
//假如你把1 × 2 ×３× 4 ×……×N中每一个因数分解质因数，结果就像：
//1 × 2 × 3 ×(2 × 2) × 5 ×(2 × 3) × 7 ×(2 × 2 ×2) ×……
//10进制数结尾的每一个0都表示有一个因数10存在——任何进制都一样，对于一个M进制的数，让结尾多一个0就等价于乘以M。
//10可以分解为2 × 5——因此只有质数2和5相乘能产生0，别的任何两个质数相乘都不能产生0，而且2，5相乘只产生一个0。
//所以，分解后的整个因数式中有多少对(2, 5)，结果中就有多少个0，而分解的结果中，2的个数显然是多于5的，因此，有多少个5，就有多少个(2, 5)对。
//所以，讨论1000的阶乘结尾有几个0的问题，就被转换成了1到1000所有这些数的质因数分解式有多少个5的问题。
//5的个数可以用上面那个式子算出，所以1000的阶乘结尾有249个0。
//
//至于为什么用这个式子，可以见下例：
//求26的阶乘的尾部有多少个0.
//26！ = 1 × 2 ×３× 4 × 5 × 6 × 7 × 8 × 9 × 10 × 11 × 12 × 13× 14 × 15 × 16 × 17 × 18 × 19 × 20 × 21 × 22 ×2３× 24 × 25 × 26
//内有 26 / 5 + 26 / 25 = 6（个）5相乘
//因为25其实可以分解成2个5相乘，而26 / 5只计算了一个5，因此还要再加26 / 25.

class Solution {
public:
	// param n : description of n
	// return: description of return 
	long long trailingZeros(long long n) 
	{
		long long count = 0;
		while(n > 0)
		{
			count += n / 5;
			n /= 5;
		}
		return count;
	}
};


//int main()
//{
//	long long data = 11;
//	Solution s;
//	cout << s.trailingZeros(data);
//	return 0;
//}