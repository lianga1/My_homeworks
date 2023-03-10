#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <stdexcept>

//以下是多个自定义的泛型函数，
//放在自定义的命名空间MySpace中。
//需要使用的这些函数的时候，
//可以在文件开始使用“using MySpace::find;”等语句
//或者直接在函数名前加“MySpace::”。
namespace MySpace{

//以下实现泛型函数swap，交换两个变量的值 
template <class X>
void swap(X & x, X & y){
	X tmp=x;
	x=y;
	y=tmp;
}

//以下实现泛型函数sort，用冒泡法排序 
template<class Ran>
void sort(Ran begin, Ran end)
{
//	std::cout << "sort...\n";
	for(Ran i=begin;i!=end;i++)
		for(Ran j=begin;j+1+(i-begin)!=end;j++)
			if(*j>*(j+1))
				swap(*j,*(j+1));
}

//以下实现泛型函数median，求中值 
template<class T>
T median(std::vector<T> vec)
{
//	std::cout << "median...\n";
	typedef typename std::vector<T>::size_type vec_sz;
	vec_sz size = vec.size();
	if(size == 0)
		throw std::domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

//以下实现泛型函数average，求均值
template<class T>
T average(std::vector<T> vec)
{
	typename std::vector<T>::iterator iter=vec.begin();
	T sum=0.0;
	int num=0;
	
	for(;iter!=vec.end();iter++)
	{
		sum+=*iter;
		num++;
	}
	return sum/num;

//	std::cout << "average...\n";
	

}

//以下实现泛型函数find，实现查找功能 
template <class In, class X> 
In find(In begin, In end, const X&x){
	In iter=begin;
	while(iter!=end)
	{
		if(*iter==x)
			return iter;
		iter++;
	}
	return end;

//	std::cout << "find...\n";
	

}

//以下实现泛型函数remove_copy，
//把所有与x不匹配的原素复制到输出迭代器dest表示的目标地址中。 
template <class In, class Out, class X> 
Out remove_copy(In begin, In end, Out dest,const X&x){
	In iter=begin;
	const Out itero=dest;
	while(iter!=end)
	{
		if((*iter)!=x)
		{
		
			*dest=*iter;
			dest++;
		}
		iter++;

	}
	return itero;

}

//以下实现泛型函数transform，
//在输入迭代器begin和end表示的序列的元素上调用函数f，
//结果保存到输出迭代器d表示的目标地址中。 
template <class In, class Out, class F> 
Out transform(In begin,In end, Out dest, F func){

	const Out itero=dest;
	In iter=begin;

	while(iter!=end)
	{
		*dest=func(*iter);
		iter++;
		dest++;
	}

	
//	std::cout << "transform...\n";

	return itero;
}
	
}
#endif
