#include "stdafx.h"
#include "map.h"
#include <stdlib.h>
using namespace std;

template <typename T1, typename T2>
int operator ==(MyIterator<T1, T2> left, MyIterator<T1, T2> rigth)
{
	if (left.cur == rigth.cur)
		return 1;
	else
		return 0;
}

template <typename T1, typename T2>
MyIterator<T1, T2>& operator +(MyIterator < T1, T2> left, int num)
{
	MyIterator<T1, T2> res = left;
	res.cur += num * sizeof(pair<T1, T2>*);
	return left;
}

template <typename T1, typename T2>
int operator !=(pair<T1, T2>* left, MyIterator<T1, T2> rigth)
{
	if (left == rigth.cur)
		return 0;
	else
		return 1;
}